#include <iostream>
#include "Move.h"
#include "Piece.h"
#include "Tile.h"

using namespace std;

// Constructor
Move::Move(Piece *previousPiece, Piece *currentPiece, Tile *initialTile, Tile *destinationTile, int turn) : previousPiece{previousPiece}, currentPiece{currentPiece}, initialTile{initialTile}, destinationTile{destinationTile}, turn{turn} {}

// Destructor
Move::~Move() {}

// Get previousPiece
Piece *Move::getPreviousPiece() { return previousPiece; }

// Get currentPiece
Piece *Move::getCurrentPiece() { return currentPiece; }

// Get initialTile
Tile *Move::getInitialTile() { return initialTile; }

// Get destinationTile
Tile *Move::getDestinationTile() { return destinationTile; }

// Get turn
int Move::getTurn() { return turn; }

// Prints move object info
void Move::print() {
    cout << endl;
    cout << "Turn: " << turn << endl; // print current turn
    cout << endl;
    cout << "Current Piece: "; // print current piece
    currentPiece->print();
    cout << " " << currentPiece->getVal() << endl; // print relevant value to current piece
    cout << "Previous Piece: "; // print current piece
    previousPiece->print();
    cout << " " << previousPiece->getVal() << endl; // print relevant value to previous piece
    cout << "Initial Tile: " << initialTile->getRow() << " " << initialTile->getCol() << endl; // print out initialTile info
    cout << "Destination Tile: " << destinationTile->getRow() << " " << destinationTile->getCol() << endl; // print out destinationTile info
    cout << endl;
}

