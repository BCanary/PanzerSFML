#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"
#include "Decoration.h"

using namespace sf;

class DecorationManager {
public:
	DecorationManager(SpriteManager &sprite_manager);

	Decoration DECORATION_DEAD_BUSH_1;
	Decoration DECORATION_VOID;
private:
	SpriteManager* sprite_manager;
	void initDecorations();
};