#include <piece.hpp>

Piece::Piece(int squareNumber, int bitValue) {
    this->squareNumber = squareNumber;
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

    Vector2 xy = SquareNumberToPosition(squareNumber);
    this->position = xy;
    Rectangle collisionBox = Rectangle {(float)xy.x, (float)xy.y, (float)texture.width * drawScale, (float)texture.height * this->drawScale};
    this->collider = collisionBox;


}

void Piece::Draw() {
    DrawTextureEx(texture, position, 0., (float)drawScale, WHITE);
}

Vector2 Piece::SquareNumberToPosition(int squareNumber) {
    int file = squareNumber % 8;
    int rank = trunc(squareNumber/8);
    Vector2 topLeftCorner = Vector2 {(float)offset + file*cellSize, (float)offset + (7 - rank)*cellSize};
    Vector2 centering = Vector2 {(float)(cellSize - drawScale * texture.width)/2.f, 0};
    return Vector2Add(topLeftCorner, centering);
}