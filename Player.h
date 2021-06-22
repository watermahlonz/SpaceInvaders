#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Player
{
private:
	float moveSP;
	sf::RectangleShape rect;
	bool shootingNow;
	

public:
	Player();
	void handleInputs();
	void render(sf::RenderTarget* target);
	bool isShooting();
	void SetShooting();
	void setMovement();
	void setMovementNegative();
	sf::RectangleShape getShape();
	
};

#endif // !__PLAYER_H__


