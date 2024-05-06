#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Window.h"
#include "Snake.h"
#include "World.h"
#include "Game.h"
#include "Textbox.h"
#include <vector>
#include <string>

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