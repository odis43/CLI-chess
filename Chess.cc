#include "Chess.h"
#include "Tile.h"
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "AI.h"
//#include rest of what we need when it is done
#include <stdexcept>
#include <unordered_map>

using namespace std;


class Chess : public Board {
    int check,checkmate;
    bool stalement;
    std::vector<Piece *> pieces;
    std::map<string,int> numEachPiece;

    //void modifyNumPos
    void pawnPromote(Piece *p);
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

Chess::Chess():Board{},check{-1},checkmate{-1},stalement{false},numEachPiece{map<string,int>()}{}

Chess::~Chess(){}

void Chess::pawnPromote(Piece *p) {

}

void Chess::Castle(Piece *p) {}

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
    setPiece(7,3,new King("white")); //white king
    numEachPiece.find("WK")->second = 1;
    setPiece(0,4,new King("black"));
    numEachPiece.find("BK")->second = 1;

    //set the Queens (slay)
    setPiece(7,3,new Queen("white"));
    numEachPiece.find("WQ")->second = 1;
    setPiece(0, 3, new Queen("black"));
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
    numEachPiece.find("BKN")->second = 2;

    //set rooks
    setPiece(7, 0, new Rook("white")); 
    setPiece(7, 7, new Rook("white")); 
    numEachPiece.find("WR")->second = 2;
    setPiece(0, 0, new Knight("black")); 
    setPiece(0, 7, new Knight("black")); 
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

void Chess::setup();

void Chess::createPlayers(std::vector<std::string> names){}

void Chess::winner(int l){}

void Chess::gameOver(){}

void Chess::printScore(){}

void Chess::checkState(){}

void Chess::notify(){}

