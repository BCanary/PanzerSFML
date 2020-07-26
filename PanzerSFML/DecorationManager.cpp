#include "DecorationManager.h"

DecorationManager::DecorationManager(SpriteManager &sprite_manager) {
	DecorationManager::sprite_manager = &sprite_manager;
	initDecorations();
}

void DecorationManager::initDecorations() {
	DECORATION_DEAD_BUSH_1 = Decoration(sprite_manager->SPRITE_DECORATION_DEAD_BUSH_1, Vector2f(-4,6));
	DECORATION_VOID = Decoration(sprite_manager->SPRITE_VOID, Vector2f(0, 0));
}