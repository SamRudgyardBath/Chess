#ifndef GAME_HPP
#define GAME_HPP

#include <chessboard.hpp>
#include <piecelist.hpp>

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
};

#endif