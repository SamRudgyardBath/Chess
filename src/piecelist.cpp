#include <piecelist.hpp>

PieceList::~PieceList() {
    for (Piece piece : pieces) {
        UnloadTexture(piece.texture);
    }
}

void PieceList::Draw() {
    for (Piece& piece : pieces) {
        if (!piece.isSelected) {
            int file = piece.position % 8;
            int rank = trunc(piece.position/8);
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

int PieceList::DeterminePiece(int bitValue) {
    return bitValue & PIECE;
}

bool PieceList::IsPieceBlack(int bitValue) {
    return (bitValue & PIECE_BLACK);
}