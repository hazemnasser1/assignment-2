// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"XO_Classes.h"
using namespace std;

void GameManager::run() {
    Board x_o;
    int x, y;
    Player ahmed{'x'};
    computerPlayer c;
    x_o.display_board();
    while (true) {
        start:
        ahmed.get_move(x, y);
        while (!x_o.update_board(x,y,'x')){
            goto start;
        }
            c.minimax(x_o, 100, false);
            x_o.display_board();
            if (x_o.is_winner() != 1){
                break;
        }
    }
    if(x_o.is_winner() == 2){
        cout << "Player X " << "won " << endl;
    } else if(x_o.is_winner() == -2){
        cout << "Player O " << "won " << endl;
    }
    else{
        cout << "In draw "<< endl;
    }
}

