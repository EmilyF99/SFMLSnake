#include "SFMLHeader.h"

#include "Game.h"
#include "Window.h"
#include "Textbox.h"
#include "Files.h"
#include "ColourManager.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)),
m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600)), m_file("scores.txt"), m_colourManager(), 
m_currentState(GameState::STATE_START)
{
	m_clock.restart();
	m_file.LocateFile();
	m_textbox.Setup(5, 20, 350, sf::Vector2f(225, 0));
}

Game::~Game() { }
sf::Time Game::GetElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }
Window* Game::GetWindow() { return &m_window; }

void Game::HandleInput() {

	if (m_currentState == GameState::STATE_START)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			m_currentState = GameState::STATE_PLAY;
		}
	}
	
	if (m_currentState == GameState::STATE_PLAY)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
			&& m_snake.GetPhysicalDirection() != Direction::Down)
		{
			m_snake.SetDirection(Direction::Up);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
			&& m_snake.GetPhysicalDirection() != Direction::Up)
		{
			m_snake.SetDirection(Direction::Down);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			&& m_snake.GetPhysicalDirection() != Direction::Right)
		{
			m_snake.SetDirection(Direction::Left);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
			&& m_snake.GetPhysicalDirection() != Direction::Left)
			m_snake.SetDirection(Direction::Right);
	}

	if (m_currentState == GameState::STATE_GAME_OVER)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			m_snake.ResetStats();
			m_currentState = GameState::STATE_PLAY;
		}
	}
}

void Game::Update() {
	m_window.Update();
	float timestep = 1.0f / m_snake.GetSpeed();
	if (m_elapsed >= timestep) {
		m_snake.Tick();
		m_world.Update(m_snake);
		m_elapsed -= timestep;

		UpdateTextbox(m_currentState);

		if (m_snake.HasLost()) {
			m_snake.LifeLost(m_file);
			m_colourManager.ColourChange(m_world, sf::seconds(2)); // Change color for 2 seconds
		}

		if (m_snake.GetLives() <= 0)
		{
			m_currentState = GameState::STATE_GAME_OVER;
		} 
		
	}
}

void Game::UpdateTextbox(GameState m_currentState) {
	m_textbox.Clear();

	switch (m_currentState)
	{
	case GameState::STATE_START:
		StartGameText();
		break;
	case GameState::STATE_PLAY:
		MainGameText();
		break;
	case GameState::STATE_GAME_OVER:
		GameOverText();
		break;
	}
}

void Game::Render() {
	m_window.BeginDraw();
	// Render here.
	m_world.Render(*m_window.GetRenderWindow());
	m_snake.Render(*m_window.GetRenderWindow());
	m_textbox.Render(*m_window.GetRenderWindow());
	m_window.EndDraw();
}

void Game::MainGameText() 
{
	srand(static_cast<unsigned int>(time(nullptr)));
	//m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
	m_textbox.Add("\nLives: " + std::to_string(m_snake.GetLives()));
	m_textbox.Add("\nScore: " + std::to_string(m_snake.GetScore()));
}

void Game::StartGameText()
{
	m_textbox.Add("\nSNAKE\nPress Space to Start.");
}

void Game::GameOverText()
{
	m_textbox.Add("\nGAME OVER\nPress Space to Restart.");
	m_textbox.Add("\nTop Three Scores: ");
	//get scores here 

	std::vector<int> topScores = m_file.GetTopScores();
	int rank = 1;
	for (int score : topScores) {
		m_textbox.Add(std::to_string(rank) + ". " + std::to_string(score) + ",");
		rank++;
	}
}