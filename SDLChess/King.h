#pragma once
#include "Piece.h"

class King : public Piece {

public:
	King(SDL_Renderer* renderer, Team team, Position pos);


	//rules of king:
	//every one-space move in any cardinal direction is valid
	bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) override;

};