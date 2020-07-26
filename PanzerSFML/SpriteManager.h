#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class SpriteManager {
public:
	Texture TEXTURE_TILES1;
	Texture TEXTURE_TANKS1;

	//T34
	Sprite SPRITE_T34_LEFT;
	Sprite SPRITE_T34_RIGHT;
	Sprite SPRITE_T34_UP;
	Sprite SPRITE_T34_DOWN;

	//Ground
	Sprite SPRITE_GROUND_SAND;

	SpriteManager();
private:
	void loadTextures();
	void loadSprites();
	void setSpriteCFG(Sprite& sprite, Texture& texture, IntRect rect);
};