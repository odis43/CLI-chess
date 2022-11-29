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
    pieces.emplace_back(piece);
}


bool Player::own(Piece *piece) {
    for (int i = 0; i < pieces.size(); i++) {
        if (piece == pieces[i]) {
            return true;
        }
    }
    return false;
}

int Player::getColour() { return colour; }

bool Player::getResign() { return resign; }

