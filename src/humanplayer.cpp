#include <humanplayer.hpp>

void HumanPlayer::Update() {
    CheckForPieceSelection();
    if (hasPieceSelected) {
        DragPiece();
    }
}

void HumanPlayer::CheckForPieceSelection() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        for (Piece& piece : pieceList.pieces) {
            // The & above gets a reference to the original, instead of creating a copy!
            if (CheckCollisionPointRec(GetMousePosition(), piece.collider)) {
                if (!piece.isSelected) {
                    bool *pIsSelected = &piece.isSelected;
                    *pIsSelected = true;
                    hasPieceSelected = true;
                }
            }
        }
    }
}

void HumanPlayer::DragPiece() {
    for (Piece& piece : pieceList.pieces) {
        if (piece.isSelected) {
            Vector2 mousePosition = Vector2Subtract(GetMousePosition(), Vector2 {(float)(piece.drawScale * piece.texture.width)/2.f, (float)(piece.drawScale * piece.texture.height)/2.f});
            piece.position = mousePosition;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                PlacePiece(piece);
            }
            if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
                CancelPlacement(piece);
            }
        }
    }
}

void HumanPlayer::PlacePiece(Piece& piece) {
    int file = ((piece.position.x - offset) / cellSize);
    int rank = (((2*offset + 8*cellSize) - piece.position.y) / cellSize) - 1;
    piece.squareNumber = 8 * rank + file;
    Vector2 topLeftCorner = Vector2 {(float)offset + file*cellSize, (float)offset + (7 - rank)*cellSize};
    Vector2 centering = Vector2 {(float)(cellSize - piece.drawScale * piece.texture.width)/2.f, 0};

    piece.position = Vector2Add(topLeftCorner, centering);
    piece.isSelected = false;
    hasPieceSelected = false;
}

void HumanPlayer::CancelPlacement(Piece& piece) {
    piece.position = piece.SquareNumberToPosition(piece.squareNumber);
    piece.isSelected = false;
    hasPieceSelected = false;
}