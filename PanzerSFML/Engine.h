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
	float deltaTime = 0; // Время потраченное на логику и отрисовку

	float world_scale = 5; // Приближение всех объектов
	float gui_scale = 1; // Приближение интерфейса

	void update();
	void draw();

	RenderWindow *window;
	
	SpriteManager sprite_manager;
	DecorationManager decoration_manager = DecorationManager(sprite_manager);
};