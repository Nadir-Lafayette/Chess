/*
This File contains important types for this project.
*/

#ifndef TYPES_HPP_INCLUDE
#define TYPES_HPP_INCLUDE
//This is used for making bit boards
#define U64 unsigned long long

//size of the board
const int board_size = 64;

// The diffrent colors for attacking
enum {
    white,
    black,
    none =2
};
#endif