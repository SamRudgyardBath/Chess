#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <settings.hpp>
#include <raylib.hpp>

class Chessboard {
    public:
        Color darkColour;
        Color lightColour;
        Color boardColours[64];

        int squares[64] = {0};
    
        // Constructor
        Chessboard(Color darkColour, Color lightColour);

        void Draw();
};

#endif