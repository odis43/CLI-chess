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
            theRow.emplace_back(unique_ptr<Tile>{new Tile(i,j)});
        }
        theBoard.emplace_back(move(theRow));
    }
}

void Board::setPiece(int row, int col, Piece* piece){
    Tile* tile = theBoard[row][col].get();
    tile->set(piece);
    piece->setTile(tile);
    piece->setBoard(this);
    
    auto ptr = unique_ptr<Piece>{piece};
    thePieces.emplace_back(move(ptr));
    if (piece->getColour() == "white") {
        thePlayers[0]->addPiece(piece);
    } else if (piece->getColour() == "black") {
        thePlayers[1]->addPiece(piece);
    }
}

Piece* Board::getPiece(int tracker) const {
    if (tracker == -1) {
        return nullptr;
    }
    for (auto &thePiece:thePieces) {
        if (thePiece->getTracker() == tracker) {
            return thePiece.get();
        }
    }
    return nullptr;
}

vector<vector<Tile*>> Board::getBoardRef() {
    vector<vector<Tile*>> boardRef;
    for (int i = 0; i < (int) theBoard.size(); ++i) {
        vector<Tile*> rowRef;
        for (int j = 0; j < (int) theBoard.at(i).size(); j++) {
            rowRef.emplace_back(theBoard[i][j].get());
        }
        boardRef.emplace_back(rowRef);
    }
    return boardRef;
}

vector<Piece*> Board::getPiecesRef() {
    vector<Piece*> pieces;
    for (int i = 0; i < (int) thePieces.size(); i++) {
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
    thePlayers.emplace_back(unique_ptr<Player>{thePlayer});
}

Player* Board::getPlayer(int num) const {
    return thePlayers.at(num).get();
}

void Board::setPlayerTurn(string colour){
    playerTurn = colour;
}

int Board::getRound() const {
    return round;
}

void Board::addMove(Move *theMove){
    prevMoves.emplace_back(move(unique_ptr<Move>{theMove}));
}

Move* Board::getMove(int num){
    if (prevMoves.size() == 0){
        return nullptr;
    } else {
        return prevMoves.at(num).get();
    }
}

void Board::updateScore(string colour, float point){
    if (colour == "white") {
        theScore[0] += point;
    } else {
        theScore[1] += point;
    }
}

int Board::getScore(string colour) const {
    if (colour == "white") {
        return theScore[0];
    } else {
        return theScore[1];
    }
}

TextDisplay* Board::getTextDisplay(){
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

bool Board::resign(){
    if (thePlayers[0]->getResign() || thePlayers[1]->getResign()) {
        return true;
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
        theScore.push_back(0);
        theScore.push_back(0);
        theTextDisplay->printBoard();
    }

    for (int i = 0; i < (int) thePieces.size(); i++){
        thePieces[i]->setTracker(i);
    }

    // Connects each tile to a piece
    for (int i = 0; i < (int) theBoard.size(); i++){
        for (int j = 0; j < (int) theBoard.at(i).size(); j++){
            theBoard[i][j]->setAll(getPiecesRef());
        }
    }

    for (int i = 0; i < (int) thePieces.size(); i++){
        if (thePieces[i]->getVal() != 10){
            thePieces[i]->createValidMoves();
        }
    }

    for (int i = 0; i < (int) thePieces.size(); i++){
        thePieces[i]->notifyObservers();
    }

    for (int i = 0; i < (int) thePieces.size(); i++){
        if (thePieces[i]->getVal() == 10){
            thePieces[i]->createValidMoves();
        }
    }

    while(inPlay){
        if (gameOver()) {
            inPlay = false;
            break;
        }
        Player* curPlayer;
        if (playerTurn == "white") {
            curPlayer = thePlayers[0].get();

        } else if (playerTurn == "black") {
            curPlayer = thePlayers[1].get();
        }

        vector<int> theirMove = curPlayer->move();
        if (theirMove.size() == 0){
            cout << "Player Did Not Make A Move" << endl;
            break;
        } else if (theirMove.size() == 1 && gameOver()) {
            inPlay = false;
            break;
        } else {
            Piece* prevPiece = getPiece(theirMove[0]);
            Piece* curPiece = getPiece(theirMove[1]);
            Tile* initialTile = theBoard[theirMove[2]][theirMove[3]].get();
            Tile* destTile = theBoard[theirMove[4]][theirMove[5]].get();
            Move* currMove = new Move(prevPiece, curPiece, initialTile, destTile, round);
            prevMoves.push_back(unique_ptr<Move>{currMove});

            for (int i = 0; i < (int) thePieces.size(); i++){
                if (thePieces[i]->getVal() != 10){
                    thePieces[i]->createValidMoves();
                }
            }
            for (int i = 0; i < (int) thePieces.size(); i++){
                thePieces[i]->notifyObservers();
            }

            for (int i = 0; i < (int) thePieces.size(); i++){
                if (thePieces[i]->getVal() == 10){
                    thePieces[i]->createValidMoves();
                }
            }
            if ((checkState() == -1) || (checkState() == 0 && playerTurn != "white") || (checkState() == 1 && playerTurn != "black")) {
                if (playerTurn == "white") {
                    playerTurn = "black";
                } else if (playerTurn == "black") {
                    playerTurn = "white";
                }
                round++;
                theTextDisplay->printBoard();
            } else {
                cout << "Game is Invalid" << endl;
            }
        }
    }
    cout << "Game Over" << endl;
    resetGame();
}
