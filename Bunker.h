#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Bunker
{
private:
	sf::RectangleShape bunkerBlock;

public:
	Bunker(float posX, float posY);
	sf::RectangleShape getBunker();
	void render(sf::RenderTarget* window);
};

