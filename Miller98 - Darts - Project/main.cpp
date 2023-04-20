#include <iostream>
#include "Game.h"
#include <time.h>
#include "UI.h"

int main() {
	srand(time(NULL));
	
	Player p1("Joe", 71);
	Player p2("Sid", 73);


	UI u(p1, p2);

	std::cout << "Enter anything to close the program" << std::endl;
	char a;
	std::cin >> a;

	return 0;
}