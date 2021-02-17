#pragma once
#include "Organism.h"
#include "Plant.h"
#include <string>
class Animal :
    public Organism
{
protected:
     int old_x;
     int old_y;
     
public:
   
    void increas_age();
  
    char get_ID();
    Animal(int ,int);
    ~Animal(void);
    void move(int x, int y);
    void move(int size);
    void dead(Organism* kiler) override;
    bool is_alive();
    bool Collision(Organism *a) ;
    
    

    
};

