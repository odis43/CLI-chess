#include "Queen.h"
#include "Tile.h"
using namespace std;

Queen::Queen(string colour): Piece{colour, 9}{}

Queen::~Queen(){}

void Queen::print(){
    if (getColour() == "white"){
        cout << "Q";
    } else {
        cout << "q";
    }
}

void Queen::genMoves(vector<vector<Tile*>> board, Tile *tile, int row, int col){
    
}
