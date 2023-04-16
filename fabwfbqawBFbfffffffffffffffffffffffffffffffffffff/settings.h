#pragma once
#include <SFML/Graphics.hpp>
const float window_width = 1200;
const float window_height = 900;

const float fps = 60.f;

std::string player_file_name = "images\\spaceShips_009.png";
std::string bullet_file_name = "images\\spaceMissiles_003.png";
std::string heart_file_name = "images\\heart.png";
std::string MedickKit_filename = "images\\medckit.png";
std::string SpeedBoost_filename = "images\\boostspeed.png";
std::string Kaboom_filename = "images\\kaboom.png";
std::string life_icon_filename = "images\\heart.png";
std::string background_filename = "images\\space.jpg";
std::string game_over = "GAME OVER";//////////////////////////

const float frame_width = 150;
const float frame_height = 20;

const double pi = 3.1415926535897932384626;
const float bullet_speed = 15.f;
const int player_max_hp = 100;
const int max_player_lives = 3;
const int char_size = 48;
const int FIRE_COOLDOWN = 200;
 float player_maxspeed = 10.f;
 const int bonus_cooldown = 5000;
 const float dv = 0.5;


const float top_border = -300.f;
const float bottom_border = 1200.f;
const float left_border = -300.f;
const float right_border = 1500.f;



const sf::Vector2f hp_text_pos{ 0.f,30.f };
const sf::Vector2f score_text_pos{ 1000.f,30.f };
const sf::Vector2f gameover_text_pos{ window_width/2 - 100.f,window_height/2 };/////////////////////////////







