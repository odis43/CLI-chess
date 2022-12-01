#include <iostream>
#include <Move.h>
#include <Piece.h>
#include <Tile.h>

using namespace std;

// Constructor
Move::Move(Piece *lastPiece, Piece *currentPiece, Tile *initialTile, Tile *destinationTile, int turn) : lastPiece{lastPiece}, currentPiece{currentPiece}, initialTile{initialTile}, destinationTile{destinationTile}, turn{turn} {}

// Destructor
Move::~Move() {}

