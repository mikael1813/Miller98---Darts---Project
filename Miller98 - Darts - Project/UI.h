

#ifndef UI_h_
#define UI_h_

#include "Game.h"
#include <iostream>


class UI {
private:
	Game game;
	Player p1;
	Player p2;

public:
	// constructor
	UI(Player p1, Player p2);

	// begins a game for one player and shows the chances of the game to end in "x" darts thrown
	void _1player();

	// begins a game for 2 players and shows at the end what were the percentages of winning of both players
	void _2players();

	// it shows the menu to guide te user
	void menu();
};

#endif // !UI_u_