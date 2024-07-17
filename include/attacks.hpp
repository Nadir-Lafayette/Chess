#ifndef ATTACKS_HPP
#define ATTACKS_HPP
#include "types.hpp"
#include "bitboard.hpp"

U64 mask_pawn_attacks(int square, int side);
U64 mask_knight_attacks(int square);
U64 mask_king_attacks(int square);
U64 mask_bishop_attacks(int square);
U64 mask_rook_attacks(int square);

U64 bishop_attacks_on_the_fly(int square, U64 block);
U64 rook_attacks_on_the_fly(int square,U64 block);

    void attack_table_gen();
#endif