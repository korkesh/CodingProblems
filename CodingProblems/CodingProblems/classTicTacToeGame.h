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

enum CURRENT_TURN {
    PLAYER1 = 0,
    PLAYER2 = 1
};

class TicTacToeGame {
    std::vector<std::vector<char>> gameBoard;
    CURRENT_TURN turn;
    
public:
    TicTacToeGame();
    
    CURRENT_TURN getCurrentTurn();
    void updateCurrentTurn();
    
    void printGameBoard();
    void updateGameBoard(location);
};




#endif /* defined(__CodingProblems__classTicTacToeGame__) */
