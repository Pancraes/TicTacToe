#include <iostream>
#include "board.h"
#include <vector>

using namespace std;

//constructor to make the vector board all spaces, sets the vector to be 3x3
Board::Board()
{
  cells.resize(3, vector<string>(3, " "));
  
}//end constructor

//Checks if moves are valid
int Board::checkMove(int move, int player)
{
  if (move < 1 or move > 9) //move is out of rnage
  {
    return 1;
  }
  int row = (move - 1) / 3; //determines row and column number
  int col = (move - 1) % 3;

  if (cells[row][col] == "O" || cells[row][col] == "X") 
    //cell is already occupied
  {
    return 2;
  }
  
  return 0; //cell is valid

}//end checkMove

//puts player's move in the cell
int Board::setMove(int move, int player)
{
  int row = (move - 1)/3; //calculates row number
  int col = (move - 1) % 3; //calculates column number
  
  if (player == 1) 
  {
    cells[row][col] = "X";
    return 0;
  }
    
  else
  {
    cells[row][col] = "O";
    return 0;
  }
}//end setMove

//Checks if a player has won
int Board::checkWin()
{
  if ((cells[0][0] == cells[2][2] and cells[2][2] == cells[1][1] 
      and cells[1][1] != " ") or // checks diagonals
      (cells[2][0] == cells[0][2] and cells[0][2] == cells[1][1] 
      and cells[1][1] != " ") or
      (cells[0][0] == cells[0][1] and cells[0][1] == cells[0][2] 
      and cells[0][0] != " ") or // checks rows
      (cells[1][0] == cells[1][1] and cells[1][1] == cells[1][2] 
      and cells[1][0] != " ") or
      (cells[2][0] == cells[2][1] and cells[2][1] == cells[2][2] 
      and cells[2][0] != " ") or
      (cells[0][0] == cells[1][0] and cells[1][0] == cells[2][0] 
      and cells[0][0] != " ") or // checks columns
      (cells[0][1] == cells[1][1] and cells[1][1] == cells[2][1] 
      and cells[0][1] != " ") or
      (cells[0][2] == cells[1][2] and cells[1][2] == cells[2][2] 
      and cells[0][2] != " "))
    return 1; //win detected
  
  else
    return 0; //no win detected
  
}//end checkWin

//checks if board is full, therefore a tie
int Board::checkTie()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (cells[i][j] == " ")
        return 0; //no tie
    }
  }

  return 1; //tie

}//end checkTie

//overloaded operator to print the board
ostream& operator<< (ostream& out, const Board& b) 
{
  out << endl;

  for (int i = 0; i < 3; i++) {
    out << "+-------+-------+-------+" << endl;
    out << "|       |       |       |" << endl;
    out << "|   ";

    for (int j = 0; j < 3; j++) {
      out << b.cells[i][j] << "   |   "; //displays move here
    }
    out << endl << "|       |       |       |" << endl;
  }
  out << "+-------+-------+-------+" << endl;
  return out;

}//end overloaded operator