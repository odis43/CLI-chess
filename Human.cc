#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Human.h"
#include "Tile.h"
#include "Board.h"

using namespace std;

// Constructor
Human::Human(string colour) : Player{colour} {}

// Destructor
Human::~Human() {}

// Creates player move based on input
vector<int> Human::moveCreate() {   
    vector<vector<Tile *>> curBoard = getBoard()->getBoardRef(); // holds a reference to the board
    string input; // reads user provided input

    while (getline(cin, input)) { // for each line,
        istringstream iss(input); // converts string input into input stringstream
        string cmd;
        iss >> cmd; // reads iss into cmd
        
        if (cmd == "resign") { // if cmd is simply resign, just set resign in player to true
            setResign(true);
            return vector<int>{-1};
        } else if (cmd == "move") { // if move,
            string initialPos; // this string holds initial position provided
            string destinationPos; // this string holds destination position provided
            stringstream conversionTool1; // used to convert strings to integers
            int tempInt1; // used to temporarily hold the integers that have been converted from strings
            stringstream conversionTool2; // used to convert strings to integers
            int tempInt2; // used to temporarily hold the integers that have been converted from strings

            iss >> initialPos; // reads second iss input into initalPos
            iss >> destinationPos; // reads third iss input into initalPos

            conversionTool1 << initialPos[1]; // read integer string into conversionTool
            conversionTool1 >> tempInt1; // read conversionTool into tempInt, converting the string into integer value
            int initialRow = 8 - tempInt1; // gets row value
            int initialCol = int(initialPos[0]) - 97; // converts col value into integer
    

            conversionTool2 << destinationPos[1]; // same as above but just with destinationPos
            conversionTool2 >> tempInt2;
            int destinationRow = 8 - tempInt2;
            int destinationCol = int(destinationPos[0]) - 97;

            // Exception Handling
            try {
                // Destination tile is the same as initial tile?
                if (initialRow == destinationRow && initialCol == destinationCol) throw out_of_range("Reason: Destination tile is same as initial tile");
                
                // Acquire piece at initial tile
                Piece *currentPiece = curBoard.at(initialRow).at(initialCol)->getPiece();
                // Acquire destination tile
                Tile *testDestination = curBoard.at(destinationRow).at(destinationCol);

                // No piece in initial tile?
                if (currentPiece == nullptr) throw out_of_range("Reason: No piece located within initial tile");

                // Check if user even owns the piece
                if (own(currentPiece) == false) throw out_of_range("Reason: You do not own that piece");
                
                // Check if the ending destination is a valid move for the piece at initial tile
                if (currentPiece->isValidMove(testDestination) == 0) throw out_of_range("Reason: No valid moves lead there");

                // Now we actually move
                // First, remove piece from initial tile
                curBoard.at(initialRow).at(initialCol)->remove();

                // Second, swap the pieces at initial tile and destination tile
                Piece *previousPiece = curBoard.at(destinationRow).at(destinationCol)->getPiece();
                curBoard.at(destinationRow).at(destinationCol)->set(currentPiece);

                // Third, modify applicable piece values after movement
                currentPiece->setTile(testDestination);
                currentPiece->setNotMoved(false);

                // Fourth, check for an existing captured piece and respond accordingly
                if (previousPiece) {
                    return vector<int>{previousPiece->getTracker(), currentPiece->getTracker(), initialRow, initialCol, destinationRow, destinationCol};
                } else {
                    return vector<int>{0, currentPiece->getTracker(), initialRow, initialCol, destinationRow, destinationCol};
                }

            } catch (const out_of_range &e) {
                cerr << "Invalid Move. " << e.what() << endl;
            }
        } else {
            // if no valid move is provided
            cerr << "Invalid Move. Please use one of the following formats: 'resign', 'move [row][col] [row][col]'" << endl;
        }
    }
    return vector<int>();
}

