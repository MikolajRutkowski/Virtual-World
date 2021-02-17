

#include <iostream>
#include "World.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "Animal.h"
#include"Fox.h"
#include <iostream>

using namespace std;



int main()
{
    char STOP;
    srand(time(NULL));

    World matrix(10);
    cout << "Wlecome in Matrixie, by: Mikolaj Rutkowski 175534 " << endl;
    matrix.display_opions();
    cin >> STOP;
    while (true)
    {
        if (STOP == 'n') {
            /**/
       
            matrix.DrawWord();
            matrix.creat('F', 1, 1);
            matrix.creat('Q');
            matrix.creat('T');
            matrix.creat('T', 1);
            matrix.creat('G');
            matrix.creat('Q');
            matrix.creat('F');
            matrix.creat('F');
            matrix.creat('G');
            matrix.creat('S');
            matrix.creat('S');
            matrix.creat('W');
            matrix.creat('W'); 
            matrix.creat('B'); 
            matrix.creat('B');
            
            matrix.DrawWord();
        }
        if (STOP == 's') {

            
            matrix.save_world("world1.txt");

        }
        if (STOP == 'c') {
            matrix.live();
        }
        if (STOP == 'r') {
            World matrix2("world1.txt");
           // matrix2.DrawWord();
            cin >> STOP;
        }
        if (STOP == 'e') 
        { 
            break; }
        if (STOP == 'i') {
            matrix.display_opions();
        }
     
        cout << "Clik c to continue" << endl;
        STOP = NULL;
        cin >> STOP;
    
    }
    
     return 0;
}

