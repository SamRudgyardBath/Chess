#include <game.hpp>

Game::Game() {
    Fen fen;
    LoadedPositionInfo loadedInfo = fen.LoadFromFen(fen.startFen);
    for (int i = 0; i < 64; i++) {
        board.squares[i] = loadedInfo.squares[i];
    }

    Update();

    InitAudioDevice();
}

Game::~Game() {
    CloseAudioDevice();
}

void Game::Update() {
    pieceList.GeneratePieces(board);
    player.Update();
}

void Game::Draw() {
    board.Draw();
    pieceList.Draw();
}