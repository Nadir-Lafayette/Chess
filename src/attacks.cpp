#include "../include/attacks.hpp"
#include "../include/types.hpp"
#include "../include/bitboard.hpp"

/*
------- NOT A FILE ---------
8  0  1  1  1  1  1  1  1
7  0  1  1  1  1  1  1  1
6  0  1  1  1  1  1  1  1
5  0  1  1  1  1  1  1  1
4  0  1  1  1  1  1  1  1
3  0  1  1  1  1  1  1  1
2  0  1  1  1  1  1  1  1
1  0  1  1  1  1  1  1  1
    a  b  c  d  e  f  g  h

    bitboard = 18374403900871474942d
*/
const U64 not_a_file = 18374403900871474942ULL;

/*
------- NOT B FILE ---------
 8  1  0  1  1  1  1  1  1
 7  1  0  1  1  1  1  1  1
 6  1  0  1  1  1  1  1  1
 5  1  0  1  1  1  1  1  1
 4  1  0  1  1  1  1  1  1
 3  1  0  1  1  1  1  1  1
 2  1  0  1  1  1  1  1  1
 1  1  0  1  1  1  1  1  1
    a  b  c  d  e  f  g  h

    bitboard 18302063728033398269d
*/
const U64 not_b_file = 18302063728033398269ULL;

/*
------- NOT G FILE ---------
 8  1  1  1  1  1  1  0  1
 7  1  1  1  1  1  1  0  1
 6  1  1  1  1  1  1  0  1
 5  1  1  1  1  1  1  0  1
 4  1  1  1  1  1  1  0  1
 3  1  1  1  1  1  1  0  1
 2  1  1  1  1  1  1  0  1
 1  1  1  1  1  1  1  0  1
    a  b  c  d  e  f  g  h

    bitboard 13816973012072644543d
*/
const U64 not_g_file = 13816973012072644543ULL;
/*
    ------- NOT H FILE ---------
    8  1  1  1  1  1  1  1  0
    7  1  1  1  1  1  1  1  0
    6  1  1  1  1  1  1  1  0
    5  1  1  1  1  1  1  1  0
    4  1  1  1  1  1  1  1  0
    3  1  1  1  1  1  1  1  0
    2  1  1  1  1  1  1  1  0
    1  1  1  1  1  1  1  1  0
        a  b  c  d  e  f  g  h

        bitboard 9187201950435737471d
*/
    const U64 not_h_file = 9187201950435737471ULL;

/*
------- NOT A and B FILE ---------
 8  0  0  1  1  1  1  1  1
 7  0  0  1  1  1  1  1  1
 6  0  0  1  1  1  1  1  1
 5  0  0  1  1  1  1  1  1
 4  0  0  1  1  1  1  1  1
 3  0  0  1  1  1  1  1  1
 2  0  0  1  1  1  1  1  1
 1  0  0  1  1  1  1  1  1
    a  b  c  d  e  f  g  h

    bitboard 18229723555195321596d

*/
const U64 not_ab_file = 18229723555195321596ULL;
/*
------- NOT g and h FILE ---------
8  1  1  1  1  1  1  0  0
 7  1  1  1  1  1  1  0  0
 6  1  1  1  1  1  1  0  0
 5  1  1  1  1  1  1  0  0
 4  1  1  1  1  1  1  0  0
 3  1  1  1  1  1  1  0  0
 2  1  1  1  1  1  1  0  0
 1  1  1  1  1  1  1  0  0
    a  b  c  d  e  f  g  h

    bitboard 4557430888798830399d
*/
const U64 not_gh_file = 4557430888798830399ULL;




 // Pawn attck area
U64 pawn_attacks[2][64];
U64 mask_pawn_attacks(int square, int side)
{

    U64 bitboard = 0ULL;
    U64 attacks = 0Ull;
    set_bit(bitboard,square);
    //black pawns
    if(side)
    {
        attacks |= ((bitboard << 7) & not_h_file);
        attacks |= ((bitboard << 9) & not_a_file);
    }
    //white pawns
    else
    {
        attacks |= ((bitboard >> 7) & not_a_file);
        attacks |= ((bitboard >> 9) & not_h_file);
    }
    return attacks;
}

void attack_table_gen()
{

    for (int sqaure = 0; sqaure < 8; sqaure++)
    {
        pawn_attacks[white][sqaure] = mask_pawn_attacks(sqaure,white);
        pawn_attacks[black][sqaure] = mask_pawn_attacks(sqaure, black);
    }
    // for (int i = 0; i < 64; i++)
    // {
    //     print_bitboard(pawn_attacks[white][i]);
    // }
    
}
