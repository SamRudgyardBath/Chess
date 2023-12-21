#include <humanplayer.hpp>

void HumanPlayer::Update() {
    if (!hasPieceSelected) {
        CheckForPieceSelection();
    }
    if (hasPieceSelected) {
        DragPiece();
    }
}

void HumanPlayer::CheckForPieceSelection() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        for (Piece& piece : pieceList.pieces) {
            // The & above gets a reference to the original, instead of creating a copy!
            if (CheckCollisionPointRec(GetMousePosition(), piece.collider)) {
                if (!piece.isSelected) {
                    piece.isSelected = true;
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
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                PlacePiece(piece);
            }
            if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) {
                CancelPlacement(piece);
            }
        }
    }
}

void HumanPlayer::PlacePiece(Piece& piece) {
    int file = ((piece.position.x - offset) / cellSize);
    int rank = (((2*offset + 8*cellSize) - piece.position.y) / cellSize) - 1;
    piece.squareNumber = 8 * rank + file;
    piece.position = piece.SquareNumberToPosition(piece.squareNumber);

    // Update collision box
    Rectangle newCollisionBox = Rectangle {(float)piece.position.x, (float)piece.position.y, (float)piece.texture.width * piece.drawScale, (float)piece.texture.height * piece.drawScale};
    piece.collider = newCollisionBox;
    piece.isSelected = false;
    hasPieceSelected = false;
}

void HumanPlayer::CancelPlacement(Piece& piece) {
    piece.position = piece.SquareNumberToPosition(piece.squareNumber);
    piece.isSelected = false;
    hasPieceSelected = false;
}