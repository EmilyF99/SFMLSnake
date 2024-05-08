#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"

class ColourManager {

public:
	static sf::Color NormalBorderColor() { return sf::Color::Green; }
	static sf::Color LostLifeBorderColor() { return sf::Color::Red; }
	void ChangeBorderColor(sf::Color color, World& world);
	void ColourChange(World& world, sf::Time duration);
};