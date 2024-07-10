#include "../include/bitboard.hpp"
#include <iostream>

int main() {
U64 bitboard = 0ULL;

set_bit(bitboard,a1);
print_bitboard(bitboard);

printf("\n\n\n");
pop_bit(bitboard, a1);
print_bitboard(bitboard);
printf("\n\n\n");
pop_bit(bitboard, a1);
print_bitboard(bitboard);

return 0;
}