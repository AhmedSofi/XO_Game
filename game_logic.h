#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

enum class Player { NONE, X, O };
enum class GameStatus { ONGOING, X_WINS, O_WINS, DRAW };

class XOGame {
private:
    char board[9];  // 0-8 corresponding to positions 1-9
    int moveCount;
    Player currentPlayer;
    
public:
    XOGame();
    void reset();
    bool makeMove(int position); // position 1-9
    bool isValidMove(int position) const;
    Player getCurrentPlayer() const;
    GameStatus getGameStatus() const;
    char getBoardPosition(int index) const; // index 0-8
    void switchPlayer();
    
private:
    bool checkWin(char symbol) const;
    bool isBoardFull() const;
};

#endif // GAME_LOGIC_H