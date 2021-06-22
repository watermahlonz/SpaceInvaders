#include "MysteryShip.h"

MysteryShip::MysteryShip()
{
	mysteryShip.setSize(sf::Vector2f(26, 26));
	mysteryShip.setPosition(sf::Vector2f(820, 45));
	mysteryShip.setFillColor(sf::Color::Red);
	movement = 3.f;
}

void MysteryShip::updateMystery()
{
	mysteryShip.move(-movement, 0);
}

sf::RectangleShape MysteryShip::getMystery()
{
	return mysteryShip;
}

void MysteryShip::render(sf::RenderTarget* target)
{
	target->draw(mysteryShip);
}