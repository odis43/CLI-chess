#ifndef PAWN
#define PAWN

//#include "Piece.h"

class Pawn : public Piece {
    bool isPromoted;
    public:
        Pawn(int color);
        ~Pawn();
        void genMove(int row, int col, std::vector<std::vector<Tile*>> board, Tile *tile);
        bool Promoted();
        void print();
};

#endif


#include "Pawn.h"

using namespace std;

Pawn::Pawn(int color):Piece{color, 1},color{color},isPromoted{false}{};
Pawn::~Pawn(){}
void Pawn::genMove(int row, int col, vector<vector<Tile*>> board, Tile *tile) {

}

void Pawn::Promoted() {
    return isPromoted;
}

void Pawm::print() {
    if(this->getColor()){
        cout << "p";
    } else {
        cout << "P";
    }
}

void Pawn::genMove(int row, int col, vector<vector<Tile*>> board, Tile *tile) {
    int newRow = this->row - 1;
    if(getColor()){
        newRow = this->row + 1;
    }

    if()
}