#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include <QtCore/QTimer>
#include "game_logic.h"

class XOGameWindow : public QMainWindow {
    Q_OBJECT

private:
    XOGame game;
    QPushButton* buttons[9];
    QLabel* statusLabel;
    QPushButton* resetButton;
    QWidget* centralWidget;

public:
    XOGameWindow(QWidget* parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("XO Game - Tic Tac Toe");
        setFixedSize(400, 500);
        
        setupUI();
        updateDisplay();
    }

private slots:
    void onButtonClicked() {
        QPushButton* button = qobject_cast<QPushButton*>(sender());
        if (!button) return;
        
        // Find which button was clicked
        int position = -1;
        for (int i = 0; i < 9; i++) {
            if (buttons[i] == button) {
                position = i + 1; // Convert 0-8 to 1-9
                break;
            }
        }
        
        if (position == -1) return;
        
        // Switch to next player before making move (to match original game logic)
        game.switchPlayer();
        
        if (game.makeMove(position)) {
            updateDisplay();
            
            GameStatus status = game.getGameStatus();
            if (status != GameStatus::ONGOING) {
                QTimer::singleShot(100, this, [this, status]() {
                    showGameResult(status);
                });
            }
        }
    }
    
    void onResetClicked() {
        game.reset();
        updateDisplay();
    }

private:
    void setupUI() {
        centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        
        QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
        
        // Status label
        statusLabel = new QLabel("Player O's turn", this);
        statusLabel->setAlignment(Qt::AlignCenter);
        statusLabel->setStyleSheet("font-size: 18px; font-weight: bold; margin: 10px;");
        mainLayout->addWidget(statusLabel);
        
        // Game grid
        QWidget* gridWidget = new QWidget();
        QGridLayout* gridLayout = new QGridLayout(gridWidget);
        gridLayout->setSpacing(2);
        
        for (int i = 0; i < 9; i++) {
            buttons[i] = new QPushButton();
            buttons[i]->setFixedSize(100, 100);
            buttons[i]->setStyleSheet(
                "QPushButton {"
                "   font-size: 36px;"
                "   font-weight: bold;"
                "   border: 2px solid #333;"
                "   background-color: #f0f0f0;"
                "}"
                "QPushButton:hover {"
                "   background-color: #e0e0e0;"
                "}"
                "QPushButton:pressed {"
                "   background-color: #d0d0d0;"
                "}"
            );
            
            connect(buttons[i], &QPushButton::clicked, this, &XOGameWindow::onButtonClicked);
            
            int row = i / 3;
            int col = i % 3;
            gridLayout->addWidget(buttons[i], row, col);
        }
        
        mainLayout->addWidget(gridWidget);
        
        // Reset button
        resetButton = new QPushButton("New Game", this);
        resetButton->setStyleSheet("font-size: 16px; padding: 10px; margin: 10px;");
        connect(resetButton, &QPushButton::clicked, this, &XOGameWindow::onResetClicked);
        mainLayout->addWidget(resetButton);
    }
    
    void updateDisplay() {
        // Update button texts
        for (int i = 0; i < 9; i++) {
            char pos = game.getBoardPosition(i);
            if (pos == 'X' || pos == 'O') {
                buttons[i]->setText(QString(pos));
                buttons[i]->setEnabled(false);
                if (pos == 'X') {
                    buttons[i]->setStyleSheet(buttons[i]->styleSheet() + "color: red;");
                } else {
                    buttons[i]->setStyleSheet(buttons[i]->styleSheet() + "color: blue;");
                }
            } else {
                buttons[i]->setText("");
                buttons[i]->setEnabled(true);
            }
        }
        
        // Update status
        GameStatus status = game.getGameStatus();
        switch (status) {
            case GameStatus::ONGOING:
                statusLabel->setText(QString("Player %1's turn")
                    .arg(game.getCurrentPlayer() == Player::X ? "X" : "O"));
                break;
            case GameStatus::X_WINS:
                statusLabel->setText("Player X wins!");
                disableAllButtons();
                break;
            case GameStatus::O_WINS:
                statusLabel->setText("Player O wins!");
                disableAllButtons();
                break;
            case GameStatus::DRAW:
                statusLabel->setText("It's a draw!");
                disableAllButtons();
                break;
        }
    }
    
    void disableAllButtons() {
        for (int i = 0; i < 9; i++) {
            buttons[i]->setEnabled(false);
        }
    }
    
    void showGameResult(GameStatus status) {
        QString message;
        switch (status) {
            case GameStatus::X_WINS:
                message = "Player X wins!\n\nWould you like to play again?";
                break;
            case GameStatus::O_WINS:
                message = "Player O wins!\n\nWould you like to play again?";
                break;
            case GameStatus::DRAW:
                message = "It's a draw!\n\nWould you like to play again?";
                break;
            default:
                return;
        }
        
        QMessageBox::StandardButton reply = QMessageBox::question(
            this, "Game Over", message,
            QMessageBox::Yes | QMessageBox::No
        );
        
        if (reply == QMessageBox::Yes) {
            game.reset();
            updateDisplay();
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    XOGameWindow window;
    window.show();
    
    return app.exec();
}

#include "gui_main.moc"