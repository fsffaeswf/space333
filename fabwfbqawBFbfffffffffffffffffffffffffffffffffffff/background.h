#pragma once
#include "settings.h"

class Background {
public:
	Background();
	void draw(sf::RenderWindow& window);
private:
	sf::Texture texture;
	sf::Sprite sprite;
};
//=====END CLASS=====

Background::Background() {
	sprite.setScale(1.2f, 1.2f);
	texture.loadFromFile(background_filename);
	sprite.setTexture(texture);
	sprite.setPosition(0.f, 0.f);
}

void Background::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}