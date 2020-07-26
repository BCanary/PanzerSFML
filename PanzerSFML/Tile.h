#pragma once
#include "Object.h"
#include "Decoration.h"

//����� Tile, ����������� �� �������, ������������ ��� ������ �����
class Tile : public Object {
public:
	Tile(Engine* engine, Sprite sprite, Vector2f position, int cost, bool is_passable);
	Tile(Engine* engine, Sprite sprite, Vector2f position, Decoration decoration, int cost, bool is_passable);
	int getCost();
	bool isPassable();
private:
	int cost; //���� ����������� �� ������ ��� ��������� A*
	bool is_passable; // ��������� �� ������
};