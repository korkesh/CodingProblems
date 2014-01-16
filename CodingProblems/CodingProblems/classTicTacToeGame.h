//
//  classTicTacToeGame.h
//  CodingProblems
//
//  Created by Matthew Correia on 1/15/2014.
//  Copyright (c) 2014 a. All rights reserved.
//

#ifndef __CodingProblems__classTicTacToeGame__
#define __CodingProblems__classTicTacToeGame__

#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int,int> location;

class Computer;

enum CURRENT_TURN {
    PLAYER1 = 0,
    PLAYER2
};

enum STATE {
    WIN = 0,
    LOSE,
    DRAW
};

class TicTacToeGame {
    std::vector<std::vector<char>> gameBoard;
    CURRENT_TURN turn;
    STATE state;
    int moveCount;
    
    Computer *computer;
    bool computerPlayer;
    location prevMove;
    
public:

    TicTacToeGame();
    
    CURRENT_TURN getCurrentTurn();
    void updateCurrentTurn();
    
    void printGameBoard();
    location updateGameBoard();
    
    STATE getState();
    
    void updateMoveCount();
    
    bool didWin(location);
    
    void setComputerPlayer();
    
    location determineNextMove();
    
    void setPrevMove(location);
};

class Computer : public TicTacToeGame {
    

public:

};

#endif /* defined(__CodingProblems__classTicTacToeGame__) */
