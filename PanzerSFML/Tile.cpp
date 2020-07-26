#include "Tile.h"

//�����������
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

//�������� ��������� �������
int Tile::getCost() {
	return Tile::cost;
}

//��������� �� ������
bool Tile::isPassable() {
	return Tile::is_passable;
}