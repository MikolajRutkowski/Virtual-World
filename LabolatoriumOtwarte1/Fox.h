#pragma once
#include "Animal.h"
class Fox :
    public Animal
{
protected:

    public:
    Fox(int x, int y);
    ~Fox(void);
    bool Collision(Organism* a);


};

