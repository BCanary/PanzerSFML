#include <SFML/Graphics.hpp>
#include "Object.h"

Object::Object(Engine *engine, Sprite sprite, Vector2f position) {
	Object::engine = engine;
	Object::window = engine->getRenderWindow();

	Object::sprite = sprite;

	Object::position = position;

	Object::scale = Vector2f(0, 0);

	Object::decoration = engine->getDecorationManager().DECORATION_VOID;
}

Object::Object(Engine *engine, Sprite sprite, Vector2f position, Decoration decoration) {
	Object::have_decoration = true;
	Object::decoration = decoration;

	Object::engine = engine;
	Object::window = engine->getRenderWindow();

	Object::sprite = sprite;

	Object::position = position;

	Object::scale = Vector2f(0, 0);
};
/*
����� �� ������ ����������
void Object::setRenderWindow(RenderWindow &window) {
	Object::window = &window;
}
*/

//������������� ������� ������� 
void Object::setPosition(Vector2f position) {
	Object::position = position;
}

//������������� ����������� �������
void Object::setScale(Vector2f scale) {
	Object::scale = scale;
}

// �������� ������� �������
Vector2f Object::getPosition() {
	return Object::position;
}

// ������� ������ �� ���������
void Object::move(float deltaTime, float moveX, float moveY) {
	Object::position.x += moveX * deltaTime;
	Object::position.y += moveY * deltaTime;
}

//������� � ���������� 
void Object::update() {
	Object::sprite.setPosition(Object::position);
	Object::sprite.setScale(Object::scale);
	if (Object::have_decoration) {
		Object::decoration.updateDecoration(Object::position, Object::sprite.getOrigin(), Object::scale);
	}
}

//������ ������
void Object::draw() {
	Object::window->draw(Object::sprite);
	if (Object::have_decoration) {
		Object::decoration.drawDecoration(Object::window);
	}
}
