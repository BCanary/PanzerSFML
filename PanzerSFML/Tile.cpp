#include "Tile.h"

//Конструктор
Tile::Tile(Engine* engine, Sprite sprite, Vector2f position, int cost, bool is_passable):Object(engine, sprite, position) {
	Tile::cost = cost;
	Tile::is_passable = is_passable;
}

Tile::Tile(Engine* engine, Sprite sprite, Vector2f position, Decoration decoration, int cost, bool is_passable)
	: Object(engine, sprite, position, decoration)
{
	Tile::cost = cost;
	Tile::is_passable = is_passable;
};

//Получаем стоимость прохода
int Tile::getCost() {
	return Tile::cost;
}

//Проходима ли клетка
bool Tile::isPassable() {
	return Tile::is_passable;
}