//
//  TicTacToe.cpp
//  CodingProblems
//
//  Created by Matthew Correia on 1/15/2014.
//  Copyright (c) 2014 a. All rights reserved.
//

#include "TicTacToe.h"

using namespace std;

void endTicTacToe(TicTacToeGame gameInstance) {
    gameInstance.printGameBoard();
    if (gameInstance.getState() == DRAW) {
        cout << "The Game is a Draw!" << endl;
    }
    else {
        gameInstance.updateCurrentTurn();
        cout << ((gameInstance.getCurrentTurn() == PLAYER1) ? "Player1" : "Player2");
        cout << " Wins!" << endl;
    }
    
    char answer;
    cout << "Would you like to play again?<y/n>" << endl;
    cin >> answer;
    
    if (answer == 'y') {
        BeginTicTacToe();
    }
}

void gameLoop(TicTacToeGame gameInstance) {
    bool victory = false;
    
    while (!victory) {
        location loc;
        gameInstance.printGameBoard();
        loc = gameInstance.updateGameBoard();
        gameInstance.updateCurrentTurn();
        gameInstance.updateMoveCount();
        
        victory = gameInstance.didWin(loc);
    }
    
    endTicTacToe(gameInstance);
}

void BeginTicTacToe() {
    TicTacToeGame gameInstance;
    
    int numberOfPlayers;
    
    cout << "Welcome to Tic-Tac-Toe." << endl;
    cout << "To play the game enter a co-ordinate to make your move." << endl;
    cout << "1 or 2 players?" << endl;
    cin >> numberOfPlayers;
    
    if (numberOfPlayers == 1) {
        gameInstance.setComputerPlayer();
    }
    
    gameLoop(gameInstance);
}