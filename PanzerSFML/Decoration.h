#pragma once
#include <SFML/Graphics.hpp>

class Engine;
class Object;

using namespace sf;

// Декорации нужны, для отрисовки их, поверх тайлов.
class Decoration {
public:
	Decoration(Engine* engine, Sprite sprite, Vector2f margin);
	Decoration(Engine* engine);
	Decoration();
	void updateDecoration(Object *parent_tile);
	void drawDecoration(RenderWindow *window);
private:
	Engine* engine;

	Sprite sprite;

	Vector2f margin;
};