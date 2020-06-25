// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Ultimate Tic Tac Toe
// Developer: Jensen Li
// Date: June 22, 2020
// Description: Player Turn Function
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ultimatetictactoe.h"

int Player_Turn(char main[9][9], char freebie[9], char current[9], char marker){
    string input;
    int number;

    cout << endl << "=========================================================================" << endl;
    printf("It is Player %c's turn to move!\n", marker);
    // If the player has a freebie
    if(current == freebie){
        // Print board for player to choose
        cout << "You have a freebie!" << endl;
        Populate(current);
        Print_Small_Board(current);
        Unpopulate(current);
        // Player input
        do{
            cout << "Choose a numbered square: ";
            cin >> input;
            number = input.at(0) - '1';
        } while ((input.size() > 1) || number < 0 || number > 8 || !Check_Unused_Space(current, number));
        current = main[number]; // Change current board to one in the main board
        cout << endl << "=========================================================================" << endl;
    }
    //Normal Turn
    // Print board for player to choose
    cout << "Current Board" << endl;
    Populate(current);
    Print_Main_Board(main);
    Unpopulate(current);
    // Player input
    do{
        cout << "Choose a numbered square: ";
        cin >> input;
        number = input.at(0) - '1';
    } while ((input.size() > 1) || number < 0 || number > 8 || !Check_Unused_Space(current, number));
    
    current[number] = marker; // Change the picked square to player marker
    Set_Board_Winner(main, freebie); // Update board

    if(!(Check_Win(main[number]) == ' ')) return -1; // Update board

    return number; // Return index for next turn
}