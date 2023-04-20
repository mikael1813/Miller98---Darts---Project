#ifndef Game_h_
#define Game_h_

#include "Player.h"
#include "DartBoard.h"
//#include "UI.h"


class Game {
private:
	std::vector<Player> players;
	DartBoard Board;
	Player winner;
	//UI u;

public:
	Game() = default;

	//constructor
	Game(std::vector<Player> players, DartBoard Board);

	// simulates a game with the least throws between the players(it works with 1 player as well)
	void start();

	// return the players
	std::vector<Player> plrs();

	// prints the name of the winner
	void print_winner();

	// for every player in the game prints their name and the number of throws they had during the last game
	void print_throws();

	// searches for the player with the least throws
	// if there are 2 players with the same number of throws the first one is the winner
	void get_winner();

	// estimates the chances of the players to win by simulating 1000 games
	void player_percentages();

	// it resets every player's score and number of darts thrown
	void reset();

	// it simulates a game where the user can choose which target to hit every time
	void User_Controlled();

	// it estimates the chances of a game ending with a number of throws by simulating 1000 games
	void game_length_percentages();
};



#endif