#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

// Класс любого игрового объекта
class Object {
public:
	Object(RenderWindow &window, Sprite &sprite, Vector2f position);

	//void setRenderWindow(RenderWindow &window);
	void setPosition(Vector2f position);
	void setScale(Vector2f scale);

	Vector2f getPosition();

	void draw();
private:
	Vector2f position;
	Vector2f scale;

	Sprite* sprite;

	RenderWindow* window;
};