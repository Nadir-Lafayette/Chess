#include "../include/bitboard.hpp"
#include "../include/attacks.hpp"
#include "../include/types.hpp"
#include <iostream>

int main() {
    print_bitboard(mask_knight_attacks(a4));

    return 0;
}