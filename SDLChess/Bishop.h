#pragma once
#include "Piece.h"
#include <vector>

class Bishop : public Piece {

public:
	Bishop(SDL_Renderer* renderer, Team team, Position pos);

	bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) override;

};