#ifndef PIECE_HPP
#define PIECE_HPP

#include <raylib.hpp>

/*  The values used here were found at: https://opensource.com/article/21/8/binary-bit-fields-masks,
*   alongside info for determining the piece type and colour from the resultant binary number.
*/ 
#define EMPTY 0
#define PAWN 1
#define ROOK 2
#define KNIGHT 3
#define BISHOP 4
#define QUEEN 5
#define KING 6
#define PIECE 7
#define PIECE_BLACK 8
#define PIECE_WHITE 0

class Piece {
    public:
        bool isBlack;
        int position;
        int bitValue;
        Texture2D texture;

        // Constructor
        Piece(int position, int bitValue);
};

#endif