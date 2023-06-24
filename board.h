#include <iostream>
#include <vector>

using namespace std;

#ifndef BOARD_H
#define BOARD_H

class Board{
  public:
  vector<vector<string>> cells; 
  //creates a 2d vector named cells for type string

  //constructor to make the vector board all spaces (in .cpp file)
  Board();

  //Checks if moves are valid
  int checkMove(int move, int player);

  //puts player's move in the cell
  int setMove(int move, int player);

  //Checks if a player has won
  int checkWin();

  //checks if board is full, therefore a tie
  int checkTie();

  //overloaded operator to print the board
  friend ostream& operator<< (ostream& out, const Board& b);

};//end of class


#endif