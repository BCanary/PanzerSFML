#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"
class Decoration;

using namespace sf;

// Класс любого игрового объекта
class Object {
public:
	Object(Engine *engine, Sprite sprite, Vector2f position);
	Object(Engine *engine, Sprite sprite, Vector2f position, Decoration decoration);

	//void setRenderWindow(RenderWindow &window);
	void setPosition(Vector2f position);
	void setScale(Vector2f scale);

	Vector2f getPosition();

	void move(float deltaTime, float moveX, float moveY);
	void update();
	void draw();
private:
	Vector2f position;
	Vector2f scale;


	Sprite sprite;

	bool have_decoration = false;
	Decoration decoration;

	RenderWindow* window; //Переход на окно движка
	Engine* engine;
};