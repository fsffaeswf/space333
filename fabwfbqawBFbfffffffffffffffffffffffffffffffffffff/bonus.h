#pragma once
#include "settings.h"

class Player;

class Bonus {
public:
	enum BonusType { MedKit, Speed_boost, KaBoom, Max_Bonus_type };
	Bonus(sf::Vector2f meteorPos, size_t bonusType);
	void draw(sf::RenderWindow& window);
	void update();
	void act(Player& player);
	bool is_to_del();
	auto getHitbox();
	void set_del();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	BonusType type;
	sf::Clock timer;
	bool del = false;
};

Bonus::Bonus(sf::Vector2f meteorPos, size_t bonusType) {
	type = (BonusType)bonusType;
	sprite.setScale(0.125f, 0.125f);
	switch (type) {
	case MedKit:
		texture.loadFromFile(MedickKit_filename);
		break;
	case Speed_boost:
		texture.loadFromFile(SpeedBoost_filename);
		break;
	case KaBoom:
		texture.loadFromFile(Kaboom_filename);
		break;
	}
	sprite.setTexture(texture);
	sprite.setPosition(meteorPos);
	timer.restart();
}
void Bonus::draw(sf::RenderWindow& window) { window.draw(sprite); }






void Bonus::update()
{
	int now = timer.getElapsedTime().asMilliseconds();
	if (now > 5000) {
		del = true;
	}
}

void Bonus::act(Player& player) {
	switch (type) {
	case MedKit:
		player.add_hp(50);
		break;
	case Speed_boost:
		player.add_speed();
		break;
	case KaBoom:
		break;
	}

}

auto Bonus::getHitbox() { return sprite.getGlobalBounds(); }

bool Bonus::is_to_del() { return del; }

void Bonus::set_del() { del = true; }