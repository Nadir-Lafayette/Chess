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




 // Pawn attck table Needs two be 2 for white and black as pawns act diffrently.
U64 pawn_attacks[2][64];

// Knight attack table
U64 knight_attacks[64];

//King attack table
U64 king_attacks[64];

//bishop attacks table
U64 bishop_attacks[64];

//rook attacks table
U64 rook_attacks[64];

void attack_table_gen()
{

    for (int sqaure = 0; sqaure < 64; sqaure++)
    {
        pawn_attacks[white][sqaure] = mask_pawn_attacks(sqaure, white);
        pawn_attacks[black][sqaure] = mask_pawn_attacks(sqaure, black);
        knight_attacks[sqaure] = mask_knight_attacks(sqaure);
        king_attacks[sqaure] = mask_king_attacks(sqaure);
        bishop_attacks[sqaure] = mask_bishop_attacks(sqaure);
        rook_attacks[sqaure] = mask_rook_attacks(sqaure);
    }
    for (int i = 0; i < 64; i++)
    {
        print_bitboard(rook_attacks[i]);
    }
}

/*
This mask make it so we can makeall possible attacks for the pawns.
*/
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

/*
This mask make it so we can makeall possible attacks for the knights.
knight offset = 6 ,10, 15,17
*/
U64 mask_knight_attacks(int square){
    U64 bitboard = 0ULL;
    U64 attacks = 0ULL;
    set_bit(bitboard, square);
    attacks |= (bitboard >> 17) & not_h_file;
    attacks|= (bitboard >> 15) & not_a_file;
    attacks |= (bitboard >> 10) & not_gh_file;
    attacks |= (bitboard >> 6) & not_ab_file;


    attacks |= (bitboard << 17) & not_a_file;
    attacks |= (bitboard << 15) & not_h_file;
    attacks |= (bitboard << 10) & not_ab_file;
    attacks |= (bitboard << 6) & not_gh_file;

    return attacks;
}
U64 mask_king_attacks(int square){
    U64 bitboard = 0ULL;
    U64 attacks = 0ULL;
    set_bit(bitboard, square);

    //north
    attacks |= (bitboard >> 8);
    //south
    attacks |= (bitboard << 8);
    //east
    attacks |= (bitboard << 1) & not_a_file;

    //west
    attacks |= (bitboard >> 1) & not_h_file;

    //going North west
    attacks |= ((bitboard << 7) & not_h_file);
    //going north east
    attacks |= ((bitboard << 9) & not_a_file);
    //going south west
    attacks |= ((bitboard >> 7) & not_a_file);
    //going south east
    attacks |= ((bitboard >> 9) & not_h_file);

    return attacks;
}

U64 mask_bishop_attacks(int square)
{
    U64 bitboard = 0ULL;
    U64 attacks = 0ULL;
    set_bit(bitboard, square);
    int rank;
    int file;
    int target_rank = square / 8;
    int target_file = square % 8;
    //Going southeast
    for(rank = target_rank +1, file = target_file +1; (rank < 7 && file < 7); rank++,file++)
    {
        attacks |= (1ULL << (rank * 8 +file));
    }
    //going north east
    for (rank = target_rank-1, file = target_file + 1; (rank > 0 && file < 7); rank--, file++)
    {
        attacks |= (1ULL << (rank * 8 + file));
    }
    //going south west
    for (rank = target_rank + 1, file = target_file - 1; (rank < 7 && file > 0); rank++, file--)
    {
        attacks |= (1ULL << (rank * 8 + file));
    }
    //going northwest
    for (rank = target_rank - 1, file = target_file - 1; (rank > 0 && file > 0); rank--, file--)
    {
        attacks |= (1ULL << (rank * 8 + file));
    }
    return attacks;
}

U64 mask_rook_attacks(int square)
{
    U64 bitboard = 0ULL;
    U64 attacks = 0ULL;
    set_bit(bitboard, square);
    int rank;
    int file;
    int target_rank = square / 8;
    int target_file = square % 8;
    // Going southeast
    //south
    for (rank = target_rank + 1; rank < 7; rank++)
    {
        attacks |= (1Ull<< (rank * 8 + target_file));
    }

    //north
    for (rank = target_rank - 1; rank > 0; rank--)
    {
        attacks |= (1Ull << (rank * 8 + target_file));
    }
    //east
    for (file= target_file + 1; file < 7; file++)
    {
        attacks |= (1Ull << (target_rank * 8 + file));
    }
    //west
    for (file = target_file - 1; file > 0; file--)
    {
        attacks |= (1Ull << (target_rank * 8 + file));
    }

    return attacks;
}

U64 bishop_attacks_on_the_fly(int square,U64 block)
{
    U64 bitboard = 0ULL;
    U64 attacks = 0ULL;
    set_bit(bitboard, square);
    int rank;
    int file;
    int target_rank = square / 8;
    int target_file = square % 8;
    // Going southeast
    for (rank = target_rank + 1, file = target_file + 1; (rank <= 7 && file <= 7); rank++, file++)
    {
        attacks |= (1ULL << (rank * 8 + file));
        if ((1ULL << (rank * 8 + file)) & block)
        { 
            break;
        }
    }
    // going north east
    for (rank = target_rank - 1, file = target_file + 1; (rank >= 0 && file <= 7); rank--, file++)
    {
        attacks |= (1ULL << (rank * 8 + file));
        if ((1ULL << (rank * 8 + file)) & block)
        {
            break;
        }
    }
    // going south west
    for (rank = target_rank + 1, file = target_file - 1; (rank <= 7 && file >= 0); rank++, file--)
    {
        attacks |= (1ULL << (rank * 8 + file));
        if ((1ULL << (rank * 8 + file)) & block)
        {
            break;
        }
    }
    // going northwest
    for (rank = target_rank - 1, file = target_file - 1; (rank >= 0 && file >= 0); rank--, file--)
    {
        attacks |= (1ULL << (rank * 8 + file));
        if ((1ULL << (rank * 8 + file)) & block)
        {
            break;
        }
    }
    return attacks;
}

U64 rook_attacks_on_the_fly(int square,U64 block)
{
    U64 bitboard = 0ULL;
    U64 attacks = 0ULL;
    set_bit(bitboard, square);
    int rank;
    int file;
    int target_rank = square / 8;
    int target_file = square % 8;
    // Going southeast
    // south
    for (rank = target_rank + 1; rank <= 7; rank++)
    {
        attacks |= (1Ull << (rank * 8 + target_file));
        if ((1ULL << (rank * 8 + target_file)) & block)
        {
            break;
        }
    }

    // north
    for (rank = target_rank - 1; rank >= 0; rank--)
    {
        attacks |= (1Ull << (rank * 8 + target_file));
        if ((1ULL << (rank * 8 + target_file)) & block)
        {
            break;
        }
    }
    // east
    for (file = target_file + 1; file <= 7; file++)
    {
        attacks |= (1Ull << (target_rank * 8 + file));
        if (1Ull << (target_rank * 8 + file)& block)
        {
            break;
        }
    }
    // west
    for (file = target_file - 1; file >= 0; file--)
    {
        attacks |= (1Ull << (target_rank * 8 + file));
        if (1Ull << (target_rank * 8 + file) & block)
        {
            break;
        }
    }

    return attacks;
}