#include "Snali.h"
#include <cstdlib>
#include<iostream>
using namespace std;
Snali::Snali(int x, int y):Animal(x,y)
{
	ID = '.';
	strength = 1;
	initiative = 1;
}

Snali::~Snali(void)
{
}

void  Snali::dead(Organism* kiler) 
{
	char inn;
	cout << "Sneli is dead";
	cin >> inn;
	int s = rand() & 10;
	if (s > 6 && kiler->get_Strength() > 4) {
		// snieli alive
	}
	else {
		alive = false;
	}

}
