#ifndef __GAME_H__
#define __GAME_H__
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"
#include "Bullet.h"
#include "Enemies.h"
#include "MysteryShip.h"
#include "Debug.h"
#include "Bunker.h"

#include <vector>
#include <iostream>
#include <cstdlib>

enum gameStates {main_menu, playing, paused, game_over, you_win};

class Game
{
	//Will need the window
private:
	//windows
	sf::RenderWindow gameWindow;
	sf::RenderWindow* secondWindow{};

	//Fonts and Texts
	sf::Font gameFont;
	sf::Text menuText;
	sf::Text scoreText;
	sf::Text livesText;
	sf::Text mainMenu;
	sf::Text gameover;
	sf::Text youWin;

	sf::Text firstControls;

	//Objects
	Player* player1;
	Bullet* playerBullet;
	std::vector <Enemies*> invaderArmy;
	std::vector <Bunker*> bunker1;
	Bullet* invaderBullet;
	MysteryShip* bonusShip;
	gameStates state;


	//Testing
	sf::RectangleShape rect;
	std::vector<sf::RectangleShape> invaders;

	//Time
	float clock;
	float alienSpawnBullet;
	float spawnBonusShip;

	//Variables
	int score;
	int timerDrop;


private:
	void processEvents();
	void update();
	void render();
	void start();
	void Delete();
	//void spawnBullet();

public:
	Game();
	~Game();
	void run();
};

#endif // !__GAME_H__


