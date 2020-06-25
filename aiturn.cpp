// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Ultimate Tic Tac Toe
// Developer: Jensen Li
// Date: June 22, 2020
// Description: AI Turn Function
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ultimatetictactoe.h"

/*
AI is 'o'
Check freebie
Check valid places
Place piece
Evaluate minimax
Recursive minimax
*/

int Evaluate_Board(char freebie[9], char current[9]){
    // Checks for game over
    switch (Check_Win(freebie)){
        case 'x':   return 1000;
        case 'o':   return -1000;
        default:    break;
    }
    // Checks if the current board is won
    switch (Check_Win(current)){
        case 'x':   return 100;
        case 'o':   return -100;
        default:    return 0;
    }
    return 0;
}

int MiniMax(char main[9][9], char freebie[9], char current[9], bool ai, int score, int depth){
    // Limit search depth
    if(depth > 3)
        return score;
    
    // Make a copy of current board state
    char temp_main[9][9];
    char temp_freebie[9];
    copy(&main, &main+81, temp_main);
    copy(&freebie, &freebie+9, temp_freebie);

    // In the case of a freebie, evaluate every freebie square
    if(Check_Win(current) != ' ')
        for(int i = 0; i < 9; i++){
            if(freebie[i] == ' ' && ai)
                MiniMax(main, freebie, main[i], ai, score-50, depth);
            else
                MiniMax(main, freebie, main[i], ai, score+50, depth);
        }
    
    // Normal turn
    if(ai){ // AI Turn
        int best = 9999999;
        for(int i = 0; i < 9; i++){ // Checking all squares
            if(current[i] == ' '){
                current[i] = 'o'; // Make a move
                Set_Board_Winner(main, freebie); // Update board
                int value = Evaluate_Board(freebie, current);
                if(value == -1000) return value; // If game is won
                best = min(best, MiniMax(main, freebie, main[i], !ai, score+value, depth++));
                // Undo the move and its effects
                copy(&temp_main, &temp_main+81, main);
                copy(&temp_freebie, &temp_freebie+9, freebie);
            }
        }
        return best;
    }
    else{ // Player Turn
        int best = -9999999;
        for(int i = 0; i < 9; i++){ // Checking all squares
            if(current[i] == ' '){
                current[i] = 'x'; // Make a move
                Set_Board_Winner(main, freebie); // Update board
                int value = Evaluate_Board(freebie, current);
                if(value == 1000) return value; // If game is won
                best = max(best, MiniMax(main, freebie, main[i], !ai, score+value, depth++));
                // Undo the move and its effects
                copy(&temp_main, &temp_main+81, main);
                copy(&temp_freebie, &temp_freebie+9, freebie);
            }
        }
        return best;
    }
}

int AI_Turn(char main[9][9], char freebie[9], char current[9], char mode){
    srand(time(NULL));
    string number;
    int counter;
    int best_value = 9999999;
    
    // Make a copy of current board state
    char temp_main[9][9];
    char temp_freebie[9];
    copy(&main, &main+81, temp_main);
    copy(&freebie, &freebie+9, temp_freebie);

    
    for(int i = 0; i < 9; i++){ // Checking all squares
        int mvalue = best_value+1;
        // Case of freebie
        if(current == freebie)
            mvalue = MiniMax(main, freebie, main[i], true, 0, 0);
        // Normal Turn
        else if(current[i] == ' '){
            current[i] = 'o'; // Make a move
            Set_Board_Winner(main, freebie); // Update board
            if(Evaluate_Board(freebie, current) == -1000) return -1000; // If game is won
            mvalue = MiniMax(main, freebie, main[i], false, 0, 0);
            // Undo the move and its effects
            copy(&temp_main, &temp_main+81, main);
            copy(&temp_freebie, &temp_freebie+9, freebie);
        }
        // Replace move if it is better
        if(mvalue < best_value){
            best_value = mvalue;
            number = i;
            counter = 1;
        }
        // Keep track of same score
        if(mvalue == best_value){
            number += ('0' + i);
            counter++;
        }
    }
    // Return randomized index
    return number[rand()%counter];
}