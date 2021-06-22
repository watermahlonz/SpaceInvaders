#ifndef  __BULLET_H__
#define  __BULLET_H__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemies.h"

class Bullet
{
private:
	float bulletSP;
	sf::RectangleShape bulletShape;

public:
	Bullet(float posX, float posY);
	sf::RectangleShape getBulletShape();
	void update();
	void renderBullet(sf::RenderTarget* target);
	bool collisionBottomScreen();
	void enemyBullet();
};

#endif // ! __BULLET_H__


