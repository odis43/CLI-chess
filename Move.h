#ifndef _MOVE_H_
#define _MOVE_H_

class Tile;
class Piece;

class Move {
private:
    Piece *lastPiece;
    Piece *currentPiece;

    Tile *initialTile;
    Tile *destinationTile;

    int turn;

public:
    Move(Piece *lastPiece, Piece *currentPiece, Tile *initialTile, Tile *destinationTile, int turn); // constructor
    ~Move(); // destructor

    Piece *getLastPiece(); // get last piece
    Piece *getCurrentPiece(); // get current piece

    Tile *getInitialTile(); // get initial tile
    Tile *getDestinationTile(); // get destination tile

    int getTurn(); // returns turn

    void print(); // prints move info
};

#endif

