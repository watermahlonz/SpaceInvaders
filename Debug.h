#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Debug
{
private:
	sf::RenderWindow window;
	sf::RectangleShape plus;
	sf::RectangleShape minus;
	int numberofClicks;

	bool isClicked;

	//sf::Font spaceInvader;
	//sf::Text debugText;

private:
	void processEvents();
	void update();
	void render();

public:
	Debug();
	void run();
	bool isClickedd();
	void clickOff();
	bool windowIsOPen();
	int numberOfClicks();
};

