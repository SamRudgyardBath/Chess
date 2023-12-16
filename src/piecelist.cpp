#include <piecelist.hpp>

PieceList::~PieceList() {
    for (int i = 0; i < pieces.size(); i++) {
        UnloadTexture(pieces[i].texture);
    }
}

void PieceList::Draw() {
    for (int i = 0; i < pieces.size(); i++) {
        int file = pieces[i].position % 8;
        int rank = trunc(pieces[i].position/8);
        Vector2 topLeftCorner = Vector2 {(float)offset + file*cellSize, (float)offset + (7 - rank)*cellSize};
        Vector2 centering = Vector2 {(float)(cellSize - drawScale * pieces[i].texture.width)/2.f, 0};
        Vector2 position = Vector2Add(topLeftCorner, centering);
        DrawTextureEx(pieces[i].texture, position, 0., (float)drawScale, WHITE);
    }
}