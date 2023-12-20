#include <piecelist.hpp>

PieceList::~PieceList() {
    for (Piece piece : pieces) {
        UnloadTexture(piece.texture);
    }
}

void PieceList::Draw() {
    for (Piece& piece : pieces) {
        piece.Draw();
    }
}

void PieceList::GeneratePieces(Chessboard& board) {
    for (int squareNo = 0; squareNo < 64; squareNo++) {
        int bitValue = board.squares[squareNo];
        if (bitValue != EMPTY) {
            // Check to see if the piece has already been created!
            bool generatePiece = true;
            for (Piece& piece : pieces) {
                if (piece.squareNumber == squareNo) {
                    // There is SOME piece here
                    if (DeterminePiece(bitValue) == DeterminePiece(piece.bitValue)) {
                        // The pieces are the same type..
                        if (IsPieceBlack(bitValue) == IsPieceBlack(piece.bitValue)) {
                            // ...and the pieces are the same colour! i.e. they are the same piece
                            // So don't create another piece
                            generatePiece = false;
                        }
                    }
                }
            }
            if (generatePiece) {
                Piece piece = Piece(squareNo, board.squares[squareNo]);
                pieces.push_back(piece);
            }
        }
    }
}

int PieceList::DeterminePiece(int bitValue) {
    return bitValue & PIECE;
}

bool PieceList::IsPieceBlack(int bitValue) {
    return (bitValue & PIECE_BLACK);
}