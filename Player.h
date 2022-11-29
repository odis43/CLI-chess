#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <vector>

class Piece;
class Board;

class Player {
private:
    Board *board; // holds game board
    std::vector<Piece *> pieces; // holds pieces owned by player
    std::string colour; // either "black" or "white"
    bool resign; // true if player has resigned

    virtual std::vector<int> moveCreate() = 0; // function to move player piece

public:
    Player(std::string colour); // constructor
    virtual ~Player(); // destructor
    
    void addPiece(Piece *); // adds pieces
    void removePiece(Piece *); // removes pieces
    std::vector<Piece *> getPieces(); // returns pieces
    bool own(Piece *); // returns true if piece is owned by Player object
    void setBoard(Board *boardInput); // sets the current value of board
    void setResign(bool resignInput); // sets current value of resign
    std::vector<int> move(); // activates moveCreate

    // Return parameters

    Board *getBoard(); // returns board
    std::string getColour(); // returns colour
    bool getResign(); // returns resign

};

#endif

