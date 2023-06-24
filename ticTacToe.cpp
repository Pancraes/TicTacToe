#include <iostream>
#include "ticTacToe.h"

using namespace std;

//constructor to initialize player1 and player2 as Players()
TicTacToe::TicTacToe()
{
  player1 = Player();
  player2 = Player();
  
}//end constructor

//main menu for users to navigate program
int TicTacToe::menu() 
{ 
  cout << "\n\n- - - Tic Tac Toe - - -" << endl << endl;
  cout << "1) Multiplayer" << endl;
  cout << "2) AI" << endl;
  cout << "3) Quit" << endl << endl;
  cout << "Enter your choice: ";

  cin >> choice;
  return choice;
  
}//end menu

//displays cells numbered 1 to 9
void TicTacToe::numberCells()
{
  int startCell[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
  //2d array numbered 1-9
  for (int i = 0; i < 3; i++) {
  cout << "+-------+-------+-------+" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|   ";
    for (int j = 0; j < 3; j++) {
      cout << startCell[i][j] << "   |   ";
    }
    cout << endl << "|       |       |       |" << endl;
  }
  cout << "+-------+-------+-------+" << endl;
  
}//end numberCells