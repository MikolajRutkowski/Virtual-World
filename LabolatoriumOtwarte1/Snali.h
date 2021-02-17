#pragma once
#include "Animal.h"
class Snali :
    public Animal
{
public:
    Snali(int x, int y);
    ~Snali(void);
    void dead(Organism* kiler)override;
};

