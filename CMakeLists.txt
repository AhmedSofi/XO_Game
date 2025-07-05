cmake_minimum_required(VERSION 3.10)
project(XOGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Console version (original)
add_executable(xo_console main.cpp)

# GUI version
add_executable(xo_gui 
    gui_main.cpp 
    game_logic.cpp
)

# Link Qt5 libraries to GUI version
target_link_libraries(xo_gui Qt5::Core Qt5::Widgets)

# Set Qt5 automoc for GUI version
set_target_properties(xo_gui PROPERTIES AUTOMOC ON)