#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <string>

using namespace sf;

const int MAX_WORLD_SCALE = 13;
const int MIN_WORLD_SCALE = 1;

Engine::Engine(RenderWindow &window) {
	Engine::window = &window;

	font_pixel.loadFromFile("fonts/pixel.ttf");
	//Engine::decoration_manager = DecorationManager(sprite_manager);
}

void Engine::start() {
	Tile sand(this, sprite_manager.SPRITE_GROUND_SAND, Vector2f(900/2, 800/2), decoration_manager.DECORATION_DEAD_BUSH_1, 2, true);

	Text text("DT: 0", font_pixel, 20);

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
					break;
				case Event::MouseButtonReleased:
					if (event.mouseButton.button == Mouse::Left) {
						is_left_mouse_hold = false;

						if (time_left_mouse_hold <= 90) {

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

			if (time_left_mouse_hold > 90) {
				//world_scale -= 0.05f * delta_time;
				cameraMoveByMouse();
			}
		}

		window->clear(Color(250, 220, 100, 0)); // Очищаем заливкой все окно определенным цветом rgba
 
		sand.setScale(Vector2f(world_scale, world_scale));
		sand.update();
		sand.draw();

		String string = "MP:" + std::to_string(old_camera_x) + "/" + std::to_string(old_camera_y);
		text.setString(string);
		window->draw(text);
	
		update(); // Обновляем состояние
		draw(); // Рисуем объекты и прочее

		window->display(); // Рисуем окно

		Engine::delta_time = clock_delta_time.getElapsedTime().asMicroseconds(); // Замеряем время
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

void Engine::cameraMoveTo(int x, int y) {
	camera_x = x;
	camera_y = y;
}

void Engine::cameraMoveByMouse() {
	camera_x = old_camera_x + mouse_click_x - mouse_x;
	camera_y = old_camera_y + mouse_click_y - mouse_y;
}