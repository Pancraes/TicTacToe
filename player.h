#include <iostream>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

//super class Player
class Player{

//declaring protected member of the class to allow derived classes access

protected:
  int move; //holds player's move

public:

  //creating constructor
  Player(){
    move =0;
  }

  //virtual function to get the player's move, allowing this function to be redefined in AIPlayer
  virtual int getMove(){
    cout << "Enter your move: ";
    cin >> move;
    return move;
  }

};//end of class


#endif