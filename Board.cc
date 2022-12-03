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

void Board::setPiece(int row, int col, Piece* piece){
    Tile* tile = theBoard[row][col].get();
    tile->set(piece);
    piece->setTile(tile);
    piece->setBoard(this);
    
    auto ptr = make_unique<Piece>(piece);
    thePieces.emplace_back(move(ptr));
    if (piece->getColour() == "white") {
        thePlayers[0]->addPiece(piece);
    } else if (piece->getColour() == "black") {
        thePlayers[1]->addPiece(piece);
    }
}

Piece* Board::getPiece(int tracker) const {
    for (auto &thePiece:thePieces) {
        if (thePiece->getTracker() == tracker) {
            return thePiece.get();
        }
    }
    return nullptr;
}

vector<vector<Tile*>> Board::getBoardRef() const {
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

vector<Piece*> Board::getPiecesRef() const {
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
    thePlayers.emplace_back(make_unique<Player>(thePlayer));
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
    prevMoves.emplace_back(move(make_unique<Move>(theMove)));
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
    }

    for (int i = 0; i < (int) thePieces.size(); i++){
        thePieces[i]->setTracker(i);
        thePieces[i]->createValidMoves();
        thePieces[i]->notifyObservers();
    }

    // Connects each tile to a piece
    for (int i = 0; i < (int) theBoard.size(); i++){
        for (int j = 0; j < (int) theBoard.at(i).size(); j++){
            theBoard[i][j]->setAll(getPiecesRef());
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
            prevMoves.emplace_back(make_unique<Move>(currMove));

            for (int i = 0; i < (int) thePieces.size(); i++){
                thePieces[i]->setTracker(i);
                thePieces[i]->createValidMoves();
                thePieces[i]->notifyObservers();
            }

            if (checkState()) {
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
