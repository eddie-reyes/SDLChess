
#include <SDL.h>
#include "Board.h"



namespace Game {
	
	//initalizes board and triggers main game loop
	void Run();

	//event handler
	void ProcessEvent(SDL_Event& event, Board& board);

	static bool isRunning;

}
