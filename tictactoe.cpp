/*
Author: Joyce Wu
Date: May 11, 2025

Any and all feedback to improve is welcome
Thank you
Hope you have fun playing!
*/

#include <iostream>
#include <cmath>
#include <string>

void grid(int elements[3][3]);

int main () {
    std::cout << "Hi Tuq! Welcome to TicTacToe :)" << std::endl;

    int play = 0;
    int elements[3][3];
    int row;
    int column;
    bool empty; //check if grid has been filled already
    int sums[8] = {0,0,0,0,0,0,0,0}; //store sum of 3 rows, 3 columns, 2 diagonals
    int winner; //record winner of match

    //assign initial value of 7 to allow checking for 3 in row algorithm to work
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            elements[i][j] = 7;
        }
    }

    while (play != 1) {
        std::cout << "Enter 1 to start: ";
        std::cin >> play;
    }

    std::cout << "To fill in the grid, enter the row number, then column number" << std::endl;

    while (play == 1){
        
        grid(elements);

        empty = true;
        winner = 0;

        //ask for player 1 (O) input, ensure spot is not already filled
        while (empty == true) {
            std::cout << "Player 1" << std::endl;
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> column;
            if (elements[row-1][column-1] == 7) {
                elements[row-1][column-1] = 1;
                empty = false;
            }

            else {
                std::cout << "Oops, that spot is already filled, try again!" << std::endl;
            }
        }

        grid(elements);

        for (int i{0}; i<3; i++) {
            for (int j{0}; j<3; j++) {
                sums[i] += elements[i][j];         //sum across rows, store in sums index 0, 1, 2
                sums[i+3] += elements[j][i];       //sum down columns, store in sums index 3, 4, 5
            }
            sums[6] += elements[i][i];             //sum diagonal, store in sums index 6
            sums[7] += elements[2-i][i];
        }

        empty = true;

        for (int i{0}; i<8; i++) {
            if (sums[i] == 3) {
                winner = 1;
                empty = false;
                sums[i] = 0;
            }
            else {
                sums[i] = 0;
            }
        }

        //ask for player 2 (X) input, ensure spot is not already filled
        while (empty == true) {
            std::cout << "Player 2" << std::endl;
            std::cout << "Row: ";
            std::cin >> row;
            std::cout << "Column: ";
            std::cin >> column;
            if (elements[row-1][column-1] == 7) {
                elements[row-1][column-1] = 2;
                empty = false;
            }

            else {
                std::cout << "Oops, that spot is already filled, try again!" << std::endl;
            }
        }

        for (int i{0}; i<3; i++) {
            for (int j{0}; j<3; j++) {
                sums[i] += elements[i][j];         //sum across rows, store in sums index 0, 1, 2
                sums[i+3] += elements[j][i];       //sum down columns, store in sums index 3, 4, 5
            }
            sums[6] += elements[i][i];             //sum diagonal, store in sums index 6
            sums[7] += elements[2-i][i];
        }

        for (int i{0}; i<8; i++) {
            if (sums[i] == 6) {
                winner = 2;
                sums[i] = 0;
            }
            else {
                sums[i] = 0;
            }
        }

        grid(elements);

        if (winner == 1) {
            std::cout << "Player 1 won! Congratulations" << std::endl;
            std::cout << "Play again? Enter 1 for yes and 0 for no: ";
            std::cin >> play;
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    elements[i][j] = 7;
                }
            }
        }

        else if (winner == 2) {
            std:: cout << "Player 2 won! Congratulations" << std::endl;
            std::cout << "Play again? Enter 1 for yes and 0 for no: ";
            std::cin >> play;
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    elements[i][j] = 7;
                }
            }
        }

    }

    return 0;
}

//print tictactoe grid to console, pass elements to be printed inside
void grid (int elements[3][3]) {

    char output[3][3] = {
        {' ',' ',' '}, 
        {' ',' ',' '}, 
        {' ',' ',' '} 
    };

    //convert int elements to char to be printed
    for (int i{0}; i<3; i++){
        for (int j{0}; j<3; j++) {
            if (elements[i][j] == 7) {
                output[i][j] = ' ';
            }
            else if (elements[i][j] == 1) {
                output [i][j] = 'O';
            }
            else {
                output [i][j] = 'X';
            }
        }
    }
 
    std::cout << "|---|---|---|";
    std::cout << std::endl;

    for (int i{0}; i<3; i++) {
        std::cout << "| ";
        for (int j{0}; j<3; j++) {
            std::cout << output [i][j] << " | ";
        }
        std::cout << std::endl;
        std::cout << "|---|---|---|";
        std::cout << std::endl;
    }

}
