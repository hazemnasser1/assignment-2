// Class definition for XO_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "XO_Classes.h"
using namespace std;

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Board::update_board (int x, int y, char mark){
    // Only update if move is valid
     {
         if(!(x < 0 || x > 2 || y < 0 || y > 2) && board[x][y] == ' ') {
             board[x][y] = toupper(mark);
             return true;
         } else{
             return false;
         }
    }

}

// Display the board and the pieces on it
void Board::display_board() {
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool haveTheSameValueAndNotEmpty(char x, char y, char z) {
    if(x == y && x == z && x != ' ') {
        return true;
    }
    return false;
}
int Board::is_winner() {
    for(int i = 0; i < 3; i++) {
        if(haveTheSameValueAndNotEmpty(board[i][0], board[i][1], board[i][2])) {
            return board[i][0] == 'X' ? 2 : -2;
        }
    }

    // For cols
    for(int i = 0; i < 3; i++) {
        if(haveTheSameValueAndNotEmpty(board[0][i], board[1][i], board[2][i])) {
            return board[0][i] == 'X' ? 2 : -2;
        }
    }

    // Diameter 1
    if(haveTheSameValueAndNotEmpty(board[0][0], board[1][1], board[2][2])) {
        return board[0][0] == 'X' ? 2 : -2;
    }

    // Diameter 2
    if(haveTheSameValueAndNotEmpty(board[2][0], board[1][1], board[0][2])) {
        return board[2][0] == 'X' ? 2 : -2;
    }

    bool draw = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                draw = false;
            }
        }
    }
    if(draw) return 0;

    // Else
    return 1;
}



// Return true if 9 moves are done and no winner


