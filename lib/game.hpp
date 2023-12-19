#ifndef GAME_HPP
#define GAME_HPP

#include <chessboard.hpp>
#include <piecelist.hpp>
#include <fen.hpp>

class Game {
    public:
        Chessboard board = Chessboard(squareDark, squareLight);
        PieceList pieceList;

        // Constructor
        Game();

        // Destructor
        ~Game();

        void Update();

        void Draw();

        void GeneratePieces();

        void SelectPiece();
};

#endif