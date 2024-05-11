#include "defaultHeader.h"
#include "SFMLHeader.h"
//Circular Issue
#include "ColourManager.h"
#include "World.h"


void ColourManager::ChangeBorderColor(sf::Color color, World& world) 
{
    sf::RectangleShape* bounds = world.getBounds();
    for (int i = 0; i < 4; ++i) {
        bounds[i].setFillColor(color);
    }
}

void ColourManager::ColourChange(World& world, sf::Time duration)
{
    // Define a list of possible colors
    std::vector<sf::Color> colors = {
        sf::Color::Red,
        sf::Color::Magenta,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color::Green
        
    };

    // Select a random color from the list
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, colors.size() - 1);

    // Keep selecting until a different color is chosen
    sf::Color randomColor;
    do {
        randomColor = colors[dis(gen)];
    } while (randomColor == m_lastColor);

    // Store the new color as the last color
    m_lastColor = randomColor;

    // Apply the random color to the world
    ChangeBorderColor(randomColor, world);
}