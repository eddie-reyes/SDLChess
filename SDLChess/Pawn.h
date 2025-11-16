#include "Piece.h"
#include <vector>

class Pawn : public Piece  {

public:
	Pawn(SDL_Renderer* renderer, Team team, Position pos);

	//rules of pawn:
	//any one-space move where relative y position > 0 is valid UNLESS
	//any space directly in front is obstructed
	//NOTE: A 2-space move forward is valid once and only once
	
	bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) override;

	std::vector<Position> possibleMoves = { {{1, 1}, {-1, 1}, { 0, 1 }, {0,2} } };

};