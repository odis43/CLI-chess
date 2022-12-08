#include <string>
#include <sstream>
#include <iostream>
#include "Level1.h"
#include "Tile.h"
#include "Piece.h"
#include "Board.h"
#include <vector>

using namespace std;

// Constructor
Level1::Level1(string colour) : AI{colour} {}

// Destructor
Level1::~Level1() {}

// Creates move info to place into a Move object
std::vector<int> Level1::moveCreate() {
    srand(time(0)); // generate seed for rand()
    vector<vector<Tile *>> curBoard = getBoard()->getBoardRef(); // holds a reference to the board
    string input; // will store input provided

    while (getline(cin, input)) {
        istringstream iss(input); // converts string input into input stringstream
        string cmd;
        iss >> cmd; // reads iss into cmd

        if (cmd == "move") { // command provided is called "move"
            vector<Piece *> myPieces; // holds the pieces that belong to this computer, computer will choose a random piece to make a move

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    Piece *myPiece = curBoard.at(i).at(j)->getPiece(); // get each piece in the board
                    
                    if (myPiece && myPiece->getColour() == getColour() && myPiece->getValidMoves().size() != 0) { // if belonging to my colour and existent
                        myPieces.emplace_back(myPiece); // add to my list of available pieces to move
                    }
                }
            }

            if (myPieces.size() == 0) { // check if myPieces even has any pieces
                return vector<int>(); // return empy vector if not
            } 

            while (1) {
                int randomVal = rand() % (myPieces.size() - 1); // generate a random value within the number of pieces in myPieces
                Piece *chosenPiece = myPieces.at(randomVal); // select the random piece with the given index from randomVal

                Tile *initialTile = chosenPiece->getTile(); // this is the tile where the chosen piece is on
                int rowInitialTile = initialTile->getRow(); // get row of this chosen piece's tile
                int colInitialTile = initialTile->getCol(); // get col of this chosen piece's tile

                Tile *destinationTile = chosenPiece->getRandomMove(); // this is the tile where our move will land on
                int rowDestinationTile = destinationTile->getRow(); // get row of the destination tile
                int colDestinationTile = destinationTile->getCol(); // get col of the destination tile

                try { // now let's actually commit to the move
                    initialTile->remove(); // first remove the piece at our initial tile because it is moving
                    Piece *previousPiece = destinationTile->getPiece(); // save the piece of the piece that was previously on the destination tile
                    destinationTile->set(chosenPiece); // because our chosen piece will now live on the destination tile
                    chosenPiece->setTile(destinationTile); // because our chosen piece will belong to destination tile
                    chosenPiece->setNotMoved(false); // because piece has moved
                    
                    // check for an existing captured piece and respond accordingly
                    if (previousPiece) {
                        return vector<int>{previousPiece->getTracker(), chosenPiece->getTracker(), rowInitialTile, colInitialTile, rowDestinationTile, colDestinationTile};
                    } else {
                        return vector<int>{0, chosenPiece->getTracker(), rowInitialTile, colInitialTile, rowDestinationTile, colDestinationTile};
                    }

                    break;

                } catch (const out_of_range &e) {
                    // if no valid move is provided
                    cerr << "Invalid Move. " << e.what() << endl;
                }     
            }
        }
    }
    return vector<int>(); // provide an empty vector
}

