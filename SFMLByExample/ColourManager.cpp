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
    ColourManager colourManager;
    colourManager.ChangeBorderColor(ColourManager::LostLifeBorderColor(), world);
}