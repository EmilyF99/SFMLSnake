#pragma once
#include "Window.h"
#include "Snake.h"
#include "World.h"
#include "Textbox.h"
#include "Files.h"

class Game {
public:
	Game();
	~Game();
	void HandleInput();
	void Update();
	void UpdateTextbox();
	void Render();
	Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();
private:
	Window m_window;
	sf::Clock m_clock;
	float m_elapsed;
	World m_world;
	Snake m_snake;
	Textbox m_textbox;
	Files m_file;
};