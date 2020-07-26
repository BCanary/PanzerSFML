#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <string>

using namespace sf;


Engine::Engine(RenderWindow &window) {
	Engine::window = &window;
	//Engine::decoration_manager = DecorationManager(sprite_manager);
}

void Engine::start() {
	Tile sand(this, sprite_manager.SPRITE_GROUND_SAND, Vector2f(900/2, 800/2), decoration_manager.DECORATION_DEAD_BUSH_1, 2, true);
	Clock clock;

	Font font;
	font.loadFromFile("fonts/pixel.ttf");
	Text text("DT: 0", font, 20);
	while (window->isOpen()) { // ���� ���� �������, �������� �������� ���� �������� � false
		clock.restart(); // ������������� ����

		Event event; // ������� ������ �����, �����, ����� ��������� � pollEvent, � ���� ����� ������������ ������
		while (window->pollEvent(event)) { // ���� ����������� �� ���� ������� ���� �� ������ ������ ( ������� � �.� )

			if (event.type == Event::Closed) { // ���� ����� ����� ��������
				window->close(); // ��������� ����
			}
		}

		window->clear(Color(250, 220, 100, 0)); // ������� �������� ��� ���� ������������ ������ rgba

		world_scale += 0.001f * deltaTime;
		sand.setScale(Vector2f(world_scale, world_scale));
		sand.update();
		sand.draw();

		String string = "DT:" + std::to_string(Engine::deltaTime);
		text.setString(string);
		window->draw(text);
	
		update(); // ��������� ���������
		draw(); // ������ ������� � ������

		window->display(); // ������ ����

		Engine::deltaTime = clock.getElapsedTime().asMicroseconds() / 900; // �������� �����
	}
}

//��������� ������� ����� ���/� ����������
void Engine::draw() {

}

//���������� ����
void Engine::update() {

}

//�������� ����
RenderWindow* Engine::getRenderWindow() {
	return Engine::window;
}

SpriteManager& Engine::getSpriteManager() {
	return Engine::sprite_manager;
}

DecorationManager& Engine::getDecorationManager() {
	return Engine::decoration_manager;
}