#include "Debug.h"

Debug::Debug()
	: window(sf::VideoMode(400, 400), "Debug Window")
{
	plus.setSize(sf::Vector2f(30, 30));
	plus.setPosition(sf::Vector2f(10, 10));
	plus.setFillColor(sf::Color::Red);

	minus.setSize(sf::Vector2f(30, 30));
	minus.setPosition(sf::Vector2f(10, 40));
	minus.setFillColor(sf::Color::Red);

	isClicked = false;
	numberofClicks = 0;
}

void Debug::processEvents()
{
	sf::Event debugEvent;

	while (window.pollEvent(debugEvent))
	{
		if (debugEvent.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Debug::update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isClicked = true;
	}
}

void Debug::render()
{
	window.clear();
	window.draw(plus);
	window.draw(minus);
	window.display();
}

void Debug::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
		numberOfClicks();
	}
}

bool Debug::isClickedd()
{
	if (isClicked)
	{
		numberofClicks--;
		return true;
	}

	else
	{
		return false;
	}
}

void Debug::clickOff()
{
	isClicked = false;
}

bool Debug::windowIsOPen()
{
	if (window.isOpen())
	{
		return true;
	}

	else
	{
		return false;
	}
}

int Debug::numberOfClicks()
{
	return numberofClicks;
}