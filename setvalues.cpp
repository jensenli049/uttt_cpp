// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Ultimate Tic Tac Toe
// Developer: Jensen Li
// Date: June 22, 2020
// Description: Set Board Functions
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ultimatetictactoe.h"

void Reset_Values(char main[9][9], char free[9]){
    // Reset Main Board
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            main[i][j] = ' ';
    // Reset Main Board
    for(int i = 0; i < 9; i++)
        free[i] = ' ';
}

void Set_Small(char small[9], int index, char player){
    small[index] = player;
}

bool Check_Unused_Space(char small[9], int index){
    if(small[index] != 'x' && small[index] != 'o' && small[index] != '-')
        return true;
    return false;
}

void Set_Board_Winner(char main[9][9], char free[9]){
    Unpopulate(free);
    for(int i = 0; i < 9; i++){
        // If the freebie board was set
        if(free[i] != ' ')  
            for(int j = 0; j < 9; j++)
                main[i][j] = free[i];
        // Check for wins in main board
        char temp = Check_Win(main[i]);
        if(temp != ' ')
            for(int j = 0; j < 9; j++)
                main[i][j] = temp;
        free[i] = temp;
    }
}