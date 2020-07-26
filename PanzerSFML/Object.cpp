#include <SFML/Graphics.hpp>
#include "Object.h"

Object::Object(Sprite& sprite, Vector2f position) {
	Object::sprite = &sprite;
	Object::position = position;
}

void Object::setRenderWindow(RenderWindow &window) {
	Object::window = &window;
}

void Object::draw() {
	//������� � ������ ������
	Object::sprite->move(Object::position);
	Object::window->draw(*Object::sprite);
}