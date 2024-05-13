#pragma once

class World;

class ColourManager {

public:
	void ChangeBorderColor(sf::Color color, World& world);
	void ColourChange(World& world, sf::Time duration);

private:
	sf::Color m_lastColor;
};