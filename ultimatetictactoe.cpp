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
    string input;
    char mode;
    bool p1turn;
    
    while(true){
        Reset_Values(main_board, freebie_board);
        
        // Starting and setting up the game
        cout << "=========================================================================" << endl;
        do{
            cout << "Do you want to set the board [y/n]? ";
            cin >> input;
            mode = tolower(input.at(0));
        } while ((input.size() > 1) || (mode != 'y' && mode != 'n'));
        if(mode == 'y') Set_Main_Board(main_board, freebie_board); // Set board

        cout << "=========================================================================" << endl;
        cout << "Modes:\n\t2-Player [p]\n\tAI [a]\n";
        do{
            cout << "Choose a mode: ";
            cin >> input;
            mode = tolower(input.at(0));
        } while ((input.size() > 1) || (mode != 'p' && mode != 'a'));
        
        // 2 Player Mode
        if(mode == 'p'){
            int move = -1;
            while(Check_Win(freebie_board) == ' '){
                if(move == -1){
                    if(p1turn)
                        move = Player_Turn(main_board, freebie_board, freebie_board, 'o');
                    else
                        move = Player_Turn(main_board, freebie_board, freebie_board, 'x');
                }
                else{
                    if(p1turn)
                        move = Player_Turn(main_board, freebie_board, main_board[move], 'o');
                    else
                        move = Player_Turn(main_board, freebie_board, main_board[move], 'x');
                }
                p1turn = !p1turn;
            }
        }

        // AI Mode
        if(mode == 'a') ;

        // Game Over
        cout << endl;
        cout << "=========================================================================" << endl;
        cout << "=========================================================================" << endl;
        Print_Main_Board(main_board);
        char result = Check_Win(freebie_board);
        cout << "Game Over!" << endl;
        switch(result){        
            case 'x':
                cout << "Player 'x' won the game!" << endl;
                break;
            
            case 'o':
                cout << "Player 'o' won the game!" << endl;
                break;
            
            default:
                cout << "Both players have tied!" << endl;
                break;
        }

        // Play again?
        do{
            cout << "Do you want to play again [y/n]? ";
            cin >> input;
            mode = tolower(input.at(0));
        } while ((input.size() > 1) || (mode != 'y' && mode != 'n'));
        if(mode == 'n') break; // Set board
    }

    return 0;
}
