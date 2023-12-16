#include <chessboard.hpp>

Chessboard::Chessboard(Color darkColour, Color lightColour) {
    this->darkColour = darkColour;
    this->lightColour = lightColour;
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            bool isLightSquare = (rank + file) % 2 != 0;
            boardColours[rank*8 + file] = (isLightSquare) ? lightColour : darkColour;
        }
    }
}

void Chessboard::Draw() {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            Vector2 position = Vector2 {(float)offset + file*cellSize, (float)offset + (7 - rank)*cellSize};
            DrawRectangle(position.x, position.y, cellSize, cellSize, boardColours[rank*8 + file]);
        }
    }
}