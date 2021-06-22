#include "Bullet.h"

Bullet::Bullet(float posX, float posY)
{
	bulletShape.setSize(sf::Vector2f(10, 10));
	bulletShape.setFillColor(sf::Color::Red);
	bulletShape.setPosition(sf::Vector2f(posX, posY));
	bulletSP = 10;
}

void Bullet::update()
{
	bulletShape.move(0, -bulletSP);
}

void Bullet::renderBullet(sf::RenderTarget* target)
{
	target->draw(bulletShape);
}

sf::RectangleShape Bullet::getBulletShape()
{
	return bulletShape;
}


bool Bullet::collisionBottomScreen()
{
	if (bulletShape.getPosition().y < 0)
	{
		return true;
	}

	if (bulletShape.getPosition().y > 700)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void Bullet::enemyBullet()
{
	bulletShape.move(0, bulletSP);
}