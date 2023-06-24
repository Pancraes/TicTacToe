#include <iostream>
#include "player.h"
#include "board.h"

#ifndef AIPLAYER_H
#define AIPLAYER_H

//creating a derived class under Player
class AIPlayer: public Player
{
public:

  //creating the constructor using polymorphism 
  //by calling constructor from Player
  AIPlayer() : Player(){}

  //generated algorithm made move
  int getMove(Board &board);

};//end of class


#endif