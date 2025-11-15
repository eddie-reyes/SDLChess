#include "Piece.h"
#include <vector>

class Pawn : public Piece  {

public:
	Pawn(SDL_Renderer* renderer, Team team, Position pos);

	bool validMove(std::array<std::array<Piece*, 8>, 8>& pieces, Position& mousePos) override;

	std::vector<Position> possibleMoves = { {{1, 1}, {-1, 1}, { 0, 1 }, {0,2} } };

};