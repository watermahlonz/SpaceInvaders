#include "Bunker.h"

Bunker::Bunker(float posX, float posY)
{
	bunkerBlock.setFillColor(sf::Color::Green);
	bunkerBlock.setSize(sf::Vector2f(20, 20));
	bunkerBlock.setPosition(sf::Vector2f(posX, posY));
}

sf::RectangleShape Bunker::getBunker()
{
	return bunkerBlock;
}

void Bunker::render(sf::RenderTarget* window)
{
	window->draw(bunkerBlock);
}