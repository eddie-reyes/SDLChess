
#include <SDL.h>
enum class Team {

	WHITE_TEAM,
	BLACK_TEAM

};

class Piece {

public:

	Piece(SDL_Renderer* renderer, Team team);

	void Draw();

	SDL_Texture  * getTexture() const;



private:


	Team m_Team;

protected:

	SDL_Texture* m_Texture;

};