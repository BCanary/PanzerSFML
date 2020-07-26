#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"

using namespace sf;

Engine::Engine(RenderWindow &window) {
	Engine::window = &window;
}

void Engine::start() {
	Tile sand(*window, sprite_manager.SPRITE_GROUND_SAND, Vector2f(1, 1), 2, true);
	while (window->isOpen()) { // ���� ���� �������, �������� �������� ���� �������� � false

		Event event; // ������� ������ �����, �����, ����� ��������� � pollEvent, � ���� ����� ������������ ������
		while (window->pollEvent(event)) { // ���� ����������� �� ���� ������� ���� �� ������ ������ ( ������� � �.� )

			if (event.type == Event::Closed) { // ���� ����� ����� ��������
				window->close(); // ��������� ����
			}
		}

		window->clear(Color(250, 220, 100, 0)); // ������� �������� ��� ���� ������������ ������ rgba

		sand.draw();
		sand.setScale(Vector2f(world_scale, world_scale));

		world_scale += 0.001f;
		update(); // ��������� ���������
		draw(); // ������ ������� � ������

		window->display(); // ������ ����
	}
}

void Engine::draw() {

}

void Engine::update() {

}