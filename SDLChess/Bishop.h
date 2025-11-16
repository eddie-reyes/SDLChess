#pragma once
#include "Piece.h"
#include <vector>

class Bishop : public Piece {

public:
	Bishop(SDL_Renderer* renderer, Team team, Position pos);

	//rules of bishop:
	//any diagonal movement from starting position is valid unless obstructed by another piece
	bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) override;

};