#include "Player.h"

Player::Player()
{
	rect.setPosition(sf::Vector2f(400, 550));
	rect.setSize(sf::Vector2f(40, 40));
	rect.setFillColor(sf::Color::Cyan);
	moveSP = 10.f;
	shootingNow = false;
}

void Player::handleInputs()
{
	if (rect.getPosition().x > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			rect.move(sf::Vector2f(-moveSP, 0));
		}
	}

	if (rect.getPosition().x < 755)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			rect.move(sf::Vector2f(moveSP, 0));
		}
	}
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(rect);
}

sf::RectangleShape Player::getShape()
{
	return rect;
}

bool Player::isShooting()
{
	return shootingNow;
}

void Player::SetShooting()
{
	if (!shootingNow)
	{
		shootingNow = true;
	}

	else
	{
		shootingNow = false;
	}
}

void Player::setMovement()
{
	moveSP++;
}

void Player::setMovementNegative()
{
	moveSP--;
}