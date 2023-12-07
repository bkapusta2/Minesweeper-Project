cmake_minimum_required(VERSION 3.26)
project(Minesweeper_Project)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(wxWidgets-3.2.4)

add_executable(Minesweeper_Project main.cpp
        lib/src/Cell.cpp
        lib/include/Cell.h
        lib/src/Board.cpp
        lib/include/Board.h
        lib/src/BombCell.cpp
        lib/include/BombCell.h
        lib/src/OpenCell.cpp
        lib/include/OpenCell.h
        lib/src/MinesweeperWindow.cpp
        lib/include/MinesweeperWindow.h
        Testing.cpp)

target_link_libraries(Minesweeper_Project wx::net wx::core wx::base)