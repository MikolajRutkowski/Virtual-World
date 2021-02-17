#include "Organism.h"

void Organism::chache_strength(int for_much)
{
	strength = for_much;
}

Organism::Organism(int x, int y)
{
	this->x = x;
	this->y = y;
	initiative = 0;
	strength = 1;
	 ID = '0';
	 age = 1;
	 alive = true;
}

Organism::~Organism(void)
{
}

int Organism::get_X()
{
	return x;
}

int Organism::get_Y()
{
	return y;
}

int Organism::get_Initiative()
{
	return initiative;
}

int Organism::get_Strength()
{
	return strength;
}
