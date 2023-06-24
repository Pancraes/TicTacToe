#include <iostream>
#include <cstdlib>

#include "AIPlayer.h"
#include "player.h"
#include "board.h"

int AIPlayer::getMove(Board &board)
{
  for (int i = 1; i <= 9; i++) 
    //checks if AI is able to make a winning move
  {
    if (board.checkMove(i,2) == 0) //checks if move is valid
    {
      board.setMove(i,2); 
      //temporarily makes the move, checks if move wins
      if (board.checkWin() == 1)
      {
        return i;
      }
      
      int row = (i - 1)/3; 
      //reverses the move for it to be made in main
      int col = (i - 1) % 3;

      board.cells[row][col] = " ";
      
    }//end valid move check 
    
  }//end win check for loop

  for (int i = 1; i <= 9; i++) //checks if opponent has any immediate winning moves
  {
    if (board.checkMove(i,1) == 0) //checks if move is valid
    {
      board.setMove(i,1); //temporarily makes the move, 
                          //checks if move wins for opponent
      if (board.checkWin() == 1)
      {
        return i;
      }
      
      int row = (i - 1)/3; //reverses the move for it to be made in main
      int col = (i - 1) % 3;

      board.cells[row][col] = " ";
      
    } //end valid move check 

  }//end loss check for loop
  
  srand (time(NULL));
  
  do //if no cases above apply, AI makes random valid move
  {
    move = rand()%9+1;
  }
    while (board.checkMove(move, 2) != 0);

  return move;
}//end getMove