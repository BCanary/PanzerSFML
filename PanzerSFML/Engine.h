#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"

using namespace sf;

class Engine {
public:
	Engine(RenderWindow &window);
	void start();
private:
	float deltaTime = 0;

	float world_scale = 5;

	void update();
	void draw();

	RenderWindow *window;
	
	SpriteManager sprite_manager;
};