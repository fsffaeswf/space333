#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <vector>
#include "meteor.h"
#include "player.h"
#include "hp_bar.h"
#include "lives_indicator.h"
#include "bonus.h"
#include "background.h"

class Game {
private:
	sf::RenderWindow window;
	std::vector<Meteor*> meteors;
	Player player;
	HpBar hpBar;
	int score = 0;
	TextObj score_text,game_over_text;////////////////////////////////////////////
	std::list<LivesIndicator*> livesIndicator;
	Background background;
	std::list<Bonus*> bonuses;

public:
	void spawnMeteors(size_t n) {
		for (int i = 0; i < n; i++) {
			int num = rand() % 4 + 1;
			std::string fileName = "images\\spaceMeteors_00" + std::to_string(num) + ".png";
			Meteor::MeteorSize size = (Meteor::MeteorSize)(rand() % 3);
			float x = rand() % 301 - 300.f;
			int choice = rand() % 10000;
			if (choice < 5000)x += 1500.f;
			float y = rand() % 301 - 300.f;
			choice = rand() % 10000;
			if (choice < 5000) y += 1500.f;
			float speedx = rand() % 11 - 5.f;
			float speedy = rand() % 11 - 5.f;
			Meteor* m = new Meteor(fileName, size, sf::Vector2f{ x, y }, sf::Vector2f{ speedx,speedy });
			meteors.push_back(m);
		}
	}
	Game() :score_text(std::to_string(score), score_text_pos),
		game_over_text(game_over, gameover_text_pos) {/////////////////////////////////////////////////////
		window.create(sf::VideoMode{ (size_t)window_width,(size_t)window_height }, "f");
		window.setFramerateLimit(fps);
		spawnMeteors(35);
		for (size_t i = 0; i < max_player_lives; i++) {
			float xPos = window_width / 2 - 64.f;
			float yPos = 10.f;
			LivesIndicator* life = new LivesIndicator(sf::Vector2f{ xPos + i * 48.f, yPos });
			livesIndicator.push_back(life);
		}
	}

	void chek_events() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			// ???????????? ????? ?? «???????» ? ????? ??????? ?????
			if (event.type == sf::Event::Closed)
				// ????? ????????? ???
				window.close();
		}
	}

	void update() {
		for (int i = 0; i < meteors.size(); i++) {
			meteors.at(i)->update();
		}
		player.update();
		hpBar.update(player.get_hp());
		score_text.update("Score: "+std::to_string(score));
		for (auto& bonus : bonuses) {
			bonus->update();
		}
	}

	void chek_collisons() {
		sf::FloatRect player_bounds = player.getHitbox()
			;
		for (auto& meteor : meteors) {
			sf::FloatRect meteor_bounds = meteor->getHitbox();
			if (meteor_bounds.intersects(player_bounds)) {
				player.decrease_hp(meteor->getDamage());
				meteor->setRandomPosition();
				if (player.get_hp() < 0) {
					if (player.get_lives() == 0){}
					player.player_minus_life();
					player.restoreHp();
					livesIndicator.pop_back();
				}
			}
		
		}
		auto bullet_sprites = player.getBullets();
			for (auto& meteor : meteors) {
				sf::FloatRect meteor_bounds = meteor->getHitbox();
				for (auto& bullet : (*bullet_sprites)){
					sf::FloatRect bullet_bounds = bullet->getHitbox();
					if (meteor_bounds.intersects(bullet_bounds)) {
						int chance = rand() % 30000;
						int bonusType = rand() % Bonus::BonusType::Max_Bonus_type;
						if (chance < 30000 * 0.5) {
							Bonus* bonus = new Bonus(meteor->get_pos(), bonusType);
							bonuses.push_back(bonus);
						}


						meteor->setRandomPosition();
						score++;
						bullet->hit();
					}
				}
			}
			for (auto& bonus : bonuses) {
				sf::FloatRect bonus_bounds = bonus->getHitbox();
				if (bonus_bounds.intersects(player_bounds)) {
					bonus->act(player);
					bonus->set_del();
				}
			}

			(*bullet_sprites).remove_if([](Bullet* laser) { return laser->get_hit(); });
			(*bullet_sprites).remove_if([](Bullet* laser) { return laser->offScreen(); });
			bonuses.remove_if([](Bonus* bonus) {return bonus->is_to_del(); });
	}
	void draw() {
		
		if (player.get_lives() <= 0) {///////////////////////
			window.clear();
			game_over_text.draw(window);
			window.display();
		}
		else {/////////////////////////
			window.clear();
			background.draw(window);
			for (int i = 0; i < meteors.size(); i++) {
				window.draw(meteors.at(i)->getSprite());
			}
			for (auto& life : livesIndicator) {
				life->draw(window);
			}
			for (auto& bonus : bonuses) {
				bonus->draw(window);
			}
			player.draw(window);
			hpBar.draw(window, player.get_hp());
			score_text.draw(window);
			window.display();
		}
	}

	void play() {
		while (window.isOpen())
		{
			chek_events();
			update();
			chek_collisons();
			draw();
		}
	}
};