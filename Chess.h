#ifndef CHESS
#define CHESS

#include "Board.h"
#include "TextDisplay.h"

class Chess : public Board {
    int check,checkmate;
    bool stalemate;
    std::vector<Piece *> pieces;
    std::map<string,int> numEachPiece;

    //void modifyNumPos
    void pawnPromote(Pawn *p);
    void Castle(Piece *p);

    public:
        Chess();
        ~Chess();
        void initGame();
        void setup();
        void createPlayers(std::vector<std::string> names);
        void winner(int l);
        bool gameOver();
        void printScore();
        void notify();
        int checkState(); //not valid when king is in check   
};

#endif
