#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include <chessboard.hpp>
#include <piecelist.hpp>

class HumanPlayer {
    public:
        bool hasPieceSelected = false;

        // Constructor
        HumanPlayer(Chessboard& refChessboard, PieceList& refPieceList) : board(refChessboard),  pieceList(refPieceList) {};

        void Update();

        void CheckForPieceSelection();
        
        void DragPiece();

        void PlacePiece(Piece& piece);

        void CancelPlacement(Piece& piece);

    protected:
        Chessboard& board;
        PieceList& pieceList;
};

#endif