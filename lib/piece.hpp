#ifndef PIECE_HPP
#define PIECE_HPP

#include <raylib.hpp>
#include <raymath.hpp>
#include <settings.hpp>

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
        int drawScale = 3;
        bool isBlack;
        int squareNumber;
        Vector2 position;
        int bitValue;
        Texture2D texture;
        bool isSelected;
        Rectangle collider;

        // Constructor
        Piece(int squareNumber, int bitValue);

        void Draw();
};

#endif