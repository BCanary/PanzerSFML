#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <string>

using namespace sf;

const int MAX_WORLD_SCALE = 13;
const int MIN_WORLD_SCALE = 1;

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
			switch (event.type) {

				case Event::Closed:  // ���� ����� ����� ��������
					window->close(); // ��������� ����
					break;

				case Event::MouseWheelMoved:
					if (event.mouseWheel.delta == 1 && world_scale < MAX_WORLD_SCALE) {
						world_scale += 0.1f * deltaTime;
					}
					else if (event.mouseWheel.delta == -1 && world_scale > MIN_WORLD_SCALE) {
						world_scale -= 0.1f * deltaTime;
					}
					if (world_scale < MIN_WORLD_SCALE) world_scale = MIN_WORLD_SCALE;
					else if (world_scale > MAX_WORLD_SCALE) world_scale = MAX_WORLD_SCALE;
			}
		}

		window->clear(Color(250, 220, 100, 0)); // ������� �������� ��� ���� ������������ ������ rgba
 
		sand.setScale(Vector2f(world_scale, world_scale));
		sand.update();
		sand.draw();

		String string = "WS:" + std::to_string(Engine::world_scale);
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