#pragma once
#include "Object.h"

class Tile : public Object {
public:
	Tile(RenderWindow &window, Sprite& sprite, Vector2f position, int cost, bool is_passable);
	int getCost();
	bool isPassable();
private:
	int cost;
	bool is_passable;
};