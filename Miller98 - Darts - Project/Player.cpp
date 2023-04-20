#include "Player.h"


Player::Player(std::string name, int frequency) :name{ name }, frequency{ frequency } {
	score = 301;
	darts = 0;
}

int Player::get_score() {
	return score;
}

void Player::set_score(int score) {
	this->score = score;
}

int Player::get_frequency() {
	return frequency;
}

void Player::set_frequency(int frequency){
	this->frequency = frequency;
}

int Player::get_throws() {
	return darts;
}

void Player::throw_dart() {
	darts++;
}

std::string Player::get_name() {
	return name;
}

void Player::reset() {
	score = 301;
	darts = 0;
}