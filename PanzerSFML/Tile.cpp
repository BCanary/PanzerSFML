#include "Tile.h"

Tile::Tile(RenderWindow& window, Sprite& sprite, Vector2f position, int cost, bool is_passable):Object(window, sprite, position) {
	Tile::cost = cost;
	Tile::is_passable = is_passable;
}

int Tile::getCost() {
	return Tile::cost;
}

bool Tile::isPassable() {
	return Tile::is_passable;
}