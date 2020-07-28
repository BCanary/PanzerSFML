#include "Decoration.h"
#include "Engine.h"
#include "Object.h"

Engine void_engine;

Decoration::Decoration() {
	Decoration::engine = &void_engine;
	Decoration::sprite = Sprite();
	Decoration::margin = Vector2f(0, 0);
}

Decoration::Decoration(Engine* engine) {
	Decoration::engine = engine;
	Decoration::sprite = Sprite();
	Decoration::margin = Vector2f(0, 0);
}

Decoration::Decoration(Engine* engine, Sprite sprite, Vector2f margin) {
	Decoration::engine = engine;
	Decoration::sprite = sprite;
	Decoration::margin = margin;
}

// Обновляет объект
void Decoration::updateDecoration(Object *parent_tile) {
	//Decoration::sprite.setOrigin(parent_tile->getPosition().x + margin.x, parent_tile->getPosition().y + margin.y); // Двигаем начальную точку, относительно центро объекта
	Decoration::sprite.setPosition(parent_tile->getPosition().x - engine->camera_x, parent_tile->getPosition().y - engine->camera_y); // Это нужно, для того, чтобы они равномерно увеличивались
	Decoration::sprite.setScale(engine->getWorldScale()); // Увеличиваем
}

// Рисуем декорацию
void Decoration::drawDecoration(RenderWindow *window) {
	window->draw(Decoration::sprite);
}