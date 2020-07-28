#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Map.h"
#include <string>


using namespace sf;

const int MAX_WORLD_SCALE = 13;
const int MIN_WORLD_SCALE = 1;

const int MIN_MOUSE_TIME_TO_CLICK = 180;

const int WORLD_SCALE = 5;

Engine::Engine(RenderWindow &window) {

	Engine::window = &window;
	//Engine::view = &view;

	//Engine::window->setView(*Engine::view);

	font_pixel.loadFromFile("fonts/pixel.ttf");
	//Engine::decoration_manager = DecorationManager(sprite_manager);
}

void Engine::start() {

	Text text("DT: 0", font_pixel, 20);

	XMLDocument doc;
	doc.LoadFile("maps/test_map.xml");
	Map test_map(doc, this);

	Tile tile1(this, sprite_manager.SPRITE_GROUND_GRAVEL, Vector2f(900/2,800/2), decoration_manager.DECORATION_ROAD_FENCE_1,2,true);
	Tile tile2(this, sprite_manager.SPRITE_GROUND_GRAVEL, Vector2f(900 / 2 - 20, 800 / 2), decoration_manager.DECORATION_ROAD_FENCE_1, 2, true);
	//Tile tile3(this, sprite_manager.SPRITE_GROUND_SAND, Vector2f(900 / 2-8, 800 / 2+11), 2, true);
	//Tile tile4(this, sprite_manager.SPRITE_GROUND_SAND, Vector2f(900 / 2 - 27, 800 / 2+11), 2, true);

	while (window->isOpen()) { // Пока окно открыто, очевидно закрытие окна приведет к false
		clock_delta_time.restart(); // Перезапускаем часы

		Event event; // Создаем пустой евент, далее, через указатель в pollEvent, в него будут записываться данный
		while (window->pollEvent(event)) { // Цикл прохождения по всем эвентам окна на данный момент ( нажатия и т.п )
			switch (event.type) {

				case Event::Closed:  // Если евент равен закрытию
					window->close(); // Закрываем окно
					break;

				case Event::MouseWheelScrolled: // Приближаем мир
					if (event.mouseWheelScroll.delta > 0 && world_scale < MAX_WORLD_SCALE) {
						world_scale += 0.05f * delta_time;
					}
					else if (event.mouseWheelScroll.delta < 0 && world_scale > MIN_WORLD_SCALE) {
						world_scale -= 0.05f * delta_time;
					}
					if (world_scale < MIN_WORLD_SCALE) world_scale = MIN_WORLD_SCALE;
					else if (world_scale > MAX_WORLD_SCALE) world_scale = MAX_WORLD_SCALE;
					//view->zoom(world_scale);
					break;
				case Event::MouseButtonPressed:
					if (event.mouseButton.button == Mouse::Left) {
						is_left_mouse_hold = true;
						clock_left_mouse_hold.restart(); // С этого момента, записываем, сколько мы держали мышь

						// Cохраняем кординаты клика
						mouse_click_x = mouse_x;
						mouse_click_y = mouse_y;

						//Сохраняем старые кординаты камеры
						old_camera_x = camera_x;
						old_camera_y = camera_y;
					}
					if (event.mouseButton.button == Mouse::Right) {
						world_scale -= 1;
					}
					break;
				case Event::MouseButtonReleased:
					if (event.mouseButton.button == Mouse::Left) {
						is_left_mouse_hold = false;

						if (time_left_mouse_hold <= MIN_MOUSE_TIME_TO_CLICK) {
							world_scale += 1;
							//camera_x = tile1.getPosition().x;
							//camera_y = tile1.getPosition().y;
						}

						time_left_mouse_hold = 0; // Обнуляем удержание мыши
					}
					break;
			}
		}

		mouse_x = Mouse::getPosition(*window).x;
		mouse_y = Mouse::getPosition(*window).y;

		if (is_left_mouse_hold) {
			time_left_mouse_hold = clock_left_mouse_hold.getElapsedTime().asMilliseconds();

			if (time_left_mouse_hold > MIN_MOUSE_TIME_TO_CLICK*0.8) {
				//world_scale -= 0.05f * delta_time;
				cameraMoveByMouse();
			}
		}

		window->clear(Color(250, 220, 100, 0)); // Очищаем заливкой все окно определенным цветом rgba
 
		//sand.setScale(Vector2f(world_scale, world_scale));

		tile1.update();
		tile1.draw();
		tile2.update();
		tile2.draw();
		//tile3.update();
		//tile3.draw();
		//tile4.update();
		//tile4.draw();

		string map_name = test_map.getMapName();
		text.setString(String::fromUtf8(map_name.begin(), map_name.end())
			+ L"\nworld_scale:" + to_string(world_scale)
			+ L"\npos:" + to_string(tile1.getPosition().x) + "/" + to_string(tile1.getPosition().y)
			+ L"\npos-s:" + to_string(tile1.getPosition().x*world_scale) + "/" + to_string(tile1.getPosition().y*world_scale)
			+ L"\ncamera:" + to_string(camera_x) + "/" + to_string(camera_y));
		window->draw(text);
	
		update(); // Обновляем состояние
		draw(); // Рисуем объекты и прочее

		window->display(); // Рисуем окно

		Engine::delta_time = static_cast<float>(clock_delta_time.getElapsedTime().asMicroseconds()); // Замеряем время
		Engine::delta_time /= 900.0f;

	}
}

//Отрисовка текущей карты или/и интерфейса
void Engine::draw() {

}

//Обновление окна
void Engine::update() {

}

//Получаем окно
RenderWindow* Engine::getRenderWindow() {
	return Engine::window;
}

SpriteManager& Engine::getSpriteManager() {
	return Engine::sprite_manager;
}

DecorationManager& Engine::getDecorationManager() {
	return Engine::decoration_manager;
}

Vector2f Engine::getWorldScale() {
	return Vector2f(world_scale, world_scale);
}

void Engine::cameraMoveTo(int x, int y) {
	camera_x = x;
	camera_y = y;
}

void Engine::cameraMoveByMouse() {
	camera_x = old_camera_x + mouse_click_x - mouse_x;
	camera_y = old_camera_y + mouse_click_y - mouse_y;
}