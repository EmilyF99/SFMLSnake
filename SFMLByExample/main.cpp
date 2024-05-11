#include "defaultHeader.h"
#include "SFMLHeader.h"

//Circular Issue
#include "Window.h"
#include "Snake.h"
#include "World.h"
#include "Game.h"
#include "Textbox.h"
#include "States.h"

int main(int argc, char* argv[]) {
	// Program entry point.
	Game game;

	States states;
	states.StateControl(STATE_START);

	while (!game.GetWindow()->IsDone()) {

		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
		{
			states.StateControl(STATE_PLAY);
			
		}
		
	}
}