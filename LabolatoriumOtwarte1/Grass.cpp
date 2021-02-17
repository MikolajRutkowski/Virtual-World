#include "Grass.h"

Grass::Grass(int x, int y):Plant(x,y)
{
	ID = 'G';
	chance_of_growth = 5;
	strength = 0;
}

Grass::~Grass(void)
{
}
