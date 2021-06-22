#include "Enemies.h"

Enemies::Enemies(float posX, float posY)
{
	invaders.setFillColor(sf::Color::Blue);
	invaders.setSize(sf::Vector2f(26, 26));
	invaders.setPosition(sf::Vector2f(posX, posY));
	movement = 1.f;
}

void Enemies::updateInvaders()
{
	invaders.move(movement, 0.f);
}

void Enemies::dropDown()
{
	invaders.setPosition(invaders.getPosition().x, invaders.getPosition().y + 20.f);
}

void Enemies::stopMoving()
{
	movement *= -1;
}

sf::RectangleShape Enemies::getShape()
{
	return invaders;
}

void Enemies::render(sf::RenderTarget* target)
{
	target->draw(invaders);
}
