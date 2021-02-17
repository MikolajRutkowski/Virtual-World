#pragma once
#include <iostream>
#include <string>
#include"Animal.h"
#include"Organism.h"
#include <fstream>

using namespace std;
class World
{

	int getSize();

	void add_descendant(char id, int x, int y);
	void makeWorld();
	static	int size_of_word;
	
	static char** tab;
	// try add only to the matrix
	bool add_sth(char id, int x, int y);
	
	void make_empty(int x, int y);
	int set_color(int x, int y);
	public:
	World(int size);
	World(string save);
	void creat(char what = '0', int x = -1, int y = -1);
	
	void DrawWord();
	
	
	// add mesage to messege box
	void add_message(string m);

	void live();
	
	void save_world(string patch);
	
	void clean_tab_of_life();
	
	void display_opions();

~World(void);
};

