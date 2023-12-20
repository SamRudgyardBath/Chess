#include <piece.hpp>

Piece::Piece(int position, int bitValue) {
    this->squareNumber = position;
    this->bitValue = bitValue;
    /*  The following is a bit clunky, as we should really be resuing the Piecelist::DeterminePiece()
    *   and Piecelist::IsPieceBlack() functions... so,
    *   TODO: Reformat code so that can reuse functions for these!
    */
    this->isBlack = bitValue & PIECE_BLACK; 
    int piece = bitValue & PIECE; 

    Image image;
    if (isBlack) {
        if (piece == PAWN) {
            image = LoadImage("src/assets/black_pawn.png");
        }
        else if (piece == ROOK) {
            image = LoadImage("src/assets/black_rook.png");
        }
        else if (piece == KNIGHT) {
            image = LoadImage("src/assets/black_knight.png");
        }
        else if (piece == BISHOP) {
            image = LoadImage("src/assets/black_bishop.png");
        }
        else if (piece == QUEEN) {
            image = LoadImage("src/assets/black_queen.png");
        }
        else {
            image = LoadImage("src/assets/black_king.png");
        }
    }
    else {
        if (piece == PAWN) {
            image = LoadImage("src/assets/white_pawn.png");
        }
        else if (piece == ROOK) {
            image = LoadImage("src/assets/white_rook.png");
        }
        else if (piece == KNIGHT) {
            image = LoadImage("src/assets/white_knight.png");
        }
        else if (piece == BISHOP) {
            image = LoadImage("src/assets/white_bishop.png");
        }
        else if (piece == QUEEN) {
            image = LoadImage("src/assets/white_queen.png");
        }
        else {
            image = LoadImage("src/assets/white_king.png");
        }
    }
    this->texture = LoadTextureFromImage(image);
    UnloadImage(image);

    this->isSelected = false;
    int file = position % 8;
    int rank = trunc(position/8);
    Vector2 topLeftCorner = Vector2 {(float)offset + file*cellSize, (float)offset + (7 - rank)*cellSize};
    Vector2 centering = Vector2 {(float)(cellSize - this->drawScale * this->texture.width)/2.f, 0};
    Vector2 xy = Vector2Add(topLeftCorner, centering);
    Rectangle collisionBox = Rectangle {(float)xy.x, (float)xy.y, (float)this->texture.width * this->drawScale, (float)this->texture.height * this->drawScale};
    this->collider = collisionBox;
}

       
