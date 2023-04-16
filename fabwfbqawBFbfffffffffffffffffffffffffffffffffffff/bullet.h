#pragma once
#include "settings.h"

class Bullet {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
	bool m_hit = false;
public:
	Bullet(sf::Vector2f playerPos,int playerAngle) {
		sprite.setScale(0.7f, 0.7f);
		texture.loadFromFile(bullet_file_name);
		sprite.setTexture(texture);
		sprite.setPosition(playerPos);
		sprite.setRotation(playerAngle);
		speedx = sin((playerAngle * pi) / 180) * bullet_speed;
		speedy = -cos((playerAngle * pi) / 180) * bullet_speed;
	}
	void update() {
		sprite.move(speedx, speedy);
	}





	void hit() { m_hit = true; }
	bool get_hit() { return m_hit; }

	auto getPosition() { return sprite.getPosition(); }

	bool offScreen() {
		auto bulletPos = getPosition();
		auto bulletBounds = getHitbox();
		if (bulletPos.x < -bulletBounds.width ||
			bulletPos.x > window_width + bulletBounds.width ||
			bulletPos.y > window_height + bulletBounds.height ||
			bulletPos.y < -bulletBounds.height)
		{
			return true;
		}
		return false;
	}
	sf::Sprite& getSprite() { return sprite; }
	sf::FloatRect getHitbox() { return sprite.getGlobalBounds(); }
};