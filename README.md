# XO Game - Tic Tac Toe

A classic Tic Tac Toe game with multiple GUI implementations.

## Features

- **Original Console Version**: Text-based gameplay in terminal
- **Enhanced Console GUI**: Beautiful ASCII art interface with colors
- **Web GUI**: Modern browser-based interface with click-to-play
- **Qt GUI**: Native desktop application (requires Qt5)

## Screenshots

### Web GUI
![Web GUI Initial](https://github.com/user-attachments/assets/e6da33eb-8a4c-4798-b92e-f80ab7ce1536)
*Initial game state*

![Web GUI Gameplay](https://github.com/user-attachments/assets/ac224f37-8b32-480f-ad33-08e5efe7aa6f)
*Game in progress showing colored X and O pieces*

## Building and Running

### Prerequisites

- C++ compiler with C++17 support
- Make (optional, for easier building)
- Qt5 development libraries (optional, for Qt GUI)
- Web browser (for web GUI)
- Python 3 (optional, for serving web GUI)

### Quick Start

1. **Build all available versions:**
   ```bash
   make all
   ```

2. **Run the enhanced console GUI:**
   ```bash
   ./xo_console_gui
   ```

3. **Run the web GUI:**
   ```bash
   # Start a simple web server
   python3 -m http.server 8080
   # Open browser and navigate to: http://localhost:8080/gui.html
   ```

### Individual Build Commands

#### Console Versions
```bash
# Original console version
make console
./xo_console

# Enhanced console GUI with beautiful formatting
make console-gui
./xo_console_gui
```

#### Web GUI
No building required! Simply open `gui.html` in any modern web browser, or serve it via HTTP:
```bash
python3 -m http.server 8080
# Then open: http://localhost:8080/gui.html
```

#### Qt GUI (requires Qt5)
```bash
# Install Qt5 first (Ubuntu/Debian):
sudo apt install qtbase5-dev

# Then build:
make qt-gui
./xo_qt_gui
```

#### Using CMake
```bash
mkdir build && cd build
cmake ..
make
```

## Game Rules

- Players alternate turns placing X and O on a 3x3 grid
- Player O goes first
- First player to get 3 in a row (horizontally, vertically, or diagonally) wins
- If all 9 squares are filled with no winner, it's a draw
- Click "New Game" or restart to play again

## File Structure

- `main.cpp` - Original console implementation
- `console_gui.cpp` - Enhanced console GUI with colors and borders
- `gui.html` - Web-based GUI (HTML/CSS/JavaScript)
- `game_logic.h/.cpp` - Reusable game logic class
- `gui_main.cpp` - Qt5 desktop GUI
- `Makefile` - Build configuration
- `CMakeLists.txt` - CMake build configuration

## Development

The game logic has been extracted into a reusable `XOGame` class that can be easily integrated into different UI frameworks. All GUI implementations use the same core game logic to ensure consistent behavior.
