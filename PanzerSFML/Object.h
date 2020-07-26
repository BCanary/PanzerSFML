#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

// Класс любого игрового объекта
class Object {
public:
	Object(Sprite &sprite, Vector2f position);

	void setRenderWindow(RenderWindow &window);

	void draw();
private:
	Vector2f position;

	Sprite* sprite;

	RenderWindow* window;
};