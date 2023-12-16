#ifndef FEN_HPP
#define FEN_HPP

#include <string>
#include <map>
#include <iterator>
#include <piece.hpp>
#include <raylib.hpp>

class Fen {
    public:
        const std::string startFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        std::map<char, int> pieceTypeFromSymbol = {
            {'k', KING},
            {'p', PAWN},
            {'n', KNIGHT},
            {'b', BISHOP},
            {'r', ROOK},
            {'q', QUEEN}
        };
};

#endif