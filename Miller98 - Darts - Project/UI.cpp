#include "UI.h"




UI::UI(Player p1, Player p2) :p1{ p1 }, p2{ p2 }{
	std::cout << "Press 1 if Joe is playing alone" << std::endl;
	std::cout << "Press 2 if Joe is playing against Sid" << std::endl;
	int n;
	std::cin >> n;
	if (n == 1) _1player();
	if (n == 2) _2players();
}

void UI::_1player() {
	std::vector<int> v{ 20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5 };
	DartBoard db(v);
	std::vector<Player> p{ p1 };
	Game game(p, db);
	game.reset();
	game.User_Controlled();
	game.game_length_percentages();
	std::cout << std::endl;
}

void UI::_2players(){
	std::vector<int> v{ 20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5 };
	DartBoard db(v);
	std::vector<Player> p{ p1,p2 };
	int n;
	while (true) {
		menu();
		std::cin >> n;
		bool ok = false;
		switch (n) {
		case 1:
			std::cout << "Insert the new frequency for " << p1.get_name() << std::endl;
			int new_frequency;
			std::cin >> new_frequency;
			this->p1.set_frequency(new_frequency);
			p.at(0).set_frequency(new_frequency);
			break;
		case 2:
			std::cout << "Insert the new frequency for " << p2.get_name() << std::endl;
			std::cin >> new_frequency;
			this->p2.set_frequency(new_frequency);
			p.at(1).set_frequency(new_frequency);
			break;
		case 3:
			p.at(0) = this->p2;
			p.at(1) = this->p1;
			this->p1 = p.at(0);
			this->p2 = p.at(1);
			break;
		case 4:
			ok = true;
			break;
		default:
			break;
		}
		if (ok) break;
	}
	Game game(p, db);
	game.User_Controlled();
	game.get_winner();
	game.print_winner();
	game.print_throws();
	game.player_percentages();

	std::cout << std::endl;
}

void UI::menu() {
	std::cout << "Name: " << p1.get_name() << " Frequency: " << p1.get_frequency() << std::endl;
	std::cout << "Name: " << p2.get_name() << " Frequency: " << p2.get_frequency() << std::endl;

	std::cout << std::endl << "Press 1 to change " << p1.get_name() << "'s frequency" << std::endl;
	std::cout << "Press 2 to change " << p2.get_name() << "'s frequency" << std::endl;
	std::cout << "Press 3 to change the order in which they start the game" << std::endl;
	std::cout << "Press 4 to start the game" << std::endl << std::endl;
}