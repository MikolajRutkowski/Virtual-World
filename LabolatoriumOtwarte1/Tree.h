#pragma once
#include "Plant.h"
class Tree :
    public Plant
{
    public:
    Tree(int x ,int y);
    ~Tree(void);
    void dead(Organism* kiler) override;

};

