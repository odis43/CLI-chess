#include "Board.h"
#include "Piece.h"
#include "Tile.h"
#include "Player.h"
#include "Move.h"
#include "TextDisplay.h"
using namespace std;

Board::Board(): theBoard{vector<vector<unique_ptr<Tile>>>()}, thePieces{vector<unique_ptr<Piece>>()}, 
thePlayers{vector<unique_ptr<Player>>()}, round{0}, playerTurn{"white"}, 
inPlay{true}, theTextDisplay{make_unique<TextDisplay>(this)} {}

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

Piece* Board::getPiece(string colour, string name) const {
    for (auto &thePiece:thePieces) {
        if (thePiece->getColour() == colour && thePiece->getName() == name) {
            return thePiece.get();
        }
    }
    return nullptr;
}

vector<vector<Tile*>> Board::getBoardRef() const {
    vector<vector<Tile*>> boardRef;
    for (int i = 0; i < theBoard.size(); ++i) {
        vector<Tile*> rowRef;
        for (int j = 0; j < theBoard.at(i).size(); j++) {
            rowRef.emplace_back(theBoard[i][j].get());
        }
        boardRef.emplace_back(rowRef);
    }
    return boardRef;
}

vector<Piece*> Board::getPiecesRef() const {
    vector<Piece*> pieces;
    for (int i = 0; i < thePieces.size(); i++) {
        Piece* thePiece = thePieces.at(i).get();
        pieces.emplace_back(thePiece);
    }
    return pieces;
}

int Board::getNumPlayers() const {
    return thePlayers.size();
}

void Board::addPlayer(Player *thePlayer) {
    thePlayer->setBoard(this);
    thePlayers.emplace_back(make_unique<Player>(thePlayer));
}

Player* Board::getPlayer(int num){
    return thePlayers.at(num).get();
}

void Board::setPlayerTurn(string colour){
    playerTurn = colour;
}

int Board::getRound() const {
    return round;
}

void Board::addMove(Move *theMove){
    prevMoves.emplace_back(move(make_unique<Move>(m)));
}

Move* Board::getMove(int num){
    if (prevMoves.size() == 0){
        return nullptr;
    } else {
        return prevMoves.at(num).get();
    }
}

void Board::updateScore(string colour, int point){
    if (theScore.count(colour)) {
        theScore[colour] = theScore[colour] + point;
    } else {
        theScore.insert({colour, point});
    }
}

int Board::getScore(string colour) const {
    return theScore.at(colour);
}

TextDiplay *Board::getTextDisplay(){
    return theTextDisplay.get();
}

void Board::resetGame(){
    round = 0;
    playerTurn = "white";
    inPlay = false;
    theBoard.clear();
    thePlayers.clear();
    thePieces.clear();
}

void Board::resign(){
    for (auto player:thePlayers) {
        if (player->getResign()) {
            return true;
        }
    }
    return false;
}

void Board::run(vector<string> playerNames){
    inPlay = true;
    if (playerNames.size() == 0) {
        theTextDisplay->printBoard();
    } else {
        resetGame();
        inPlay = true;
        createPlayers(playerNames);
        initGame();
    }

    for (int i = 0; i < pieces.size(); i++){
        thePieces[i]->setTracker(i);
        thePieces[i]->createValidMoves();
        thePieces[i]->notifyObservers();
    }

    // Connects each tile to a piece
    for (int i = 0; i < theBoard.size(); i++){
        for (int j = 0; j < theBoard.at(i).size(); j++){
            theBoard[i][j]->setAll(getPiecesRef);
        }
    }

    while(inPlay){
        if (gameOver()) {
            inPlay = false;
            break;
        }
        Player* curPlayer = thePlayers[playerTurn].get();
        vector<int> theirMove = curPlayer->move();

    }

    cout << "Game Over" << endl;
    reset();
}
