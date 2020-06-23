// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Ultimate Tic Tac Toe
// Developer: Jensen Li
// Date: June 22, 2020
// Description: Set Board Functions
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ultimatetictactoe.h"

void Set_Main_Board(char main[9][9], char free[9]){
    string input;
    int number;
    char letter;
    while(true){
        cout << endl;
        cout << "=========================================" << endl;
        cout << "|\t   ***Setting Board***\t\t|" << endl;
        cout << "=========================================" << endl;
        cout << "Current Freebie Board" << endl;
        Populate(free);
        Print_Small_Board(free);
 
        // Actions
        cout << "\nActions:\n\tSet Winner/Tie for a Big Square [w]\n\tChange Small Square [c]\n\tExit [x]\n";
        do{
            cout << "Choose an action: ";
            cin >> input;
            letter = tolower(input.at(0));
        } while ((input.size() > 1) || (letter != 'x' && letter != 'w' && letter != 'c'));
        cout << "=========================================================================" << endl << endl;

        // If User chose to exit
        if(letter == 'x') break;

        // If User chose to change small square
        if(letter == 'c'){
            // Select Square to change
            do{
                cout << "Choose a square: ";
                cin >> input;
                number = input.at(0) - '1';
            } while ((input.size() > 1) || number < 0 || number > 8);
            
            Populate(main[number]);
            Print_Main_Board(main);
            Unpopulate(main[number]);
            Set_XOs(main[number], letter);
        }

        // If User chose to set winner
        if(letter == 'w'){
            Print_Small_Board(free);
            Unpopulate(free);
            Set_XOs(free, letter);        
        }

        // Print Current Main Board
        cout << "=========================================================================" << endl;
        Set_Board_Winner(main, free);
        cout << "\n\nCurrent Main Board" << endl;
        Print_Main_Board(main);
    }
}

void Set_XOs(char small[9], char letter){
    string input;
    int number = 999;

    // Select Square to change to x
    cout << endl << "---------------------------------------------------" << endl;
    cout << "***Use 0 to break/continue***" << endl;
    cout << "Select squares to change to 'x'" << endl;
    while(number > 0){
        do{
            cout << "Choose a square: ";
            cin >> input;
            number = input.at(0) - '0';
        } while ((input.size() > 1) || number < 0 || number > 9);
        if(number > 0)
            small[number - 1] = 'x';
    }

    number = 999;
    // Select Square to change to o
    cout << endl << "---------------------------------------------------" << endl;
    cout << "***Use 0 to break/continue***" << endl;
    cout << "Select squares to change to 'o'" << endl;
    while(number > 0){
        do{
            cout << "Choose a square: ";
            cin >> input;
            number = input.at(0) - '0';
        } while ((input.size() > 1) || number < 0 || number > 9);
        if(number > 0)
            small[number - 1] = 'o';
    }
    
    if(letter == 'w'){
        number = 999;
        // Select Square to change to -
        cout << endl << "---------------------------------------------------" << endl;
        cout << "***Use 0 to break/continue***" << endl;
        cout << "Select squares to change to -" << endl;
        while(number > 0){
            do{
                cout << "Choose a square: ";
                cin >> input;
                number = input.at(0) - '0';
            } while ((input.size() > 1) || number < 0 || number > 9);
            if(number > 0)
                small[number - 1] = '-';
        }
    }
}