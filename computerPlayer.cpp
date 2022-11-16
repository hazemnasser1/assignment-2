
#include "XO_Classes.h"

int computerPlayer::minimax(Board &b, int depth, bool is_Max, bool firstMove) {
    int res = b.is_winner();
    if(res != 1 || depth == 0){
        return res;
    }
    if(is_Max) {
        int final_score = -INT_MAX;
        int fJ, fI;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (b.board[i][j] == ' ') {
                    b.board[i][j] = 'X';
                    int score = minimax(b, depth - 1, false, false);
                    b.board[i][j] = ' ';
                    if(final_score < score){
                        final_score = score;
                        fI = i;
                        fJ = j;
                    }
                }
            }
        }
        if(firstMove){
            b.board[fI][fJ] = 'O';
        }
        return final_score;
    } else{
        int final_score = INT_MAX;
        int fI, fJ;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (b.board[i][j] == ' ') {
                    b.board[i][j] = 'O';
                    int score = minimax(b, depth - 1, true, false);
                    b.board[i][j] = ' ';
                    if(final_score > score){
                        final_score = score;
                        fI = i;
                        fJ = j;
                    }
                }
            }
        }
        if(firstMove){
            b.board[fI][fJ] = 'O';
        }
        return final_score;
    }
}
