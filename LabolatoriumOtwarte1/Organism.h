#pragma once
#include<string>
class Organism
{
protected:
	int x;
	int y;
	int initiative;
	int strength;
	char ID;
	int age;
	bool alive;
public :
	virtual int get_X();
	virtual int get_Y();
	virtual void increas_age() = 0;
	virtual int get_Initiative();
	virtual char get_ID() = 0;
	virtual int get_Strength();
	virtual bool Collision(Organism *a) = 0;
	virtual void move(int x, int y) = 0;
	virtual void move(int size) = 0;
	virtual void dead(Organism *kiler ) = 0;
	
	virtual bool is_alive() = 0;
	void chache_strength(int for_much);

	


	Organism(int, int);
	~Organism(void);
};

