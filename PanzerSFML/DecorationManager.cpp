#include "DecorationManager.h"
#include "Engine.h"
#include "SpriteManager.h"

DecorationManager::DecorationManager() {
	DecorationManager::engine = engine;
}

DecorationManager::DecorationManager(Engine *engine) {
	DecorationManager::engine = engine;
	initDecorations();
}

void DecorationManager::initDecorations() {
	SpriteManager* sprite_manager = &engine->getSpriteManager();
	DECORATION_DEAD_BUSH_1 = Decoration(engine, sprite_manager->SPRITE_DECORATION_DEAD_BUSH_1, Vector2f(-4,6));
	DECORATION_VOID = Decoration(engine, sprite_manager->SPRITE_VOID, Vector2f(0, 0));

	DECORATION_ROAD_FENCE_1 = Decoration(engine, sprite_manager->SPRITE_DECORATION_ROAD_FENCE_1, Vector2f(0,2));
}