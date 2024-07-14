#include "../include/bitboard.hpp"
#include "../include/attacks.hpp"
#include "../include/types.hpp"
#include <iostream>

int main() {
   // print_bitboard(mask_king_attacks(a1));
   //print_bitboard(mask_bishop_attacks(d5));
   attack_table_gen();
    return 0;
}