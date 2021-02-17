#include "Tree.h"

Tree::Tree(int x, int y):Plant(x,y) {
	ID = 'T';
	chance_of_growth = 2;

}
 void  Tree::dead (Organism * kiler)  {
	// tree is imortal only Beavers can eat them
	 if (kiler->get_ID() == 'Q') {
		 alive = false;
		 kiler->chache_strength(kiler->get_Strength() + 1);
	 }
}

Tree::~Tree(void)
{
}
