#include "Chess.h"
#include "Tile.h"
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "AI.h"
#include "Move.h"
#include <stdexcept>
#include <unordered_map>
#include "Board.h"
#include "Level1.h"
#include "Human.h"
using namespace std;

Chess::Chess():Board{},check{-1},checkmate{-1},stalemate{false},numEachPiece{map<string,int>()},resigned{-1}{}

Chess::~Chess(){}

void Chess::pawnPromote(Piece *p) {
    vector<vector<Tile*>> board = getBoardRef();
    if(p->getColour() == "white") {
        Tile *curr = p->getTile();
        Piece *newpiece;
        if(curr->getRow() == 0) {
            string str;
            curr->remove();
            cout << "Please select a piece to promote (R,B,N,Q)" << endl;
            while(getline(cin, str)) {
                if(str == "R") {
                    newpiece = new Rook("white");
                    setPiece(curr->getRow(), curr->getCol(), newpiece);
                    break;
                }

                if(str == "B") {
                    newpiece = new Bishop("white");
                    setPiece(curr->getRow(), curr->getCol(), newpiece);
                    break;
                }

                if(str == "N") {
                    newpiece = new Knight("white");
                    setPiece(curr->getRow(), curr->getCol(), newpiece);
                    break;
                }

                if(str == "Q") {
                    newpiece = new Queen("white");
                    setPiece(curr->getRow(), curr->getCol(), newpiece);
                    break;
                }
            }
            for(int i = 0; i < (int) board.size(); i++) {
                for(int j = 0; j < (int) board.at(i).size(); j++) {
                    board[i][j]->setAll(getPiecesRef());
                }
            }

            newpiece->setTracker(getRound() + 32);
            Move *move = new Move(p, newpiece, curr, curr, getRound());
            addMove(move);
        }
    }

    if(p->getColour() == "black") {
        Tile *curr = p->getTile();
        Piece *newpiece;
        if(curr->getRow() == 7) {
            string str;
            curr->remove();
            cout << "Please select a piece to promote (r,b,n,q)" << endl;
            while(getline(cin, str)) {
                if(str == "r") {
                    newpiece = new Rook("black");
                    setPiece(curr->getRow(), curr->getCol(), newpiece);
                    break;
                }

                if(str == "b") {
                    newpiece = new Bishop("black");
                    setPiece(curr->getRow(), curr->getCol(), newpiece);
                    break;
                }

                if(str == "n") {
                    newpiece = new Knight("black");
                    setPiece(curr->getRow(), curr->getCol(), newpiece);
                    break;
                }

                if(str == "q") {
                    newpiece = new Queen("black");
                    setPiece(curr->getRow(), curr->getCol(), newpiece);
                    break;
                }
            }
            for(int i = 0; i < (int) board.size(); i++) {
                for(int j = 0; j < (int) board.at(i).size(); j++) {
                    board[i][j]->setAll(getPiecesRef());
                }
            }

            newpiece->setTracker(getRound() + 32);
            Move *move = new Move(p, newpiece, curr, curr, getRound());
            addMove(move);
        }
    }
}

void Chess::Castle(Piece *p) {
    vector<vector<Tile*>> board  = getBoardRef();
    int row = p->getTile()->getRow();
    int col = p->getTile()->getCol();
    if(row == 7 && col == 6) { //white king 
        cout << "here" << endl;
        Tile *rookCell = board[7][7];
        Tile *newRookCell = board[7][5];
        Piece *rook = board[7][7]->getPiece(); //pointer to rook piece 
        cout << rook->getNotMoved() << endl;

        if(rook != nullptr && rook->getNotMoved()) {
            cout << "YES" << endl;
            rookCell->remove();
            newRookCell->set(rook);
            Move *move = new Move(nullptr, rook, rookCell, newRookCell, getRound());
            addMove(move);
            p->createUniqueStatus();
        }
    }

        if(row == 7 && col == 2) {
        Tile *rookCell = board[7][0];
        Tile *newRookCell = board[7][3];
        Piece *rook = board[7][0]->getPiece();
        if(rook != nullptr && rook->getNotMoved()) {
            rookCell->remove();
            newRookCell->set(rook);
            Move *move = new Move(nullptr, rook, rookCell, newRookCell, getRound());
            addMove(move);
        }
    }

        if(row == 0 && col == 6) { //white king
        Tile *rookCell = board[0][7];
        Tile *newRookCell = board[7][5];
        Piece *rook = board[0][7]->getPiece();
        if(rook != nullptr && rook->getNotMoved()) {
            rookCell->remove();
            newRookCell->set(rook);
            Move *move = new Move(nullptr, rook, rookCell, newRookCell, getRound());
            addMove(move);
        }
    }

        if(row == 0 && col == 2) { //black side king 
        Tile *rookCell = board[0][0];
        Tile *newRookCell = board[0][3];
        Piece *rook = board[0][0]->getPiece();
        if(rook != nullptr && rook->getNotMoved()) {
            rookCell->remove();
            newRookCell->set(rook);
            Move *move = new Move(nullptr, rook, rookCell, newRookCell, getRound());
            addMove(move);
        }
    }

}

void Chess::initGame(){
    numEachPiece["WP"]=0; //white pawn
    numEachPiece["WR"]=0; //white rook
    numEachPiece["WKN"]=0; //white knight
    numEachPiece["WB"]=0; //white bishop
    numEachPiece["WQ"]=0; //white queen
    numEachPiece["WK"]=0; //white king
    numEachPiece["BP"]=0; //black pawn
    numEachPiece["BR"]=0; //black rook
    numEachPiece["BKN"]=0; //black horse man done
    numEachPiece["BB"]=0; //black bishop done
    numEachPiece["BQ"]=0; //black queen done
    numEachPiece["BK"]=0; //black king done

    setBoard(8,8);

    //set the kings
    setPiece(7,4,new King("white")); //white king
    numEachPiece.find("WK")->second = 1;
    setPiece(0,4,new King("black"));
    numEachPiece.find("BK")->second = 1;

    //set the Queens (slay)
    /*setPiece(7,3,new Queen("white"));
    numEachPiece.find("WQ")->second = 1;
    setPiece(0,3,new Queen("black"));
    numEachPiece.find("BQ")->second = 1;

    //set bishops
    setPiece(7,2,new Bishop("white"));
    setPiece(7,5, new Bishop("white"));
    numEachPiece.find("WB")->second = 2;
    setPiece(0,2,new Bishop("black"));
    setPiece(0,5, new Bishop("black"));
    numEachPiece.find("BB")->second = 2;

    //set knights
    setPiece(7, 1, new Knight("white")); 
    setPiece(7, 6, new Knight("white")); 
    numEachPiece.find("WKN")->second = 2;
    setPiece(0, 1, new Knight("black")); 
    setPiece(0, 6, new Knight("black")); 
    numEachPiece.find("BKN")->second = 2;*/

    //set rooks
    setPiece(7, 0, new Rook("white")); 
    setPiece(7, 7, new Rook("white")); 
    numEachPiece.find("WR")->second = 2;
    setPiece(0, 0, new Rook("black")); 
    setPiece(0, 7, new Rook("black")); 
    numEachPiece.find("BR")->second = 2;

    //set pawns
    for(int i = 0; i < 8; i++) {
        setPiece(6,i,new Pawn("white"));
    }
    numEachPiece.find("WP")->second = 8;

    for(int i = 0; i < 8; i++) {
        setPiece(1,i,new Pawn("black"));
    }
    numEachPiece.find("BP")->second = 8;
}

//helper function to create pieces for us
Piece *returnPiece(char p) {
    if(p == 'K') return new King("white");
    if(p == 'k') return new King("black");
    if(p == 'Q') return new Queen("white");
    if(p == 'q') return new Queen("black");
    if(p == 'B') return new Bishop("white");
    if(p == 'b') return new Bishop("black");
    if(p == 'R') return new Rook("white");
    if(p == 'r') return new Rook("black");
    if(p == 'N') return new Knight("white");
    if(p == 'n') return new Knight("black");
    if(p == 'P') return new Pawn("white");
    if(p == 'p') return new Pawn("black");
    else return nullptr;
}

//Another helper for setup (get the number from e1 for eg)
vector<int> numPos(string position) {
    int row = 8 - stoi(position.substr(1));
    int col = position[0] - 97;
    vector<int> numpos = {row, col};
    return numpos;
}

//helper to modify pos
void Chess::modifyPos(char ch, string col, int val) {
    string piece;
    switch(val) {
        case 1:
            piece = "WP";
            break;
        case 3:
            piece = "WKN";
            break;
        case 4:
            piece = "WB";
            break;
        case 5:
            piece = "WR";
            break;
        case 9:
            piece = "WQ";
            break;
        case 10:
            piece = "WK";
            break;
    }
    if (col == "white") {
        if (piece == "WP") piece = "BP";
        if (piece == "WKN") piece = "BKN";
        if (piece == "WB") piece = "BW";
        if (piece == "WR") piece = "BR";
        if (piece == "WQ") piece = "BQ";
        if (piece == "WK") piece = "BK";
    }
    if (ch == '+') {
        numEachPiece.find(piece)->second += 1;
    } else if (ch == '-') {
        numEachPiece.find(piece)->second -= 1;
    }
}

void Chess::setup(){
    TextDisplay *dis = getTextDisplay();
    if(getNumPlayers() == 0) {
        createPlayers({"human", "human"});
        initGame();
    }

    else {
        dis->printBoard();
    }

    string str;
    vector<vector<Tile*>> board = getBoardRef();
    while(getline(cin,str)) {
        istringstream iss{str};
        string command;
        iss >> command;
        //add the pieces
        if(command == "+") { 
            char piece;
            string position;
            iss >> piece >> position;
            Piece *p = returnPiece(piece);
            try {
                if(p) {
                    //set the piece on the board using numPos
                    if (!board[numPos(position)[0]][numPos(position)[1]]) {
                        Piece *old = board[numPos(position)[0]][numPos(position)[1]]->getPiece();
                        modifyPos('-',old->getColour(), old->getVal());
                    }

                    setPiece(numPos(position)[0], numPos(position)[1], p);
                    modifyPos('+', p->getColour(), p->getVal());
                }
            } catch (...) {
                cerr << "Bad Piece" << endl;
            }
        }

        if(command == "-") {
            try {
                string position;
                iss >> position;
                Piece *p = board[numPos(position)[0]][numPos(position)[1]]->getPiece();
                if (p) {
                    board[numPos(position)[0]][numPos(position)[1]]->remove();
                    modifyPos('-', p->getColour(), p->getVal());
                }
            } catch (...) {
                cerr << "Bad Piece" << endl;
            }
        }

        if(command == "=") {
            string color;
            iss >> color;
            if(color == "white") setPlayerTurn("white");
            if(color == "black") setPlayerTurn("black");
            else cerr << "Bad input" << endl;
        }

        if(command == "done") {
            bool pawnOnBack;
            for (int i = 0; i < 8;i++) {
                if(board.at(0).at(i)->getPiece() != nullptr && board.at(0).at(i)->getPiece()->getVal() == 1) pawnOnBack = true;
            }

             for (int i = 0;i < 8;i++) {
                if(board.at(7).at(i)->getPiece() != nullptr && board.at(7).at(i)->getPiece()->getVal() == 1) pawnOnBack = true;
            }

            pawnOnBack = false;

            if(numEachPiece.find("WK")->second != 1 || numEachPiece.find("BK")->second != 1) {
                cerr << "Must have exactly one King at each color" << endl;
            }

            if (pawnOnBack) {
                cerr << "No pawns on back row" << endl;
            }

            else {
                break;
            }
        }

        dis->printBoard();
    }

    cout << "Setup done" << endl;
}

void Chess::createPlayers(std::vector<std::string> names){
    string playerSideW = "white"; //white
    string playerSideB = "black"; //white
    int i = 0;
    while (i < (int) names.size()) {
        if(names[i] == "human" && i == 0) {
            Human* newPlayer = new Human(playerSideW);
            addPlayer(newPlayer);
        }

        if(names[i] == "human" && i == 1) {
            Human* newPlayer = new Human(playerSideB);
            addPlayer(newPlayer);
        }

        if(names[i] == "computer" && i == 0) {
            Level1* newPlayer = new Level1(playerSideW);
            addPlayer(newPlayer);
        }

        if(names[i] == "computer" && i == 1) {
            Level1* newPlayer = new Level1(playerSideB);
            addPlayer(newPlayer);
        } 

        i++;
    }
}

void Chess::winner(int l){
    if(l == 0) cout << "Black won" << endl;
    if(l == 1) cout << "White won" << endl;
}

bool Chess::gameOver(){
    if (stalemate) {
        for (int i = 0;i < getNumPlayers(); i++) {
            string player;
            if(i == 0) player = "white";
            if(i == 1) player = "black";

            updateScore(player, 0.5);
        }

        cout << "Stalemate" << endl;
        return true;
    }

    if (checkmate != -1) {
        if(checkmate == 0) {
            cout << "White is in checkmate" << endl;
        }

        if(checkmate == 1) {
            cout << "Black is in checkmate" << endl;
        }

        for (int i = 0; i < getNumPlayers(); i++) {
            if(i != checkmate) { //skips player that got checkmated
                if (i == 0) updateScore("white", 1);
                if (i == 1) updateScore("black", 1);
            }
        }

        winner(checkmate);
        return true;
    }

    else {
        this->resigned = resign();
            if (this->resigned != 0) {
                for (int i = 0; i < getNumPlayers(); ++i) {
                    if (i == this->resigned) { // not the player that got checkmated
                        if (i == 0) updateScore("white", 1);
                        if (i == 1) updateScore("black", 1);
                    }
                }
                winner(!this->resigned);
                return true;
        }
        return false;
    }
}

void Chess::printScore(){
    cout << "Final Score: " << endl;
        cout << "White: " << getScore("white") << endl;
        cout << "Black: " << getScore("black") << endl;
}

int Chess::checkState(){
    if (check == 0) {
        cout <<"White is in Check" << endl;
    }

    if (check == 1) {
        cout << "Black is in Check" << endl;
    }

    return check;
}

void Chess::notify(){
    //check = 0 for white in check, 1 for black
    vector<vector<Tile*>> board = getBoardRef();
    pieces = getPiecesRef();
    for(auto piece : pieces){
        if(piece->getVal() == 10) { //king
            string color = piece->getColour();
            
            if(piece->receiveUniqueStatus()) {
                Castle(piece);
            }        
            if (color == "white") { //king piece is white
                if(piece->getTile()->getThreats("black")) {
                    check = 0;
                } else {
                    check = -1;
                }
            } else if (color == "black") {
                if(piece->getTile()->getThreats("white")) {
                    check = 1;
                } else {
                    check = -1;
                }
            }

            if(check != -1) { //checkmate check!!!
                bool noMove = true;
                for(auto p : piece->getValidMoves()) {
                    if(p.second != 3) {
                        noMove = false;
                    }
                }
                if(noMove == true) {
                    if(color == "white") checkmate = 0;
                    if(color == "black") checkmate = 1; 
                } else {
                    checkmate = -1;
                }
            } else {
                checkmate = -1;
            }    
            //pawn check
        } else if (piece->getVal() == 1) {
            if(piece->getTile()->getRow() == 0 || piece->getTile()->getRow() == 7) {
                pawnPromote(piece);
            }
        }
    }
}



