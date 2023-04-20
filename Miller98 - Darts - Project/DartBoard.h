

#ifndef DartBoard_h_
#define DartBoard_h_

#include <vector>
#include <random>


class DartBoard {
private:
	std::vector<int> segments;

public:
	DartBoard() = default;

	// constructor
	DartBoard(std::vector<int> segments);

	// returns the bull (frequency)% of times and a random number between 1-20 otherwise
	int bull(int frequency);

	// 80% of the time return nr, 10% of the time return the number left of nr and 10% the number to the right
	// left and right according to the vector segments
	int nr_to_hit(int nr);
};


#endif