#pragma once
#include "Organism.h"
#include"Animal.h"
class Plant :
    public Organism
{
protected:
    bool edible;
    int chance_of_growth;
public:
   
    void increas_age();
    
    char get_ID();
    Plant(int x, int y);
    ~Plant(void);
    void move(int x, int y);
    void move(int size);
    void dead(Organism* kiler) override;
    bool Collision(Organism* a);
    
    
    

    bool is_alive();
};

