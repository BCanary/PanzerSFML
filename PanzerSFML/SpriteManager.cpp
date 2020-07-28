#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"

using namespace sf;

SpriteManager::SpriteManager() {
	loadTextures();
	loadSprites();
}

void SpriteManager::setSpriteCFG(Sprite& sprite, Texture& texture, IntRect rect) {
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
	//sprite.setOrigin(rect.width / 2, rect.height / 2);
}

void SpriteManager::loadTextures() {
	TEXTURE_TANKS1.loadFromFile("textures/tanks1.png");
	TEXTURE_TILES1.loadFromFile("textures/tiles1.png");
}

void SpriteManager::loadSprites() {
	setSpriteCFG(SPRITE_VOID, TEXTURE_TILES1, IntRect(0, 0, 0, 0));

	//Tanks
		//T34
	setSpriteCFG(SPRITE_T34_LEFT, TEXTURE_TANKS1, IntRect(1, 1, 28, 14));

	//Tiles
	setSpriteCFG(SPRITE_GROUND_SAND, TEXTURE_TILES1, IntRect(27, 3, 20, 16));
	setSpriteCFG(SPRITE_GROUND_GRAVEL, TEXTURE_TILES1, IntRect(129, 6, 20, 16));

	//Decorations
	setSpriteCFG(SPRITE_DECORATION_DEAD_BUSH_1, TEXTURE_TILES1, IntRect(28, 84, 15, 14));
	setSpriteCFG(SPRITE_DECORATION_ROAD_FENCE_1, TEXTURE_TILES1, IntRect(17, 125, 20, 10));
};

