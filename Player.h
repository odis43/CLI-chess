#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include <memory>

class Piece;
class Board;

class Player {
private:
    Board *board; // holds game board
    std::vector<Piece *> pieces; // holds pieces owned by player
    int side; // (used to be called colour), side makes more sense for 4 player chess, also side is either 1, 2, 3, or 4.
    bool resign; // true if player has resigned

    virtual std::vector<int> moveCreate() = 0; // function to move player piece

public:
    Player(int side);
    
    void addPiece(Piece *); // adds pieces
    //void removePiece(Piece *); // removes pieces
    std::vector<Piece *> getPieces(); // returns pieces
    bool own(Piece *); // returns true if piece is owned by Player object

    int getSide(); // returns side
    bool getResign(); // returns resign

};
#endif

