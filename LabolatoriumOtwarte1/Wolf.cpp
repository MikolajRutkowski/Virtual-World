#include "Wolf.h"


Wolf::Wolf(int x, int y) :Animal(x, y) {
	strength = 9;
	initiative = 5;
	ID = 'W';
}



Wolf::~Wolf(void)
{
}
