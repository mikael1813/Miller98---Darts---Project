#include "Game.h"
#include <iostream>

Game::Game(std::vector<Player> players, DartBoard Board) :players{ players }, Board{ Board }{
	//start();
	//get_winner();
	//print_winner();
	//print_throws();
	//std::cout << std::endl;
}

void Game::start() {
	while (true) {
		bool done = true;
		for (auto& p : players) {
			for (int x = 0; x < 3; x++) {
				if (p.get_score() != 0) {
					done = false;
					if (p.get_score() >= 100) {
						p.throw_dart();
						int dart = Board.bull(p.get_frequency());
						if (p.get_score() - dart >= 50)
							p.set_score(p.get_score() - dart);
					}

					if (p.get_score() < 100 && p.get_score() >= 70) {
						p.throw_dart();
						int dart = Board.nr_to_hit(20);
						p.set_score(p.get_score() - dart);
					}

					if (p.get_score() > 50 && p.get_score() < 70) {
						p.throw_dart();
						int desired_number = p.get_score() - 50;
						int dart = Board.nr_to_hit(desired_number);
						if (dart == desired_number) {
							p.set_score(50);
						}
					}

					if (p.get_score() == 50) {
						p.throw_dart();
						int dart = Board.bull(p.get_frequency());
						if (dart == 50) {
							p.set_score(0);
						}
					}
				}
			}
		}

		if (done) {
			break;
		}
	}
}

void Game::User_Controlled() {
	while (true) {
		bool done = true;
		for (auto& p : players) {
			for (int x = 0; x < 3; x++) {
				if (p.get_score() != 0) {
					done = false;
					bool ok = false;
					std::cout <<std::endl<< "It's " << p.get_name() << "'s";
					if (x == 0) std::cout << " first throw" << std::endl;
					if (x == 1) std::cout << " second throw" << std::endl;
					if (x == 2) std::cout << " third throw" << std::endl;
					std::cout << "Score: " << p.get_score() << std::endl;
					std::cout << "Select the number which you want to hit(50 for the bull)" << std::endl;
					int k;
					std::cin >> k;
					if (k == 50) {
						if (p.get_score() >= 100) {
							p.throw_dart();
							int dart = Board.bull(p.get_frequency());
							std::cout << "You hit " << dart << std::endl;
							p.set_score(p.get_score() - dart);
						}
						else
						if (p.get_score() == 50) {
							p.throw_dart();
							int dart = Board.bull(p.get_frequency());
							std::cout << "You hit " << dart << std::endl;
							if (dart == 50) {
								p.set_score(0);
							}
							else ok = true;
						}
						else
						if (p.get_score() > 50 && p.get_score() < 100) {
							p.throw_dart();
							int dart = Board.bull(p.get_frequency());
							std::cout << "You hit " << dart << std::endl;
							if (p.get_score() - dart >= 50) {
								p.set_score(p.get_score() - dart);
							}
							else
								ok = true;
						}
						if (ok) std::cout << "But that hit was invalid so it doesn't count" << std::endl;
					}
					if (k >= 0 && k <= 20) {
						p.throw_dart();
						int dart = Board.nr_to_hit(k);
						std::cout << "You hit " << dart << std::endl;
						if (p.get_score() - dart >= 50) {
							p.set_score(p.get_score() - dart);
						}
						else {
							std::cout << "But that hit was invalid so it doesn't count" << std::endl;
						}
					}
				}
			}
		}

		if (done) {
			break;
		}
	}
}

std::vector<Player> Game::plrs() {
	return players;
}

void Game::print_winner() {
	std::cout <<"The winner is " <<winner.get_name() << std::endl;
}

void Game::print_throws() {
	for (auto p : players) {
		std::cout <<"Player "<< p.get_name() << " has thrown " << p.get_throws() <<" darts"<< std::endl;
	}

}

void Game::get_winner() {
	int min = 302;
	Player w;
	for (auto p : players) {
		if (p.get_throws() < min) {
			w = p;
			min = p.get_throws();
		}
	}
	winner = w;
}

void Game::reset() {
	for (auto& p : players) {
		p.reset();
	}
}

void Game::player_percentages() {

	std::vector<int> wins;
	int total = 0;

	for (int i = 0; i < players.size(); i++) {
		wins.push_back(0);
	}

	for (int i = 0; i < 1000; i++) {
		reset();
		start();
		get_winner();

		for (int j = 0; j < players.size(); j++) {
			if (players.at(j).get_name() == winner.get_name()) {
				wins.at(j)++;
				total++;
				break;
			}
		}

	}

	for (int i = 0; i < players.size(); i++) {
		double percentage = (wins.at(i) * 100) / total;
		std::cout << players.at(i).get_name() << " has a " << percentage <<"% chance to win the game"<< std::endl;
	}

}

void Game::game_length_percentages() {
	int game_length[301];
	int total = 0;

	for (int i = 7; i < 301; i++) game_length[i] = 0;

	for (int i = 0; i < 1000; i++) {
		reset();
		start();

		game_length[players.at(0).get_throws()]++;
		total++;

	}

	for (int i = 7; i < 20; i++) {
		float percentage = (game_length[i] * 100) / total;
		std::cout << percentage << "% of games would last "<<i<<" throws" << std::endl;
	}
}