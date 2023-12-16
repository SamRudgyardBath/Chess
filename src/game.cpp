#include <game.hpp>

Game::Game() {
    // The piece at a square is represented using a bit-field
    board.squares[0] = PIECE_WHITE | BISHOP;
    board.squares[10] = PIECE_BLACK | QUEEN;
    board.squares[63] = PIECE_WHITE | KING;

    Update();

    InitAudioDevice();
}

Game::~Game() {
    CloseAudioDevice();
}

void Game::Update() {
    for (int squareNo = 0; squareNo < 64; squareNo++) {
        if (board.squares[squareNo] != EMPTY) {
            Piece piece = Piece(squareNo, board.squares[squareNo]);
            pieceList.pieces.push_back(piece);
        }
    }
}

void Game::Draw() {
    board.Draw();
    pieceList.Draw();
}