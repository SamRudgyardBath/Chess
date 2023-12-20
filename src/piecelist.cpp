#include <piecelist.hpp>

PieceList::~PieceList() {
    for (Piece piece : pieces) {
        UnloadTexture(piece.texture);
    }
}

void PieceList::Draw() {
    for (Piece& piece : pieces) {
        if (!piece.isSelected) {
            int file = piece.squareNumber % 8;
            int rank = trunc(piece.squareNumber/8);
            Vector2 topLeftCorner = Vector2 {(float)offset + file*cellSize, (float)offset + (7 - rank)*cellSize};
            Vector2 centering = Vector2 {(float)(cellSize - piece.drawScale * piece.texture.width)/2.f, 0};
            Vector2 position = Vector2Add(topLeftCorner, centering);
            DrawTextureEx(piece.texture, position, 0., (float)piece.drawScale, WHITE);
        }
        if (piece.isSelected) {
            Vector2 mousePosition = Vector2Subtract(GetMousePosition(), Vector2 {(float)(piece.drawScale * piece.texture.width)/2.f, (float)(piece.drawScale * piece.texture.height)/2.f});
            DrawTextureEx(piece.texture, mousePosition, 0., (float)piece.drawScale, WHITE);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                int file = ((mousePosition.x - offset) / cellSize);
                int rank = (((2*offset + 8*cellSize) - mousePosition.y) / cellSize) - 1;
                piece.position = 8 * rank + file;
                piece.isSelected = false;
            }
        }
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