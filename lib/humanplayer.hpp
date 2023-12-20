#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include <chessboard.hpp>
#include <piecelist.hpp>

class HumanPlayer {
    public:
        // Constructor
        HumanPlayer(Chessboard& refChessboard, PieceList& refPieceList) : board(refChessboard),  pieceList(refPieceList) {};

        void Update();

    protected:
        Chessboard& board;
        PieceList& pieceList;
};

#endif