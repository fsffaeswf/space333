#pragma once
#include "settings.h"
class TextObj {
private:
	sf::Font font;
	sf::Text text;

public:
	TextObj(std::string str,sf::Vector2f pos) {
		font.loadFromFile("DS-DIGIB.ttf");
		text.setString(str);
		text.setFont(font);
		text.setCharacterSize(char_size);
		text.setPosition(pos);
	}
	void update(std::string str) {
		text.setString(str);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(text);
	}
};
