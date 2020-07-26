#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "DecorationManager.h"

using namespace sf;

class Engine {
public:
	Engine(RenderWindow &window);

	void start();

	RenderWindow* getRenderWindow();
	SpriteManager& getSpriteManager();
	DecorationManager& getDecorationManager();
private:
	float deltaTime = 0; // ����� ����������� �� ������ � ���������

	float world_scale = 5; // ����������� ���� ��������
	float gui_scale = 1; // ����������� ����������

	void update();
	void draw();

	RenderWindow *window;
	
	SpriteManager sprite_manager;
	DecorationManager decoration_manager = DecorationManager(sprite_manager);
};