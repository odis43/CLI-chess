#include <vector>
#include "Player.h"
#include "Piece.h"

// Constructor
Player::Player(std::string colour) : board{nullptr}, pieces{vector<Piece*>()}, colour{colour}, resign{false} {}

// Destructor
Player::~Player() {}

// Adds a piece to back of vector which holds Player's owned pieces
void Player::addPiece(Piece *piece) {
    pieces.emplace_back(piece);
}

// Removes a piece from player's owned pieces
void Player::removePiece(Piece *piece) {
    for (auto it = pieces.begin(); it != pieces.end(); ++it) {
        if (*it == piece) {
            pieces.erase(it);
            break;
        }
    }
}

// Returns true if a piece is owned by a player
bool Player::own(Piece *piece) {
    for (auto it = pieces.begin(); it != pieces.end(); ++it) {
        if (*it == piece) {
            return true;
        }
    }
    return false;
}

// Sets value of game board
void Player::setBoard(Board *boardInput) {
    board = boardInput;
}

// Sets value of resign
void Player::setResign(bool resignInput) {
    resign = resignInput;
}

// Functions that return parameters

Board *Player::getBoard() { return board; }

int Player::getColour() { return colour; }

bool Player::getResign() { return resign; }

