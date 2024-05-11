#include "SFMLHeader.h"

#include "Game.h"
#include "Window.h"
#include "Textbox.h"
#include "Files.h"
#include "ColourManager.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)),
m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600)), m_file("scores.txt"), m_colourManager()
{
	m_clock.restart();
	m_file.LocateFile();
}

Game::~Game() { }
sf::Time Game::GetElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }
Window* Game::GetWindow() { return &m_window; }

void Game::HandleInput() {
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

void Game::Update() {
	m_window.Update();
	float timestep = 1.0f / m_snake.GetSpeed();
	if (m_elapsed >= timestep) {
		m_snake.Tick();
		m_world.Update(m_snake);
		m_elapsed -= timestep;

		UpdateTextbox();

		if (m_snake.HasLost()) {
			m_snake.LifeLost(m_file);
			m_colourManager.ColourChange(m_world, sf::seconds(2)); // Change color for 2 seconds
		}
		
	}
}

void Game::UpdateTextbox() {
	m_textbox.Clear();
	m_textbox.Add("Lives: " + std::to_string(m_snake.GetLives()));
	m_textbox.Add("\nScore: " + std::to_string(m_snake.GetScore()));
}

void Game::Render() {
	m_window.BeginDraw();
	// Render here.
	m_world.Render(*m_window.GetRenderWindow());
	m_snake.Render(*m_window.GetRenderWindow());
	m_textbox.Render(*m_window.GetRenderWindow());
	m_window.EndDraw();
}

void Game::InitialTextBoxSetup() {
	m_textbox.Setup(5, 20, 350, sf::Vector2f(225, 0));
	srand(time(nullptr));
	m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
	m_textbox.Add("\nLives: " + std::to_string(m_snake.GetLives()));
	m_textbox.Add("\nScore: " + std::to_string(m_snake.GetScore()));
}