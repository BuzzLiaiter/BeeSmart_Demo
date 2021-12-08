//by Felenko and Liaiter
#include <iostream>
#include "Game.h"

using namespace std;
using namespace sf;
int main()
{
	//init game engine
	Game game;
	

	//game loop
	while (game.running())
	{
		//update
		game.update();

		//render
		game.render();
		
	}
	

	return 0;
}