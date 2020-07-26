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
}

void SpriteManager::loadTextures() {
	TEXTURE_TANKS1.loadFromFile("tanks1.png");
	TEXTURE_TILES1.loadFromFile("tiles1.png");
}

void SpriteManager::loadSprites() {
	//Tanks
		//T34
	setSpriteCFG(SPRITE_T34_LEFT, TEXTURE_TANKS1, IntRect(1, 1, 28, 14));

	//Tiles
		//Ground
	setSpriteCFG(SPRITE_GROUND_SAND, TEXTURE_TILES1, IntRect(27, 3, 20, 16));
};

