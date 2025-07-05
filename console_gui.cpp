#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "game_logic.h"

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
#endif

class ConsoleGUI {
private:
    XOGame game;
    
public:
    void run() {
        while (true) {
            clearScreen();
            displayGame();
            
            GameStatus status = game.getGameStatus();
            if (status != GameStatus::ONGOING) {
                handleGameEnd(status);
                if (!askPlayAgain()) {
                    break;
                }
                game.reset();
                continue;
            }
            
            if (makePlayerMove()) {
                // Move was successful, continue game loop
            } else {
                // Invalid move, stay in same state
            }
        }
    }
    
private:
    void clearScreen() {
        system(CLEAR_SCREEN);
    }
    
    void displayGame() {
        std::cout << "\n";
        std::cout << "╔═══════════════════════════════════╗\n";
        std::cout << "║            XO GAME GUI            ║\n";
        std::cout << "║          Tic Tac Toe             ║\n";
        std::cout << "╚═══════════════════════════════════╝\n\n";
        
        // Display current player
        Player current = game.getCurrentPlayer();
        std::cout << "Current Player: ";
        if (current == Player::X) {
            std::cout << "\033[31mX\033[0m (Red)\n"; // Red color for X
        } else {
            std::cout << "\033[34mO\033[0m (Blue)\n"; // Blue color for O
        }
        std::cout << "\n";
        
        // Display board with fancy borders
        std::cout << "     │     │     \n";
        displayRow(0);
        std::cout << "─────┼─────┼─────\n";
        displayRow(3);
        std::cout << "─────┼─────┼─────\n";
        displayRow(6);
        std::cout << "     │     │     \n\n";
        
        // Display position guide
        std::cout << "Position Guide:\n";
        std::cout << "  1 │ 2 │ 3  \n";
        std::cout << " ───┼───┼───\n";
        std::cout << "  4 │ 5 │ 6  \n";
        std::cout << " ───┼───┼───\n";
        std::cout << "  7 │ 8 │ 9  \n\n";
    }
    
    void displayRow(int startIndex) {
        std::cout << "  ";
        for (int i = 0; i < 3; i++) {
            char pos = game.getBoardPosition(startIndex + i);
            if (pos == 'X') {
                std::cout << "\033[31m" << pos << "\033[0m"; // Red
            } else if (pos == 'O') {
                std::cout << "\033[34m" << pos << "\033[0m"; // Blue
            } else {
                std::cout << pos;
            }
            
            if (i < 2) std::cout << " │ ";
        }
        std::cout << "  \n";
    }
    
    bool makePlayerMove() {
        game.switchPlayer(); // Switch to next player
        
        std::cout << "Enter position (1-9): ";
        int position;
        std::cin >> position;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\nInvalid input! Please enter a number.\n";
            std::cout << "Press Enter to continue...";
            std::cin.get();
            return false;
        }
        
        if (!game.isValidMove(position)) {
            std::cout << "\nInvalid move! Position must be between 1-9 and available.\n";
            std::cout << "Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
            return false;
        }
        
        return game.makeMove(position);
    }
    
    void handleGameEnd(GameStatus status) {
        std::cout << "\n";
        std::cout << "╔═══════════════════════════════════╗\n";
        switch (status) {
            case GameStatus::X_WINS:
                std::cout << "║           \033[31mX WINS!\033[0m              ║\n";
                break;
            case GameStatus::O_WINS:
                std::cout << "║           \033[34mO WINS!\033[0m              ║\n";
                break;
            case GameStatus::DRAW:
                std::cout << "║            DRAW!                  ║\n";
                break;
            default:
                break;
        }
        std::cout << "╚═══════════════════════════════════╝\n\n";
    }
    
    bool askPlayAgain() {
        std::cout << "Play again? (y/n): ";
        char choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline
        
        return (choice == 'y' || choice == 'Y');
    }
};

int main() {
    ConsoleGUI gui;
    gui.run();
    
    std::cout << "\nThanks for playing XO Game!\n";
    return 0;
}