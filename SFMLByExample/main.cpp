#include "defaultHeader.h"
#include "SFMLHeader.h"

//Circular Issue
#include "Window.h"
#include "Snake.h"
#include "World.h"
#include "Game.h"
#include "Textbox.h"

int main(int argc, char* argv[]) {
	// Program entry point.
	Game game;
	while (!game.GetWindow()->IsDone()) {

		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();		
	}
}