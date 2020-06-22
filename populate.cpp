// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Ultimate Tic Tac Toe
// Developer: Jensen Li
// Date: June 22, 2020
// Description: Populate Board Functions
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ultimatetictactoe.h"

void Populate(char small[9]){
    for(int i = 0; i < 9; i++)
        if(small[i] == ' ')
            small[i] = '1' + i;
}

void Unpopulate(char small[9]){
    for(int i = 0; i < 9; i++)
        if(small[i] > '0' && small[i] <= '9')
            small[i] = ' ';
}