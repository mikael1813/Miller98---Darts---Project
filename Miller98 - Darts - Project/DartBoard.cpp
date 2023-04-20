#include "DartBoard.h"


DartBoard::DartBoard(std::vector<int> segments) :segments{ segments } {

}

int DartBoard::bull(int frequency) {
	int chance = rand() % 100 + 1;
	if (chance <= frequency) {
		return 50;
	}
	else {
		int nr = rand() % 20 + 1;
		return nr;
	}
}

int DartBoard::nr_to_hit(int nr) {
	int chance = rand() % 100 + 1;
	if (chance <= 80) {
		return nr;
	}
	else {
		chance = rand() % 2 + 1;
		int index;
		for (index = 0; index < segments.size(); index++) {
			if (segments.at(index) == nr) 
				break;
		}
		if (chance == 1) {
			if (index == 0)
				return segments.at(segments.size() - 1);
			else
				return segments.at(index - 1);
		}
		else {
			if (index == segments.size() - 1)
				return segments.at(0);
			else 
				return segments.at(index + 1);
		}
	}
}