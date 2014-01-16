//
//  classTicTacToeGame.cpp
//  CodingProblems
//
//  Created by Matthew Correia on 1/15/2014.
//  Copyright (c) 2014 a. All rights reserved.
//

#include "classTicTacToeGame.h"

using namespace std;

TicTacToeGame::TicTacToeGame() {
    vector<char> row{'-','-','-'};
    vector<vector<char>> board(3,row);
    
    gameBoard = board;
    
    turn = PLAYER1;
}

CURRENT_TURN TicTacToeGame::getCurrentTurn() {
    return turn;
}

void TicTacToeGame::updateCurrentTurn() {
    turn = ((turn == PLAYER1) ? PLAYER2 : PLAYER1);
}

void TicTacToeGame::printGameBoard() {
    
}

void TicTacToeGame::updateGameBoard(location loc) {
    if (turn == PLAYER1) {
        gameBoard[loc.first][loc.second] = 'X';
    }
    else {
        gameBoard[loc.first][loc.second] = 'Y';
    }
}
