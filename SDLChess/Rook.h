#pragma once
#include "Piece.h"
#include <vector>

class Rook : public Piece {

public:
	Rook(SDL_Renderer* renderer, Team team, Position pos);


	//rules of rook:
	//any movement along the vertical and horizontal axis from starting position is valid unless obstructed by another piece
	bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) override;

};