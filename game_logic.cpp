#include "game_logic.h"

XOGame::XOGame() {
    reset();
}

void XOGame::reset() {
    for (int i = 0; i < 9; i++) {
        board[i] = '1' + i; // Initialize with '1' to '9'
    }
    moveCount = 0;
    currentPlayer = Player::O; // Start with O, will switch to X on first move
}

bool XOGame::makeMove(int position) {
    if (!isValidMove(position)) {
        return false;
    }
    
    int index = position - 1; // Convert 1-9 to 0-8
    char symbol = (currentPlayer == Player::X) ? 'X' : 'O';
    board[index] = symbol;
    moveCount++;
    
    return true;
}

bool XOGame::isValidMove(int position) const {
    if (position < 1 || position > 9) {
        return false;
    }
    
    int index = position - 1;
    return board[index] == ('1' + index); // Position still shows its number
}

Player XOGame::getCurrentPlayer() const {
    return currentPlayer;
}

GameStatus XOGame::getGameStatus() const {
    if (checkWin('X')) {
        return GameStatus::X_WINS;
    }
    if (checkWin('O')) {
        return GameStatus::O_WINS;
    }
    if (isBoardFull()) {
        return GameStatus::DRAW;
    }
    return GameStatus::ONGOING;
}

char XOGame::getBoardPosition(int index) const {
    if (index >= 0 && index < 9) {
        return board[index];
    }
    return '?';
}

void XOGame::switchPlayer() {
    currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
}

bool XOGame::checkWin(char symbol) const {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i*3] == symbol && board[i*3+1] == symbol && board[i*3+2] == symbol) {
            return true;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == symbol && board[i+3] == symbol && board[i+6] == symbol) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0] == symbol && board[4] == symbol && board[8] == symbol) {
        return true;
    }
    if (board[2] == symbol && board[4] == symbol && board[6] == symbol) {
        return true;
    }
    
    return false;
}

bool XOGame::isBoardFull() const {
    return moveCount >= 9;
}