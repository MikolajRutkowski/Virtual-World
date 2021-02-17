#include "Fox.h"
#include <cstdlib>
#include<iostream>
using namespace std;
Fox::Fox(int x, int y):Animal(x,y)
{
	strength = 3;
	initiative = 7;
	ID = 'F';
}

Fox::~Fox(void)
{
}

bool Fox::Collision(Organism* a)
{
	
	if (a->get_Strength() > get_Strength()) {
		
		return false;
	}


	return Animal::Collision(a);
	
}
