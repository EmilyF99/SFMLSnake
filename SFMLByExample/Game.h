#pragma once
#include "Window.h"
#include "Snake.h"
#include "World.h"
#include "Textbox.h"
#include "Files.h"
#include "ColourManager.h"

enum class GameState {
	STATE_START,
	STATE_PLAY,
	STATE_GAME_OVER
};

class Game {
public:
	Game();
	~Game();
	void HandleInput();
	void Update();
	void UpdateTextbox(GameState m_currentState);
	void Render();
	Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();
	void MainGameText();
	void StartGameText();
	void GameOverText();
private:
	Window m_window;
	sf::Clock m_clock;
	float m_elapsed;
	World m_world;
	Snake m_snake;
	Textbox m_textbox;
	Files m_file;
	ColourManager m_colourManager;
	GameState m_currentState;
};