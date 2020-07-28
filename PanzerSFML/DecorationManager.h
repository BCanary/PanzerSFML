#pragma once
#include <SFML/Graphics.hpp>
//#include "SpriteManager.h"
#include "Decoration.h"

class Engine;
class SpriteManager;

using namespace sf;

class DecorationManager {
public:
	DecorationManager();
	DecorationManager(Engine* engine);

	Decoration DECORATION_DEAD_BUSH_1;
	Decoration DECORATION_VOID;

	Decoration DECORATION_ROAD_FENCE_1;
private:
	Engine *engine;
	void initDecorations();
};