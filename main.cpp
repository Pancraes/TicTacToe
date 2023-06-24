//////////////////////////////
//// Name: Frederick Chen ////
//// Class: ICS4U1-02     ////
//// Topic: Summative     ////
//// Total Lines: 499     ////
//////////////////////////////

#include <iostream>
#include "ticTacToe.h"
#include "board.h"
#include "player.h"
#include "AIPlayer.h"

using namespace std;


int main() {
  int choice = 1;
  int move;
  TicTacToe ticTacToe;
  AIPlayer ai;

  //main game loop
  while (choice != 3)
  {
    Board board;

    choice = ticTacToe.menu();

    
    //Multiplayer
    
    if (choice == 1)
    {
      cout << "Player 1: X" << endl;
      cout << "Player 2: O" << endl << endl;

      //displays numbered cells from 1-9
      ticTacToe.numberCells();

      //start of game
      for (int i = 0; i < 9; i++)
      {
        int player = i%2+1; //determines which player's turn it is
        cout << "Player " << player << ", ";
        
        do
        {
          if (player == 1)
          {
            //gets the users move and puts it in the board 
            //if it is valid
            move = ticTacToe.player1.getMove(); 
           
            
            if (board.checkMove(move, player) == 2)
              cout << "Cell is already occupied, please enter a valid move." << endl;
            else if (board.checkMove(move, player) == 1)  
              cout << "Please enter a valid move." << endl;
          }
          
            
          else{
            move = ticTacToe.player2.getMove();
            
            if (board.checkMove(move, player) == 2)
              cout << "Cell is already occupied, please enter a valid move." << endl;
            else if (board.checkMove(move, player) == 1)  
              cout << "Please enter a valid move." << endl;
          }
        }//end do
          
          while (board.checkMove(move, player) != 0); 
        //if the user enters an invalid value, 
        //this prompts them to do it again,   
        //this is the while part of the do-while loop

        //sets user's valid move onto the board
        board.setMove(move, player);
        
        //displays the board
        cout << board;

        //check if any player has won
        if (board.checkWin() == 1)
        {
          cout << "Player " << player << " wins!" << endl;
          break;
        }

          //check if the game is tied
        else if (board.checkTie() == 1)
        {
          cout << "It's a tie!" << endl;
          break;
        }
        
      }//end for loop
    }//end multiplayer


    //Playing against AI
      
    else if (choice == 2)
    {
      
      cout << "You: X" << endl;
      cout << "AI: O" << endl << endl;
      
      ticTacToe.numberCells();
  
      //start of game
      for (int i = 0; i < 9; i++)
      {
        //same structure as Multiplayer game
        int player = i%2+1; 

        //player makes move here, same as before
        if (player == 1){
          
          do{
  
          move = ticTacToe.player1.getMove();
            if (board.checkMove(move, player) == 2)
              cout << "Cell is already occupied, please enter a valid move." << endl;
            else if (board.checkMove(move, player) == 1)  
              cout << "Please enter a valid move." << endl;
          }
          
          while (board.checkMove(move, player) != 0); 
          board.setMove(move, player);
        }
          
        //AI makes move here, since it does not make an invalid move, no need for do-while loop
        else
        {
          move = ai.getMove(board);
          board.setMove(move, player);
          cout << "The AI has made its move: " << move;
        }
      
        cout << board;
        if (board.checkWin() == 1)
        {
          if (player == 1){
            cout << "You win!";
            break;
          }
            
          else 
          {
            cout << "You lost.";
            break;
          }
        }
        else if (board.checkTie() == 1)
        {
          cout << "It's a tie!" << endl;
          break;
        }
        
      }//end for loop
      
    }//end AI

    //quit
      
    else if (choice == 3)
    {
      break;
    }
      
    else 
    {
      cout << "Please enter a valid choice" << endl;
    }
  }
  
  cout << "Thank you for using this program!";
}