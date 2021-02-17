#pragma once
#include "Plant.h"

//guarana
class Fruit_Bush :
    public Plant
{
public:
    Fruit_Bush(int x, int y);
    ~Fruit_Bush(void);
    void dead(Organism* kiler) override;
};

