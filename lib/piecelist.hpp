#ifndef PIECELIST_HPP
#define PIECELIST_HPP

#include <deque>
#include <piece.hpp>
#include <raymath.hpp>
#include <settings.hpp>

using namespace std;

class PieceList {
    public:
        deque<Piece> pieces;
        int drawScale = 3;

        // Destructor
        ~PieceList();

        void Draw();
};

#endif