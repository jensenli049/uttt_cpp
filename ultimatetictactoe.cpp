// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Ultimate Tic Tac Toe
// Developer: Jensen Li
// Date: June 22, 2020
// Description: Main File
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ultimatetictactoe.h"

int main(){
    char main_board[9][9];
    char freebie_board[9];
    
    Reset_Values(main_board, freebie_board);
    /* cout << endl << endl;
    Print_Main_Board(main_board);
    cout << endl << endl;
    Populate(freebie_board);
    Print_Small_Board(freebie_board); */
    Set_Main_Board(main_board, freebie_board);
}

char Check_Win(char board[9]){
    Unpopulate(board);
    // Column Check
    for(int i = 0; i < 3; i++)
        if((board[i] == board[i+3] && board[i+3] == board[i+6]) && (board[i] == 'x' || board[i] == 'o'))
            return board[i];
    // Row Check
    for(int i = 0; i <= 6; i+=3)
        if((board[i] == board[i+1] && board[i+1] == board[i+2]) && (board[i] == 'x' || board[i] == 'o'))
            return board[i];
    // Diagonal Check
    if(((board[0] == board[4] && board[4] == board[8]) || (board[2] == board[4] && board[4] == board[6])) && (board[4] == 'x' || board[4] == 'o'))
        return board[4];
    // Tie Check
    for(int i = 0; i < 9; i++)
        if(board[i] == ' ')
            return ' ';
    return '-';
}