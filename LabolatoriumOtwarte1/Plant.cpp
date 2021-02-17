#include "Plant.h"
#include "Organism.h"
#include <cstdlib>

void Plant::increas_age()
{
	age++;
}



char Plant::get_ID()
{
	return ID;
}

Plant::Plant(int x, int y):Organism(x,y)
{
	ID = 'P';
	strength = 0;
	edible = true;
	chance_of_growth = 4;
}

Plant::~Plant(void)
{
}

void Plant::move(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Plant::move(int size)
{
	//Plant cant move but can growth
	int growth = rand() % 10;
	growth++;
	if (growth <= chance_of_growth) {
		if (alive) {
			int new_x = 0;
			int	new_y = 0;
			while (new_x == 0 && new_y == 0)
			{
				new_x = (rand() % 3) - 1;
				new_y = (rand() % 3) - 1;
			}
			new_x += get_X();
			new_y += get_Y();

			if (new_x < 0) {
				new_x = size - 1;
			}
			if (new_x >= size) {
				new_x = 0;
			}
			if (new_y < 0) {
				new_y = size - 1;
			}
			if (new_y >= size) {
				new_y = 0;
			}
			this->x = new_x;
			this->y = new_y;
		}

	}

}

void Plant::dead(Organism* kiler)
{
	alive = false;
}

bool Plant::Collision(Organism* a)
{
	return false;
}



bool Plant::is_alive()
{
	return alive;
}


