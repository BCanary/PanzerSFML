#include "Decoration.h"

Decoration::Decoration() {
	Decoration::sprite = Sprite();
	Decoration::margin = Vector2f(0, 0);
}

Decoration::Decoration(Sprite sprite, Vector2f margin) {
	Decoration::sprite = sprite;
	Decoration::margin = margin;
}

// Обновляет объект
void Decoration::updateDecoration(Vector2f parent_position, Vector2f parent_origin, Vector2f scale) {
	Decoration::sprite.setOrigin(parent_origin.x + margin.x, parent_origin.y + margin.y); // Двигаем начальную точку, относительно центро объекта
	Decoration::sprite.setPosition(parent_position); // Это нужно, для того, чтобы они равномерно увеличивались
	Decoration::sprite.setScale(scale); // Увеличиваем
}

// Рисуем декорацию
void Decoration::drawDecoration(RenderWindow *window) {
	window->draw(Decoration::sprite);
}