#pragma once
#include "Piece.h"

class Queen : public Piece {

public:

	Queen(SDL_Renderer* renderer, Team team, Position pos);

	//rules of queen:
	//every movement in any cardinal direction is valid unless obstructed by another piece
	bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) override;

};
