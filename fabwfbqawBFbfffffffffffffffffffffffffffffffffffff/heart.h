#pragma once
#include "settings.h"

class Heart {
private:
	sf::Sprite sprite;
	sf::Texture texture;

public:
	
	Heart() {
		sprite.setScale(0.2f, 0.2f);
		texture.loadFromFile(heart_file_name);
		sprite.setTexture(texture);	
	}
};
