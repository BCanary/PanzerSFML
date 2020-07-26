#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

// Декорации нужны, для отрисовки их, поверх тайлов.
class Decoration {
public:
	Decoration(Sprite sprite, Vector2f margin);
	Decoration();
	void updateDecoration(Vector2f parent_position, Vector2f parent_origin, Vector2f scale);
	void drawDecoration(RenderWindow *window);
private:
	Sprite sprite;

	Vector2f margin;
};