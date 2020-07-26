#include <iostream>
#include <SFML/Graphics.hpp>
#include "loadTextures.h"

using namespace sf;

Texture TEXTURE_TILES1;
Texture TEXTURE_TANKS1;

//T34
Sprite SPRITE_T34_LEFT;
//Sprite SPRITE_T34_RIGHT;
//Sprite SPRITE_T34_UP;
//Sprite SPRITE_T34_DOWN;

//Ground
Sprite SPRITE_GROUND_SAND;

void loadTextures() {
	TEXTURE_TANKS1.loadFromFile("tanks1.png");
	TEXTURE_TILES1.loadFromFile("tiles1.png");
}

void setSpriteCFG(Sprite& sprite, Texture& texture, IntRect rect) {
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
}

void loadSprites() {
//Tanks
	//T34
	setSpriteCFG(SPRITE_T34_LEFT, TEXTURE_TANKS1, IntRect(1,1,28,14));

//Tiles
	//Ground
	setSpriteCFG(SPRITE_GROUND_SAND, TEXTURE_TILES1, IntRect(27, 3, 20, 16));
};

void loadTexturesAndSprites() {
	loadTextures();
	loadSprites();
}

