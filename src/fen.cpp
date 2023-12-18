#include <fen.hpp>

LoadedPositionInfo Fen::LoadFromFen(std::string fen) {
    static LoadedPositionInfo loadedPositionInfo;

    std::string delimiter = " ";

    // Term 1 - Positions of pieces
    std::string boardComponent = fen.substr(0, fen.find(delimiter));
    std::cout << boardComponent << std::endl;
    int file = 0;
    int rank = 7;

    static int squares[64] = {0};

    // Parsing algorithm courtesy of Sebastian Lague (https://github.com/SebLague/Chess-Coding-Adventure/blob/Chess-V1-Unity/Assets/Scripts/Core/FenUtility.cs)
    for (char symbol : boardComponent) {
        if (symbol == '/') {
            // Go to a new row
            file = 0;
            rank--;
        } 
        else {
            if (std::isdigit(symbol)) {
                // Skip this number of squares
                file += (int)symbol;
            }
            else {
                // There is a piece here!
                int pieceColour = 8 * ((std::isupper(symbol)) ? false : true);
                int pieceType = pieceTypeFromSymbol[std::tolower(symbol)];
                squares[rank*8 + file] = pieceType | pieceColour;
                file++;
            }
        }
    }

    for (int i = 0; i < 64; i++) {
        loadedPositionInfo.squares[i] = squares[i];
    }

    // Term 2 - Who's turn is it to move?
    fen.erase(0, boardComponent.length() + delimiter.length());
    std::string colourToMoveComponent = fen.substr(0, fen.find(delimiter));
    std::string whiteMove = "w";
    loadedPositionInfo.whiteToMove = (colourToMoveComponent == whiteMove);

    // Turn 3 - Castling rights
    fen.erase(0, colourToMoveComponent.length() + delimiter.length());
    std::string castlingRightsComponent;
    if (fen.empty()) {
        castlingRightsComponent = "KQkq";
    }
    else {
        castlingRightsComponent = fen.substr(0, fen.find(delimiter));
    }
    loadedPositionInfo.whiteCastleKingSide = castlingRightsComponent.find("K") != std::string::npos;
    loadedPositionInfo.whiteCastleQueenSide = castlingRightsComponent.find("Q") != std::string::npos;
    loadedPositionInfo.blackCastleKingSide = castlingRightsComponent.find("k") != std::string::npos;
    loadedPositionInfo.blackCastleQueenSide = castlingRightsComponent.find("q") != std::string::npos;

    // TODO: Need to sort out hte "- 0 1" parts, plus how to return everything nicely!

    return loadedPositionInfo;
}