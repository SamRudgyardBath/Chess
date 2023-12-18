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
    for (int squareNo = 0; squareNo < 64; squareNo++) {
        int bitValue = board.squares[squareNo];
        if (bitValue != EMPTY) {
            // Check to see if the piece has already been created!
            bool generatePiece = true;
            for (int pieceIndex = 0; pieceIndex < pieceList.pieces.size(); pieceIndex++) {
                Piece piece = pieceList.pieces[pieceIndex];
                if (piece.position == squareNo) {
                    // There is SOME piece here
                    if (pieceList.DeterminePiece(bitValue) == pieceList.DeterminePiece(piece.bitValue)) {
                        // The pieces are the same type..
                        if (pieceList.IsPieceBlack(bitValue) == pieceList.IsPieceBlack(piece.bitValue)) {
                            // ...and the pieces are the same colour! i.e. they are the same piece
                            // So don't create another piece
                            generatePiece = false;
                        }
                    }
                }
            }

            if (generatePiece) {
                Piece piece = Piece(squareNo, board.squares[squareNo]);
                pieceList.pieces.push_back(piece);
            }
        }
    }
}

void Game::Draw() {
    board.Draw();
    pieceList.Draw();
}