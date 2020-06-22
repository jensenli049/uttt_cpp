#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

char Check_Win(char board[9]);
// Print Board Functions
void Print_Small_Board(char small[9]);
void Print_Main_Board(char main[9][9]);
// Populate Functions
void Populate(char small[9]);
void Unpopulate(char small[9]);
// Set Value Functions
void Reset_Values(char main[9][9], char free[9]);
void Set_Small(char small[9], int index, char player);
bool Check_Unused_Space(char small[9], int index);
void Set_Board_Winner(char main[9][9], char free[9]);
// Set Main Functions
void Set_Main_Board(char main[9][9], char free[9]);
void Set_XOs(char small[9], char letter);