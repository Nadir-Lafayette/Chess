cmake_minimum_required(VERSION 3.10)
project(chess)

set(SOURCES
    src/bitboard.cpp
    src/piece.cpp
    src/attacks.cpp
    src/main.cpp
    
)

add_executable(chess.exe ${SOURCES})