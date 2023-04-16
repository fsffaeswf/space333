#pragma once
#include "settings.h"

class Meteor{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f speed;
	int damage;
public:
	enum MeteorSize{Small, Average,Big};
	Meteor(std::string fileName, MeteorSize size, sf::Vector2f pos, sf::Vector2f fspeed) {
		texture.loadFromFile(fileName);
		if (size == Big) {
			sprite.setScale(0.5f, 0.5f);
			damage = 30;
		}
		else if (size == Average) {
			sprite.setScale(0.25f, 0.25f);
			damage = 15;
		}
		else if (size == Small) {
			sprite.setScale(0.125f, 0.125f);
			damage = 5;
		}
		sprite.setPosition(pos);
		sprite.setTexture(texture);
		speed = fspeed;
	}
	void update() {
		sprite.move(speed);
		sf::Vector2f pos = sprite.getPosition();
		if (pos.x < left_border || pos.x>right_border || pos.y<top_border || pos.y>bottom_border) {
			setRandomPosition();
		}
	}

	void setRandomPosition(){
		float x = rand() % 301 - 300.f;
		int choice = rand() % 10000;
		if (choice < 5000)x += 1500.f;


		float y = rand() % 301 - 300.f;
		choice = rand() % 10000;
		if (choice < 5000) y += 1500.f;

		float speedx = rand() % 11 - 5.f;
		float speedy = rand() % 11 - 5.f;
		sprite.setPosition(x, y);
	}
	sf:: FloatRect getHitbox() { return sprite.getGlobalBounds(); }
	sf::Sprite getSprite() { return sprite; }
	int getDamage() { return damage; }

	sf::Vector2f get_pos();
	
};
sf::Vector2f Meteor::get_pos() { return sprite.getPosition(); }