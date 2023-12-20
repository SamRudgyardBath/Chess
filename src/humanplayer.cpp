#include <humanplayer.hpp>

void HumanPlayer::Update() {
    CheckForPieceSelection();
}

void HumanPlayer::CheckForPieceSelection() {
    if (hasPieceSelected and IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        for (Piece& piece : pieceList.pieces) {
            // The & above gets a reference to the original, instead of creating a copy!
            if (CheckCollisionPointRec(GetMousePosition(), piece.collider)) {
                if (!piece.isSelected) {
                    bool *pIsSelected = &piece.isSelected;
                    *pIsSelected = true;
                }
            }
        }
    }
}
