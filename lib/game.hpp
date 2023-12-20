#ifndef GAME_HPP
#define GAME_HPP

#include <chessboard.hpp>
#include <piecelist.hpp>
#include <humanplayer.hpp>
#include <fen.hpp>

class Game {
    public:
        Chessboard board = Chessboard(squareDark, squareLight);
        PieceList pieceList;
        HumanPlayer player = HumanPlayer(board, pieceList);

        // Constructor
        Game();

        // Destructor
        ~Game();

        void Update();

        void Draw();
};

#endif