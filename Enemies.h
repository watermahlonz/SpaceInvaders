#ifndef __ENEMIES_H__
#define __ENEMIES_H__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Enemies {
private:
	float movement;
	sf::RectangleShape invaders;

public:
	Enemies(float posX, float posY);
	void updateInvaders();
	void dropDown();
	void stopMoving();
	void render(sf::RenderTarget* window);
	sf::RectangleShape getShape();
};

#endif // !__ENEMIES_H__
