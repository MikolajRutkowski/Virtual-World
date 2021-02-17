#include "Fruit_Bush.h"
//guarana

Fruit_Bush::Fruit_Bush(int x, int y):Plant(x,y)
{
	ID = 'B';
}

Fruit_Bush::~Fruit_Bush(void)
{
}

void Fruit_Bush::dead(Organism* kiler)
{
	kiler->chache_strength(kiler->get_Strength() + 2);

	alive = false;
}
