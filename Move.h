#ifndef _MOVE_H_
#define _MOVE_H_

class Tile;
class Piece;

class Move {
private:
    Piece *previousPiece;
    Piece *currentPiece;

    Tile *initialTile;
    Tile *destinationTile;

    int turn;

public:
    Move(Piece *previousPiece, Piece *currentPiece, Tile *initialTile, Tile *destinationTile, int turn); // constructor
    ~Move(); // destructor

    Piece *getPreviousPiece(); // get last piece
    Piece *getCurrentPiece(); // get current piece

    Tile *getInitialTile(); // get initial tile
    Tile *getDestinationTile(); // get destination tile

    int getTurn(); // returns turn

    void print(); // prints move info
};

#endif

