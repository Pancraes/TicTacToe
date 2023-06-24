#include <iostream>
#include "board.h"
#include "player.h"
using namespace std;

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
private:
int choice; //holds user's choice for the mode they would like to play

public:
Player player1, player2; //declaring player1 and player2 as Players

//constructor to create player1 and player2 as Players()(in .cpp file)
TicTacToe();

//main menu for users to navigate program
int menu();

//displays cells numbered 1 to 9
void numberCells();

};//end of class


#endif