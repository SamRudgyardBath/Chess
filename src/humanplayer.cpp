#include <humanplayer.hpp>

void HumanPlayer::Update() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
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
