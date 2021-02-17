#include "Animal.h"
#include"Organism.h"
#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;



void Animal::increas_age()
{
	age++;
}



char Animal::get_ID()
{
	return ID;
}

Animal::Animal(int x, int y):Organism(x,y)
{
	initiative = 1;
	ID = 'A';
	old_x = x;
	old_y = y;
	alive = true;
}

Animal::~Animal(void)
{
}

void Animal::move(int x, int y)
{
	old_x = get_X();
	old_y = get_Y();
	this->x = x;
	this->y = y;
}


void Animal::move(int size )
{
	old_x = get_X();
	old_y = get_Y();
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

void Animal::dead(Organism* kiler)
{

	alive = false;
}

bool Animal::is_alive()
{
	return alive;
}

bool Animal::Collision(Organism* a)
{
	

	

	int strength_one = get_Strength();
	int strength_two = a->get_Strength();
	

	if (get_ID() == a->get_ID()) {
		move(old_x, old_y);
		return false;
	}

	if (strength_one == strength_two) {
		x = old_x;
		y = old_y;
		return false;
	}
	if (strength_one < strength_two) {
		dead(a);
		x = old_x;
		y = old_y;
		return false;
	}
	else {
		a->dead(a);
		return true;
	}

	
}




