#include "World.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>

#include <fstream>
#include"Organism.h"
#include"Fox.h"
#include"Fruit_Bush.h"
#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"
#include"Grass.h"
#include"Snali.h"
#include"Tree.h"
#include"Beaver.h"
HANDLE hOut;

using namespace std;

int World::size_of_word;
char** World::tab;

const int size_of_info = 20;
string tab_of_info[size_of_info];

 Organism* tab_of_life_form[200];
int conter_of_live_form ;

int World::getSize() {
	return size_of_word;
}

//create wordl of this size
World::World(int size) {
	add_message("Make Matrix");
	this->size_of_word = size ;
	tab = new char*[size_of_word];
	for (int i = 0; i < size_of_word; i++)
	{
		tab[i] = new char[size_of_word];
	}
	conter_of_live_form = 0;
	makeWorld();
}

World::World(string save)
{
	add_message("save reload");
	fstream plik;
	plik.open(save,  ios::in );
	int sizee;
	plik >> sizee;
	this->size_of_word = sizee;
	tab = new char* [size_of_word];
	for (int i = 0; i < size_of_word; i++)
	{
		tab[i] = new char[size_of_word];
	}
	conter_of_live_form = 0;
	makeWorld();
	int conter;
	plik >> conter;
	int xx;
	int yy;
	char iid;
	for (int i = 0; i < conter; i++)
	{
		plik >> iid;
		plik >> xx;
		plik >> yy;
		creat(iid, xx, yy);
	}


}

int random_locaion(int size) {
	int x = rand() % size;
	return x;
}





void World::creat(char what, int x, int y)
{
	string m = "";
	if (x < 0 || y < 0) {
		do {
			x = random_locaion(size_of_word);
			y = random_locaion(size_of_info);
		} while (!add_sth(' ', x,y));
	}
	switch (what)
	{
	case 'F' :
	{
		tab_of_life_form[conter_of_live_form] = new Fox(x,y);

		if (add_sth(tab_of_life_form[conter_of_live_form]->get_ID()
			, tab_of_life_form[conter_of_live_form]->get_X()
			, tab_of_life_form[conter_of_live_form]->get_Y())) {
			
			m = "Creat new Fox, on pole:";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_X());
			m += " ";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_Y());
			add_message(m);
			conter_of_live_form++;
		}
		else
		{
			delete tab_of_life_form[conter_of_live_form];
			add_message("I cant create Fox here");
		}
		break;
	}
	case 'T':
	{
		tab_of_life_form[conter_of_live_form] = new Tree(x, y);

		if (add_sth(tab_of_life_form[conter_of_live_form]->get_ID()
			, tab_of_life_form[conter_of_live_form]->get_X()
			, tab_of_life_form[conter_of_live_form]->get_Y())) {
			
			m = "Creat new Tree, on pole:";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_X());
			m += " ";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_Y());
			add_message(m);
			conter_of_live_form++;
		}
		else
		{
			delete tab_of_life_form[conter_of_live_form];
			add_message("I cant create Tree here");
		}
		break;
	}
	case '.':
	{
		tab_of_life_form[conter_of_live_form] = new Snali(x, y);

		if (add_sth(tab_of_life_form[conter_of_live_form]->get_ID()
			, tab_of_life_form[conter_of_live_form]->get_X()
			, tab_of_life_form[conter_of_live_form]->get_Y())) {
			
			m = "Creat new Snali, on pole:";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_X());
			m += " ";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_Y());
			add_message(m);
			conter_of_live_form++;
		}
		else
		{
			delete tab_of_life_form[conter_of_live_form];
			add_message("I cant create Snali here");
		}
		break;
	}
	case 'B':
	{
		
		
		tab_of_life_form[conter_of_live_form] = new Fruit_Bush(x, y);

		if (add_sth(tab_of_life_form[conter_of_live_form]->get_ID()
			, tab_of_life_form[conter_of_live_form]->get_X()
			, tab_of_life_form[conter_of_live_form]->get_Y())) {
			
			m = "Creat new Fruit_Bush, on pole:";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_X());
			m += " ";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_Y());
			add_message(m);
			conter_of_live_form++;
		}
		else
		{
			delete tab_of_life_form[conter_of_live_form];
			add_message("I cant create Fruit_Bush here");
		}
		break;
	}
	case 'W':
	{
		tab_of_life_form[conter_of_live_form] = new Wolf(x, y);

		if (add_sth(tab_of_life_form[conter_of_live_form]->get_ID()
			, tab_of_life_form[conter_of_live_form]->get_X()
			, tab_of_life_form[conter_of_live_form]->get_Y())) {
			
			m = "Creat new Wolf, on pole:";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_X());
			m += " ";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_Y());
			add_message(m);
			conter_of_live_form++;
		}
		else
		{
			delete tab_of_life_form[conter_of_live_form];
			add_message("I cant create Wolf here");
		}
		break;
	}
	case 'S':
	{
		tab_of_life_form[conter_of_live_form] = new Sheep(x, y);

		if (add_sth(tab_of_life_form[conter_of_live_form]->get_ID()
			, tab_of_life_form[conter_of_live_form]->get_X()
			, tab_of_life_form[conter_of_live_form]->get_Y())) {
			
			m = "Creat new Sheep, on pole:";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_X());
			m += " ";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_Y());
			add_message(m);
			conter_of_live_form++;
		}
		else
		{
			delete tab_of_life_form[conter_of_live_form];
			add_message("I cant create Sheep here");
		}
		break;
	}
	case 'G':
	{
		tab_of_life_form[conter_of_live_form] = new Grass(x, y);

		if (add_sth(tab_of_life_form[conter_of_live_form]->get_ID()
			, tab_of_life_form[conter_of_live_form]->get_X()
			, tab_of_life_form[conter_of_live_form]->get_Y())) {
			
			m = "Creat new Grass, on pole:";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_X());
			m += " ";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_Y());
			add_message(m);
			conter_of_live_form++;
		}
		else
		{
			delete tab_of_life_form[conter_of_live_form];
			add_message("I cant create Grass here");
		}
		break;
	}
	case 'Q':
	{
		tab_of_life_form[conter_of_live_form] = new Beaver(x, y);

		if (add_sth(tab_of_life_form[conter_of_live_form]->get_ID()
			, tab_of_life_form[conter_of_live_form]->get_X()
			, tab_of_life_form[conter_of_live_form]->get_Y())) {

			m = "Creat new Beaver, on pole:";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_X());
			m += " ";
			m += to_string(tab_of_life_form[conter_of_live_form]->get_Y());
			add_message(m);
			conter_of_live_form++;
		}
		else
		{
			delete tab_of_life_form[conter_of_live_form];
			add_message("I cant create Beaver here");
		}
		break;
	}
	default:

		add_message("I dont know this ID");

		break;
	}
	DrawWord();
}



void World:: makeWorld() {
	for (int y = 0; y < size_of_word; y++)
	{
		for (int x = 0; x < size_of_word; x++)
		{
			tab[y][x] = ' ';
		}
	}

	
}

void Draw_Single_line(int size) {
	int x = 3;
	x = x + (size * 4);
	
	for (int i = 0; i < x; i++)
	{
	
		if ((i+2) % 4 == 0) {
			cout << "+";
			continue;
		}
		cout << "-";
	}
	cout << endl;
}




void World::DrawWord()
{
	system("cls");
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 10);
	
	
	cout << "--+";
	for (int i = 0; i < size_of_word; i++)
	{
		if (i < 10) {
			cout << "-" << i << "-+";
		}
		else
		{
			cout << "-" << i << "+";
		}
	}
	cout << endl;
		for (int y = 0; y < size_of_word; y++)
		{
			if (y < 10) {
				cout<<"0" << y << "|";
			}
			else
			{
				cout  << y << "|";
			}

			for (int x = 0; x < size_of_word; x++)
			{
				cout << " " ;
				SetConsoleTextAttribute(hOut, set_color(x,y));
				cout << tab[x][y];
				SetConsoleTextAttribute(hOut, 10);
				cout << " " << "|";
			}
			cout << endl;
			Draw_Single_line(size_of_word);
		}
		cout << "--------------------------------------------------" << endl;
		for (int i = 0; i < size_of_info; i++)
		{
			cout << i + 1 << ": " << tab_of_info[i] << endl;
		}
}

bool World::add_sth(char id, int x, int y) {
	
	if (tab[x][y] == ' ') {
		tab[x][y] = id;
		return true;
	}
	return false;
}
 
void World::add_message(string m){
	 for (int i = 0; i < size_of_info-1; i++)
	 {
		 tab_of_info[i] = tab_of_info[i + 1];
	 }
	 tab_of_info[size_of_info-1] = m;
}

void World:: make_empty(int x, int y) {
	tab[x][y] = ' ';
}

int World::set_color(int x, int y)
{
	int k = 10;
	if (tab[x][y] == 'G') {
		k = 34;
	}
	if (tab[x][y] == 'W') {
		k = 8;
	}
	if (tab[x][y] == 'S') {
		k = 7;
	}
	if (tab[x][y] == 'F') {
		k = 12;
	}
	if (tab[x][y] == 'B') {
		k = 5;
	}
	if (tab[x][y] == 'T') {
		k = 6;
	}
	return k;
}

int find_in_live_tab(int x, int y, int who_not) {
	for (int i = 0; i < conter_of_live_form; i++)
	{
		if (tab_of_life_form[i]->get_X() == x && tab_of_life_form[i]->get_Y() == y && i != who_not) {
			return i;
		}
	}
}

void World::add_descendant(char id, int x, int y)
{
	int start_x = x - 1;
	if (start_x < 0) {
		start_x = getSize() - 1;
	}
	int start_y = y - 1;
	if (start_y < 0) {
		start_y = getSize() - 1;
	}
	bool free = false;
	for (int i = 0; i < 3; i++)
	{
		if (free == true) { break; }
		for (int j = 0; j < 3; j++)
		{
			start_x += j; start_y += i;
			if (start_x == getSize()) { start_x = 0; }
			if (start_y == getSize()) { start_y = 0; }
			if (tab[start_x ][start_y ] == ' ') {
				creat(id, start_x , start_y);
				free = true;
				break;
			}
		}
	}

}

 void World::live()
 {
	 string m;
	 m = "";
	 int x, y;
	 char stop;
	 // for animals
	 for (int iniciativ = 10; iniciativ > 0; iniciativ--)
	 {
		 //cout << iniciativ;
		 for (int i = 0; i < conter_of_live_form; i++)
		 {
			 
			 if (tab_of_life_form[i]->is_alive() == true)
			 {
				 m = "";
				if (tab_of_life_form[i]->get_Initiative() == iniciativ) {
					//cout << "I find live form: " << tab_of_life_form[i]->get_ID() << endl;
					//cin >> stop;
					//meke empty old pole
					x = tab_of_life_form[i]->get_X();
					y = tab_of_life_form[i]->get_Y();
				 make_empty(x, y);

				 tab_of_life_form[i]->move(getSize());
				 if (add_sth(tab_of_life_form[i]->get_ID()
					 , tab_of_life_form[i]->get_X()
					 , tab_of_life_form[i]->get_Y()
				 )) {
					 // normal move
					 m += tab_of_life_form[i]->get_ID();
					 m += " move from: ";
					 m += to_string(x);
					 m += " , ";
					 m += to_string(y);
					 m += " to: ";
					 m += to_string(tab_of_life_form[i]->get_X());
					 m += " , ";
					 m += to_string(tab_of_life_form[i]->get_Y());
					 add_message(m);
				 }
				 else {
					 //colision
					 m += tab_of_life_form[i]->get_ID();
					 m += " move from: ";
					 m += to_string(x);
					 m += " , ";
					 m += to_string(y);
					 m += " to: ";
					 m += "colision on pole: ";
					 m += to_string(tab_of_life_form[i]->get_X());
					 m += " , ";
					 m += to_string(tab_of_life_form[i]->get_Y());

					 int who = find_in_live_tab(tab_of_life_form[i]->get_X(), tab_of_life_form[i]->get_Y(),i );
					 bool vin =tab_of_life_form[i]->Collision(tab_of_life_form[who]);


					 add_message(m);
					 // the same animal , new animal born
					 if (tab_of_life_form[i]->get_ID() == tab_of_life_form[who]->get_ID()) {
						 add_descendant(tab_of_life_form[i]->get_ID(), tab_of_life_form[i]->get_X(), tab_of_life_form[i]->get_Y());
						 DrawWord();
						 Sleep(2000);
						 continue;
					 }
					 // animal go and died RIP
					 if (vin == false && tab_of_life_form[i]->is_alive() == false ) {
						 make_empty(tab_of_life_form[i]->get_X(), tab_of_life_form[i]->get_Y());
						 DrawWord();
						 Sleep(2000);
						 continue;
					 }
					 // second Organism has the same strng like first
					 if (vin == false && tab_of_life_form[i]->is_alive() == true) {
						 add_sth(tab_of_life_form[i]->get_ID(), tab_of_life_form[i]->get_X(), tab_of_life_form[i]->get_Y());

						// cout << tab_of_life_form[i]->get_ID() << tab_of_life_form[i]->get_X() << tab_of_life_form[i]->get_Y();
						 
						 DrawWord();
						 Sleep(2000);
						 continue;
						 
					 }
					 // first organism win with second
					 if (vin == true && tab_of_life_form[who]->is_alive() == false) {
						 make_empty(tab_of_life_form[i]->get_X(), tab_of_life_form[i]->get_Y());
						 add_sth(tab_of_life_form[i]->get_ID(), tab_of_life_form[i]->get_X(), tab_of_life_form[i]->get_Y());
						 DrawWord();
						 Sleep(2000);
						 continue;
					 }
					 // for sneli and Trees
					 if (vin == true && tab_of_life_form[who]->is_alive() == true) {
						 i--;
						 
						 Sleep(2000);
						 continue;
					 }
					
					
				 }
				 
				 DrawWord();
				 Sleep(2000);
			 }
		 }
	 }
	 }

	 // for plants
	 for (int i = 0; i < conter_of_live_form; i++)
	 {
		 if (tab_of_life_form[i]->get_Initiative() == 0) {
			 int old_x = tab_of_life_form[i]->get_X();
			 int old_y = tab_of_life_form[i]->get_Y();

			 tab_of_life_form[i]->move(getSize());

			 if (tab_of_life_form[i]->get_X()!= old_x && tab_of_life_form[i]->get_Y() != old_y) {
				 if (add_sth(tab_of_life_form[i]->get_ID()
					 , tab_of_life_form[i]->get_X()
					 , tab_of_life_form[i]->get_Y())) {
					 make_empty(tab_of_life_form[i]->get_X(), tab_of_life_form[i]->get_Y());

					 creat(tab_of_life_form[i]->get_ID(), tab_of_life_form[i]->get_X(), tab_of_life_form[i]->get_Y());
					tab_of_life_form[i]->move(old_x, old_y);
					add_sth(tab_of_life_form[i]->get_ID()
						, tab_of_life_form[i]->get_X()
						, tab_of_life_form[i]->get_Y());
				 }
				 else {
					 tab_of_life_form[i]->move(old_x, old_y);
				 }
			 }



		 }
	 }
	 clean_tab_of_life();

 }

 

 void World::save_world(string patch)
 {
	 fstream plik;
	 plik.open(patch, ios::in | ios::out | ios::trunc);
	 
	 if (plik.good() == true)
	 {
		 std::cout << "Uzyskano dostep do pliku!" << std::endl;
		 //tu operacje na pliku

		 plik << getSize() << endl;
		 plik << conter_of_live_form << endl;
		 for (int i = 0; i < conter_of_live_form; i++)
		 {
			 plik << tab_of_life_form[i]->get_ID() << " ";
			 plik << tab_of_life_form[i]->get_X() << " ";
			 plik << tab_of_life_form[i]->get_Y() << endl;
		 }



	 }
	 else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;


 }

 void World::clean_tab_of_life()
 {
	 for (int i = 0; i < conter_of_live_form; i++)
	 {
		 if (tab_of_life_form[i]->is_alive() == false) {
			 delete tab_of_life_form[i];
			 for (int j = i+1; j < conter_of_live_form; j++)
			 {
				 tab_of_life_form[j - 1] = tab_of_life_form[j];

			 }
			 conter_of_live_form--;
		 }
		 
	 }
	 for (int i = 0; i < conter_of_live_form; i++)
	 {
		 if (tab_of_life_form[i]->is_alive() == true) {
			 if (
				 tab[tab_of_life_form[i]->get_X()][tab_of_life_form[i]->get_Y()] == ' '
				 ) {
				 tab[tab_of_life_form[i]->get_X()][tab_of_life_form[i]->get_Y()] = tab_of_life_form[i]->get_ID();
			 }
		 }
	 }

	 DrawWord();

 }

 void World::display_opions()
 {
	 cout << "Dostepne opcje: " << endl;
	 cout << "n - nowa gra" << endl;
	 cout << "s - zapisz gre" << endl;
	 cout << "c - contynuj rozgrywke " << endl;
	 cout << "r - wczytaj gre" << endl;
	 cout << "i - wyswietl komendy " << endl;
	 cout << "e - zakoncz" << endl;
 }


World::~World(void) {
	
	for (int i = 0; i < size_of_word; i++)
	{
		delete[] tab[i];
	}
	for (int i = 0; i < conter_of_live_form; i++)
	{
	//	delete[] tab_of_life_form[i];
	}
//	delete tab_of_life_form;
	delete[] tab;
}


