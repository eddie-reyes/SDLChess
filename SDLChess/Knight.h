#pragma once
#include "Piece.h"
#include <vector>

class Knight : public Piece {

public:
	Knight(SDL_Renderer* renderer, Team team, Position pos);

	bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) override;

	std::vector<Position> possibleMoves = { {2, 1}, {1, 2}, { -1, 2 }, {-2,1}, {-2, -1 }, {-1, -2}, {1, -2}, {2, -1} };

};