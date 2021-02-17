#include "Sheep.h"

Sheep::Sheep(int x, int y):Animal(x, y) {
	strength = 4;
	initiative = 4;
	ID = 'S';
}

Sheep::~Sheep(void)
{
}
