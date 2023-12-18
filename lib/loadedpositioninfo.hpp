#ifndef LOADEDPOSITIONINFO_HPP
#define LOADEDPOSITIONINFO_HPP

class LoadedPositionInfo {
    public:
        int squares[64];
        bool whiteToMove;
        bool whiteCastleKingSide;
        bool whiteCastleQueenSide;
        bool blackCastleKingSide;
        bool blackCastleQueenSide;
        int enPassantFile;
        int plyCount;
};

#endif