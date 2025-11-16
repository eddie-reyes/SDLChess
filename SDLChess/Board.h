
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

//board color palette
const Color BG_Color = { 248, 231, 187 };
const Color FG_Color = { 251, 245, 222 };

class Board {

public:

	//draws board and pieces every frame
	void Draw();

	//updates mouse position relative to window
	void updateMousePosition();

	//mouse pressed
	void OnInteractionStarted();

	//mouse released
	void OnInteractionEnded();

	//modifies underlying pieces array
	void EvaluateMove();

	//game over graphic
	void ShowGameOverScreen();

	//init board and pieces
	Board();
	
	//responsible for destroying window and renderer
	~Board();

	// Surface of board to draw on
	SDL_Renderer* Renderer;

	//ref to current piece being held
	Piece* currentPiece = nullptr;

	//board keeps track of mouse position every frame
	Position mousePos = {};

	//container for all chess pieces
	std::array<std::array<Piece*, 8>, 8> Pieces;

private:

	//white goes first
	Team m_CurrentTurn = Team::WHITE_TEAM;

	// Create our window
	SDL_Window* m_Window;

	//black win graphic
	SDL_Texture* m_BlackWin;

	//white win graphic
	SDL_Texture* m_WhiteWin;

	//flag triggers when king is taken
	bool gameOver = false;


};