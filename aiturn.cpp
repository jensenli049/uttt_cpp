// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Ultimate Tic Tac Toe
// Developer: Jensen Li
// Date: June 22, 2020
// Description: AI Turn Function
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ultimatetictactoe.h"

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
    //printf("Depth: %d\tScore: %d\tAI: %d\n", depth, score, ai);
    // Limit search depth
    if(depth > 4)
        return score;
    
    // Make a copy of current board state
    char temp_main[9][9];
    char temp_freebie[9];
    copy(&main[0][0], &main[9][9], &temp_main[0][0]);
    copy(&freebie[0], &freebie[9], &temp_freebie[0]);
    
    // In the case of a freebie, evaluate every freebie square
    //cout << "Check_Win(current) = " << Check_Win(current) << endl;
    if(Check_Win(current) != ' '){
        for(int i = 0; i < 9; i++){
            if(freebie[i] == ' ' && ai)
                MiniMax(main, freebie, main[i], ai, score-50, depth);
            else if(freebie[i] == ' ')
                MiniMax(main, freebie, main[i], ai, score+50, depth);
        }
    }
    // Normal turn
    if(ai){ // AI Turn
        int best = 9999999;
        for(int i = 0; i < 9; i++){ // Checking all squares
            if(current[i] == ' '){
                current[i] = 'o'; // Make a move
                Set_Board_Winner(main, freebie); // Update board
                //Print_Main_Board(main);
                int value = Evaluate_Board(freebie, current);
                //printf("AI Value: %d\n", value);
                if(value == -1000) return value; // If game is won
                best = min(best, MiniMax(main, freebie, main[i], !ai, score+value, depth+1));
                // Undo the move and its effects
                copy(&temp_main[0][0], &temp_main[9][9], &main[0][0]);
                copy(&temp_freebie[0], &temp_freebie[9], &freebie[0]);
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
                //Print_Main_Board(main);
                int value = Evaluate_Board(freebie, current);
                //printf("Player Value: %d\n", value);
                if(value == 1000) return value; // If game is won
                best = max(best, MiniMax(main, freebie, main[i], !ai, score+value, depth+1));
                // Undo the move and its effects
                copy(&temp_main[0][0], &temp_main[9][9], &main[0][0]);
                copy(&temp_freebie[0], &temp_freebie[9], &freebie[0]);
            }
        }
        return best;
    }
}

int AI_Turn(char main[9][9], char freebie[9], char current[9]){
    int number[9];
    int counter;
    int best_value = 9999999;
    
    // Make a copy of current board state
    char temp_main[9][9];
    char temp_freebie[9];
    copy(&main[0][0], &main[9][9], &temp_main[0][0]);
    copy(&freebie[0], &freebie[9], &temp_freebie[0]);
    
    if(current == freebie) cout << endl << "Freebie:" << endl;
    else cout << endl << "Normal Turn:" << endl;

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
            mvalue = MiniMax(main, freebie, main[i], true, 0, 0);
            // Undo the move and its effects
            copy(&temp_main[0][0], &temp_main[9][9], &main[0][0]);
            copy(&temp_freebie[0], &temp_freebie[9], &freebie[0]);
        }
        // Replace move if it is better
        if(mvalue < best_value){
            best_value = mvalue;
            number[0] = i;
            counter = 1;
        }
        // Keep track of same score
        if(mvalue == best_value)
            number[counter++] = i;
        
        printf("\tThe mvalue for square %d is: %d\n", i+1, mvalue);
    }
    
    int index = number[rand()%counter]; // Return randomized index
    if(current != freebie){ // Do only on a normal turn
        current[index] = 'o'; // Change the picked square to ai marker
        Set_Board_Winner(main, freebie); // Update board
    }
    if(!(Check_Win(main[index]) == ' ')) return -1; // Case of freebie
    
    return index; // Return index for next turn
}