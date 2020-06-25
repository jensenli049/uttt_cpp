#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

// Print Board Functions
void Print_Small_Board(char small[9]);
void Print_Main_Board(char main[9][9]);
// Populate Functions
void Populate(char small[9]);
void Unpopulate(char small[9]);
// Set Value Functions
void Reset_Values(char main[9][9], char free[9]);
void Set_Board_Winner(char main[9][9], char free[9]);
// Set Main Functions
void Set_Main_Board(char main[9][9], char free[9]);
void Set_XOs(char small[9], char letter);
// Check Board Functions
bool Check_Unused_Space(char small[9], int index);
char Check_Win(char board[9]);
// Player Turn
int Player_Turn(char main[9][9], char freebie[9], char current[9], char marker);
// AI Turn
int Evaluate_Board(char freebie[9], char current[9]);
int MiniMax(char main[9][9], char freebie[9], char current[9], bool ai, int score, int depth);
int AI_Turn(char main[9][9], char freebie[9], char current[9], char mode);