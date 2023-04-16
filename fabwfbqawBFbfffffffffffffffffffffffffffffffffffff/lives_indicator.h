#pragma once
#include "settings.h"

class LivesIndicator {
public:
	LivesIndicator(sf::Vector2f pos);
	void update();
	void draw(sf::RenderWindow& window);
private:
	sf::Texture texture;
	sf::Sprite sprite;
};
//=====END CLASS=====

LivesIndicator::LivesIndicator(sf::Vector2f pos) {
	sprite.setScale(0.05f, 0.05f);
	texture.loadFromFile(life_icon_filename);
	sprite.setTexture(texture);
	sprite.setPosition(pos);
}

void LivesIndicator::update() {}

void LivesIndicator::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
