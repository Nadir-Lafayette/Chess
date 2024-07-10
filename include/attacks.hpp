#ifndef ATTACKS_HPP
#define ATTACKS_HPP
#include "types.hpp"
#include "bitboard.hpp"

U64 mask_pawn_attacks(int square, int side);
void attack_table_gen();
#endif