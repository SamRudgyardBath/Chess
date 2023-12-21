#include <game.hpp>

Game::Game() {
    Fen fen;
    LoadedPositionInfo loadedInfo = fen.LoadFromFen(fen.startFen);
    for (int i = 0; i < 64; i++) {
        squares[i] = loadedInfo.squares[i];
    }

    Update();

    InitAudioDevice();
}

Game::~Game() {
    CloseAudioDevice();
}

void Game::Update() {
    pieceList.GeneratePieces(squares);
    player.Update();

    for (int i = 0; i < 64; i++) {
        bool pieceOnThisSquare = false;
        for (Piece piece : pieceList.pieces) {
            if (i == piece.squareNumber) {
                pieceOnThisSquare = true;
                squares[i] = piece.bitValue;
            }
        }
        if (!pieceOnThisSquare) {
            squares[i] = EMPTY;
        }
    }
}

void Game::Draw() {
    board.Draw();
    pieceList.Draw();
}