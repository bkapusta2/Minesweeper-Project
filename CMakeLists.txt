cmake_minimum_required(VERSION 3.26)
project(Minesweeper_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Minesweeper_Project main.cpp
        src/Cell.cpp
        include/Cell.h
        src/Board.cpp
        include/Board.h
        src/BombCell.cpp
        include/BombCell.h
        src/OpenCell.cpp
        include/OpenCell.h)
