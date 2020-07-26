#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"

using namespace sf;

Engine::Engine(RenderWindow &window) {
	Engine::window = &window;
}

void Engine::start() {
	Tile sand(*window, sprite_manager.SPRITE_GROUND_SAND, Vector2f(1, 1), 2, true);
	while (window->isOpen()) { // Пока окно открыто, очевидно закрытие окна приведет к false

		Event event; // Создаем пустой евент, далее, через указатель в pollEvent, в него будут записываться данный
		while (window->pollEvent(event)) { // Цикл прохождения по всем эвентам окна на данный момент ( нажатия и т.п )

			if (event.type == Event::Closed) { // Если евент равен закрытию
				window->close(); // Закрываем окно
			}
		}

		window->clear(Color(250, 220, 100, 0)); // Очищаем заливкой все окно определенным цветом rgba

		sand.draw();
		sand.setScale(Vector2f(world_scale, world_scale));

		world_scale += 0.001f;
		update(); // Обнавляем состояние
		draw(); // Рисуем объекты и прочее

		window->display(); // Рисуем окно
	}
}

void Engine::draw() {

}

void Engine::update() {

}