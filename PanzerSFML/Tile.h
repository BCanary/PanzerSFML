#pragma once
#include "Object.h"
#include "Decoration.h"

//Класс Tile, наследуется от объекта, используется как клетка земли
class Tile : public Object {
public:
	Tile(Engine* engine, Sprite sprite, Vector2f position, int cost, bool is_passable);
	Tile(Engine* engine, Sprite sprite, Vector2f position, Decoration decoration, int cost, bool is_passable);
	int getCost();
	bool isPassable();
private:
	int cost; //Цена прохождения по клетке для алгоритма A*
	bool is_passable; // Проходима ли клетка
};