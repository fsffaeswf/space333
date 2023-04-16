#pragma once
#include "settings.h"

class HpBar {
private:
	sf::RectangleShape frame;
	sf::RectangleShape hp_bar;
	float hp_bar_width;
public:
	HpBar() {
		hp_bar.setSize(sf::Vector2f{ frame_width,frame_height });
		hp_bar.setFillColor(sf::Color::Blue);
		hp_bar.setPosition(sf::Vector2f{ 7.f ,7.f });
		frame.setOutlineThickness(2);
		frame.setSize(sf::Vector2f{ frame_width+4,frame_height+4});
		frame.setFillColor(sf::Color::Black);
		frame.setPosition(sf::Vector2f{ 5.f ,5.f});
	}
	void update(int playerHp) {
		if (playerHp < 0) {
			hp_bar_width = 0;
		}
		else {
			hp_bar_width = playerHp / 100.f * frame_width;
			
		}
		hp_bar.setSize(sf::Vector2f{ hp_bar_width,frame_height });
	}
	void draw(sf::RenderWindow& window, int playerHp) {
		window.draw(frame);
		window.draw(hp_bar);
		
	}
};