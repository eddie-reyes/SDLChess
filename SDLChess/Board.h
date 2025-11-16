
#include <SDL.h>
#include <array>
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "types.h"
#include "constants.h"

const Color BG_Color = { 248, 231, 187 };
const Color FG_Color = { 251, 245, 222 };

class Board {

public:

	void Draw();

	void updateMousePosition();

	void OnInteractionStarted();

	void OnInteractionEnded();

	void EvaluateMove();

	void ShowGameOverScreen();

	Board();
	
	~Board();

	// Surface of board to draw on
	SDL_Renderer* Renderer;

	Piece* currentPiece;

	Position mousePos;

	//container for all chess pieces
	std::array<std::array<Piece*, 8>, 8> Pieces;

private:

	Team m_CurrentTurn = Team::WHITE_TEAM;

	// Create our window
	SDL_Window* m_Window;

	SDL_Texture* m_BlackWin;

	SDL_Texture* m_WhiteWin;

	bool gameOver = false;


};