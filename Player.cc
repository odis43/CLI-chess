#include "Player.h"

#include <vector>
#include "Piece.h"

Player::Player(int side) : board{nullptr}, pieces{vector<Piece*>()}, colour{colour}, resign{false} {}

Player::~Player() {}

void Player::addPiece(Piece *piece) {
    pieces.emplace_back(piece);
}

/*
void Player::removePiece(Piece *piece) {
    pieces.emplace_back(piece);
}
*/

bool Player::own(Piece *piece) {
    for (int i = 0; i < pieces.size(); i++) {
        if (piece == pieces[i]) {
            return true;
        }
    }
    return false;
}

int Player::getSide() { return colour; }

bool Player::getResign() { return resign; }

