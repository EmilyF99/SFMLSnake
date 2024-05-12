#pragma once

class Snake;

class World {
public:
	World(sf::Vector2u l_windSize);
	~World();
	int GetBlockSize();
	void RespawnApple();
	void RespawnSpeedUp();
	void Update(Snake& l_player);
	void Render(sf::RenderWindow& l_window);
	sf::RectangleShape* getBounds() {return m_bounds;}
private:
	sf::Vector2u m_windowSize;
	sf::Vector2i m_item;
	sf::Vector2i m_item2;
	int m_blockSize;
	sf::CircleShape m_appleShape;
	sf::CircleShape m_speedUp;
	sf::RectangleShape m_bounds[4];
};