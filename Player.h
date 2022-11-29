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
    std::string colour;
    bool resign; // true if player has resigned

    virtual std::vector<int> moveCreate() = 0; // function to move player piece

public:
    Player(int side);
    virtual ~Player();
    
    void addPiece(Piece *); // adds pieces
    //void removePiece(Piece *); // removes pieces
    std::vector<Piece *> getPieces(); // returns pieces
    bool own(Piece *); // returns true if piece is owned by Player object

    std::string getSide(); // returns side
    bool getResign(); // returns resign

};

#endif

