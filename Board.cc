#include "Board.h"
#include "Piece.h"
#include "Tile.h"
#include "Player.h"
#include "Move.h"
#include "TextDisplay"
using namespace std;

Board::Board(): theBoard{vector<vector<unique_ptr<Tile>>>()}, thePieces{vector<unique_ptr<Piece>>()}, 
thePlayers{vector<unique_ptr<Player>>()}, prevMoves{vector<unique_ptr<Move>>}, 
round{0}, playerTurn{"white"}, inPlay{true}, theTextDisplay{make_unique<TextDisplay>(this)} {}

Board::~Board(){}

void Board::setBoard(int row, int col) {
    for (int i = 0; i < row; ++i) {
        vector<unique_ptr<Tile>> theRow;
        for (int j = 0; j < col; ++j) {
            theRow.emplace_back(make_unique<Tile>(i,j));
        }
        theBoard.emplace_back(move(theRow));
    }
}

void Board::setPiece(int row, int col, Piece *piece){
    Tile *tile = theBoard[row][col].get()
    piece->setBoard(this);
    tile->setPiece(piece);
    piece->setTile(tile);
    auto ptr = make_unique<Piece>(piece);
    thePieces.emplace_back(move(ptr));
    thePlayers.at(piece->getColour())->addPiece(piece);
}

Piece* Board::getPiece(string colour, string name){
    for (auto &thePiece:thePieces) {
        if (thePiece->getColour() == colour && thePiece->getName() == name) {
            return thePiece.get();
        }
    }
    return nullptr;
}

vector<Piece*> Board::getPiecesRef(){
    vector<Piece*> pieces;
    for (int i = 0; i < thePieces.size(); i++) {
        Piece* thePiece = thePieces.at(i).get();
        pieces.emplace_back(thePiece);
    }
    return pieces;
}
