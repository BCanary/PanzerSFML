#include <SFML/Graphics.hpp>
#include "Object.h"

Object::Object(RenderWindow &window, Sprite& sprite, Vector2f position) {
	Object::window = &window;
	Object::sprite = &sprite;
	Object::position = position;
	Object::scale = Vector2f(0, 0);
}

/*
Отказ от данной реализации
void Object::setRenderWindow(RenderWindow &window) {
	Object::window = &window;
}
*/

//Устанавливаем позицию объекту 
void Object::setPosition(Vector2f position) {
	Object::position = position;
}

//Устанавливаем приближение объекта
void Object::setScale(Vector2f scale) {
	Object::scale = scale;
}

// Получить позицию объекта
Vector2f Object::getPosition() {
	return Object::position;
}

//Двигаем и рисуем объект
void Object::draw() {
	Object::sprite->setPosition(Object::position);
	Object::sprite->setScale(Object::scale);
	Object::window->draw(*Object::sprite);
}
