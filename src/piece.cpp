#include <piece.hpp>

Piece::Piece(int position, int bitfield) {
    this->position = position;
    this->isBlack = IsPieceBlack(bitfield); 
    int piece = DeterminePiece(bitfield);

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
}

       
int Piece::DeterminePiece(int piece) {
    return piece & PIECE;
}

bool Piece::IsPieceBlack(int piece) {
    return (piece & PIECE_BLACK);
}