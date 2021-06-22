#ifndef __MYSTERY_SHIP_H
#define __MYSTERY_SHIP_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class MysteryShip
{
private:
	float movement;
	sf::RectangleShape mysteryShip;

public:
	MysteryShip();
	void updateMystery();
	sf::RectangleShape getMystery();
	void render(sf::RenderTarget* target);
};

#endif // !__MYSTERY_SHIP_H


