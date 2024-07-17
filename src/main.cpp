#include "../include/bitboard.hpp"
#include "../include/attacks.hpp"
#include "../include/types.hpp"
#include <iostream>

int main() {
    U64 bitboard = 0ULL;
    set_bit(bitboard,d3);
    set_bit(bitboard,d8);
    set_bit(bitboard,a4);
    set_bit(bitboard, g4);
    print_bitboard(bitboard);
    print_bitboard(rook_attacks_on_the_fly(d4, bitboard));
   
    return 0;
}