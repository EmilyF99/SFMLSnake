#pragma once
#include <SFML/Graphics.hpp>

class ColourManager {

public:
	static sf::Color NormalBorderColor() { return sf::Color::Green; }
	static sf::Color LostLifeBorderColor() { return sf::Color::Red; }
};