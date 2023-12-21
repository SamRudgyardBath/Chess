#ifndef PIECELIST_HPP
#define PIECELIST_HPP

#include <deque>
#include <iostream>
#include <piece.hpp>
#include <raymath.hpp>
#include <settings.hpp>
#include <chessboard.hpp>

using namespace std;

class PieceList {
    public:
        deque<Piece> pieces;
        

        // Destructor
        ~PieceList();

        void Draw();

        void GeneratePieces(int squares[64]);

        /*  Method: DeterminePiece
            Determines the type of piece at the provided index on the board.

            @param bitValue index of the square of interest on the chess board.
            @return the piece's corresponding bit-field integer. 
        */
        int DeterminePiece(int bitValue);

        /*  Method: IsPieceBlack
            Determines whether a piece is black or white.

            @param bitValue index of the square of interest on the chess board.
            @return true if piece is black, false if piece is white.
        */
        bool IsPieceBlack(int bitValue);
};

#endif