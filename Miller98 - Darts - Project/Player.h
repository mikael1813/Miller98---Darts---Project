#ifndef Player_h_
#define Player_h_


#include <string>

class Player {
private:
	std::string name;
	int score,frequency,darts;


public:
	Player() = default;

	//constructor
	Player(std::string name, int frequency);

	// returns the score of the player
	int get_score();

	//changes the score of the player
	void set_score(int score);

	// returns the frequency of the player
	int get_frequency();

	// changes the frequency of the player
	void set_frequency(int frequency);

	// returns the number of throws the player had during the last game
	int get_throws();

    // increments the number of times the player threw a dart by 1
	void throw_dart();

	// return the name of the player
	std::string get_name();

	// changes the score to 301 and the number of darts thrown to 0
	void reset();
};


#endif