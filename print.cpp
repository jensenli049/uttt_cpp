// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Ultimate Tic Tac Toe
// Developer: Jensen Li
// Date: June 22, 2020
// Description: Print Board Functions
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ultimatetictactoe.h"

void Print_Small_Board(char small[9]){
    char s1[43] = "             |             |             \n";
    char s2[43] = "-------------+-------------+-------------\n";
    cout << s1 << s1;
    printf("      %c      |      %c      |      %c      \n", small[0], small[1], small[2]);
    cout << s1 << s1 << s2 << s1 << s1;
    printf("      %c      |      %c      |      %c      \n", small[3], small[4], small[5]);
    cout << s1 << s1 << s2 << s1 << s1;
    printf("      %c      |      %c      |      %c      \n", small[6], small[7], small[8]);
    cout << s1 << s1;
}

void Print_Main_Board(char main[9][9]){
    char DIVIDER1[43] = " ---+---+--- | ---+---+--- | ---+---+--- \n";
	char DIVIDER2[43] = "-------------+-------------+-------------\n";
    
    char temp[81];
    int counter = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                for(int l = 0; l < 3; l++) {
                    temp[counter] = main[i*3 + k][j*3 + l];
                    counter++;
                }
    printf("  %c | %c | %c  |  %c | %c | %c  |  %c | %c | %c  \n", temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8]);
    cout << DIVIDER1;
    printf("  %c | %c | %c  |  %c | %c | %c  |  %c | %c | %c  \n", temp[9], temp[10], temp[11], temp[12], temp[13], temp[14], temp[15], temp[16], temp[17]);
    cout << DIVIDER1;
    printf("  %c | %c | %c  |  %c | %c | %c  |  %c | %c | %c  \n", temp[18], temp[19], temp[20], temp[21], temp[22], temp[23], temp[24], temp[25], temp[26]);
    cout << DIVIDER2;
    printf("  %c | %c | %c  |  %c | %c | %c  |  %c | %c | %c  \n", temp[27], temp[28], temp[29], temp[30], temp[31], temp[32], temp[33], temp[34], temp[35]);
    cout << DIVIDER1;
    printf("  %c | %c | %c  |  %c | %c | %c  |  %c | %c | %c  \n", temp[36], temp[37], temp[38], temp[39], temp[40], temp[41], temp[42], temp[43], temp[44]);
    cout << DIVIDER1;
    printf("  %c | %c | %c  |  %c | %c | %c  |  %c | %c | %c  \n", temp[45], temp[46], temp[47], temp[48], temp[49], temp[50], temp[51], temp[52], temp[53]);
    cout << DIVIDER2;
    printf("  %c | %c | %c  |  %c | %c | %c  |  %c | %c | %c  \n", temp[54], temp[55], temp[56], temp[57], temp[58], temp[59], temp[60], temp[61], temp[62]);
    cout << DIVIDER1;
    printf("  %c | %c | %c  |  %c | %c | %c  |  %c | %c | %c  \n", temp[63], temp[64], temp[65], temp[66], temp[67], temp[68], temp[69], temp[70], temp[71]);
    cout << DIVIDER1;
    printf("  %c | %c | %c  |  %c | %c | %c  |  %c | %c | %c  \n", temp[72], temp[73], temp[74], temp[75], temp[76], temp[77], temp[78], temp[79], temp[80]);
}