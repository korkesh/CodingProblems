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
    vector<char> row(3, '-');
    vector<vector<char>> board(3,row);
    
    gameBoard = board;
    
    turn = PLAYER1;
    
    moveCount = 0;
    
    computerPlayer = false;
}

CURRENT_TURN TicTacToeGame::getCurrentTurn() {
    return turn;
}

void TicTacToeGame::updateCurrentTurn() {
    turn = ((turn == PLAYER1) ? PLAYER2 : PLAYER1);
}

void TicTacToeGame::printGameBoard() {
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0; j < 3; j++) {
            cout << gameBoard[i][j];
        }
        cout << endl;
    }
}

location TicTacToeGame::updateGameBoard() {
    bool legalmove = false;
    location loc;

    while (!legalmove) {
        if (computerPlayer && turn == PLAYER2) {
            loc = computer->determineNextMove();
        }
        else {
            string player = (turn == PLAYER1) ? "Player1" : "Player2";
            
            cout << player << " make your move:" << endl;
            cin >> loc.first;
            cin >> loc.second;
        }
        
        if (loc.first < 0 || loc.first > 2 || loc.second < 0 || loc.first > 2 || gameBoard[loc.first][loc.second] != '-') {
            if ((computerPlayer && turn == PLAYER1) || !computerPlayer) {
                cout << "Invalid Move." << endl;
            }
            legalmove = false;
        }
        else {
            legalmove = true;
        }
    }
    
    if (turn == PLAYER1) {
        gameBoard[loc.first][loc.second] = 'X';
        computer->setPrevMove(loc);
    }
    else {
        gameBoard[loc.first][loc.second] = 'O';
    }
    
    if (computerPlayer && turn == PLAYER2) {
        cout << "The Computer is Making its Move" << endl;
    }
    
    return loc;
}

STATE TicTacToeGame::getState() {
    return state;
}

void TicTacToeGame::updateMoveCount() {
    moveCount += 1;
}

bool TicTacToeGame::didWin(location loc) {
    
    char player = ((turn == PLAYER1) ? 'O' : 'X');
    
    // Check Rows
    for (int i = 0; i < 3; i++) {
        if (gameBoard[loc.first][i] != player) {
            break;
        }
        if (i == 2) {
            state = WIN;
            return true;
        }
    }
    
    // Check Columns
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][loc.second] != player) {
            break;
        }
        if (i == 2) {
            state = WIN;
            return true;
        }
    }
    
    // Check Diagonal
    if(loc.first == loc.second){
        //we're on a diagonal
        for(int i = 0; i < 3; i++){
            if(gameBoard[i][i] != player)
                break;
            if(i == 2){
                state = WIN;
                return true;
            }
        }
    }
    
    //check anti diag
    for(int i = 0;i<3;i++){
        if(gameBoard[i][2 - i] != player)
            break;
        if(i == 2){
            state = WIN;
            return true;
        }
    }
    
    if (moveCount == 9) {
        state = DRAW;
        return true;
    }
    
    return false;
}

void TicTacToeGame::setComputerPlayer(){
    computerPlayer = !computerPlayer;
}

location TicTacToeGame::determineNextMove() {
    location loc;
    
    srand(time(NULL));
    
    if (true) {
        loc.first = rand() % 3;
        loc.second = rand() % 3;
    }
    //Implement this some day (Current attempt at AI is much too simplistic. Take a look at maxmin on a GameTree
//    else {
//        if (prevMove.first - 1 >= 0 && prevMove.first + 1 <= 2
//            && gameBoard[prevMove.first - 1][prevMove.second] == 'X'
//            && gameBoard[prevMove.first + 1][prevMove.second] != 'X') {
//            loc.first = prevMove.first + 1;
//            loc.second = prevMove.second;
//        }
//        else if (prevMove.second - 1 >= 0 && prevMove.second + 1 <= 2
//                 && gameBoard[prevMove.first][prevMove.second - 1] == 'X'
//                 && gameBoard[prevMove.first][prevMove.second + 1] != 'X') {
//            loc.first = prevMove.first;
//            loc.second = prevMove.second + 1;
//        }
//        else {
//            loc.first = rand() % 3;
//            loc.second = rand() % 3;
//        }
//    }
    
    return loc;
}

void TicTacToeGame::setPrevMove(location loc) {
    prevMove = loc;
}
