#include "Game.h"
#include <iostream>
#include <sstream>

Game::Game()
: gameWindow(sf::VideoMode(800, 600), "Space Invaders")
{
	gameWindow.setFramerateLimit(60);
	secondWindow = nullptr;
	state = main_menu;

	//timers
	clock = 0;
	alienSpawnBullet = 0;
	spawnBonusShip = 0;
	timerDrop = 21;

	//Setting up 
	if (!gameFont.loadFromFile("space.ttf"))
	{
		std::cout << "Report Error!!!" << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		rect.setSize(sf::Vector2f(20, 20));
		rect.setFillColor(sf::Color::Cyan);
		rect.setPosition(sf::Vector2f(30.f * (i+23.5f), 16.f));
		invaders.push_back(rect);
	}

	
	//Setting up game fonts
	scoreText.setFont(gameFont);
	livesText.setFont(gameFont);
	menuText.setFont(gameFont);
	mainMenu.setFont(gameFont);
	gameover.setFont(gameFont);
	youWin.setFont(gameFont);
	firstControls.setFont(gameFont);

	menuText.setString("Score:");
	menuText.setPosition(0, 5);
	mainMenu.setString("Welcome to space Invaders!!!");
	mainMenu.setPosition(150, 300);

	gameover.setString("GameOver!!!");
	gameover.setPosition(300, 300);

	youWin.setString("You win!!!");
	youWin.setPosition(300, 300);

	scoreText.setPosition(165, 5);

	livesText.setString("Lives:");
	livesText.setPosition(580, 5);

	//Second Window
	firstControls.setFont(gameFont);
	firstControls.setCharacterSize(14);
	firstControls.setString("Press A to increase player speed or D to decrease it");
	firstControls.setPosition(10, 10);

	score = 0;

	//Pointer objects
	playerBullet = nullptr;
	invaderBullet = nullptr;
	bonusShip = nullptr;
	player1 = nullptr;
}

void Game::start()
{

	player1 = new Player;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			invaderArmy.push_back(new Enemies(30 * (j + 1), 30 * (i + 3)));
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bunker1.push_back(new Bunker(20 *   (j + 18), 25 * (i + 17)));
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bunker1.push_back(new Bunker(20 * (j + 5), 25 * (i + 17)));
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bunker1.push_back(new Bunker(20 * (j + 30), 25 * (i + 17)));
		}
	}
}

void Game::Delete()
{
	delete player1;
	player1 = nullptr;

	if (invaderBullet != nullptr)
	{
		delete invaderBullet;
		invaderBullet = nullptr;
	}

	if (bonusShip != nullptr)
	{
		delete bonusShip;
		bonusShip = nullptr;
	}

	if (playerBullet != nullptr)
	{
		delete playerBullet;
		playerBullet = nullptr;
	}


	for (int i = 0; i < invaderArmy.size(); i++)
	{
		delete invaderArmy[i];
	}

	for (int i = 0; i < bunker1.size(); i++)
	{
		delete bunker1[i];
	}

	bunker1.clear();

	invaderArmy.clear();

	clock = 0;
	alienSpawnBullet = 0;
	spawnBonusShip = 0;
	score = 0;
}

void Game::run()
{
	while (gameWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;

	while (gameWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			gameWindow.close();
		}

		if (state == main_menu)
		{
			if (event.KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					start();
					state = playing;
				}
			}
		}

		if (state == game_over)
		{
			if (event.KeyPressed)
			{
				if (event.key.code == sf::Keyboard::R)
				{
					Delete();
					if (invaders.size() == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							rect.setSize(sf::Vector2f(20, 20));
							rect.setFillColor(sf::Color::Cyan);
							rect.setPosition(sf::Vector2f(30 * (i + 23.5), 16));
							invaders.push_back(rect);
						}
					}
					state = main_menu;
				}
			}
		}

		if (state == you_win)
		{
			if (event.KeyPressed)
			{
				if (event.key.code == sf::Keyboard::R)
				{
					Delete();
					if (invaders.size() == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							rect.setSize(sf::Vector2f(20, 20));
							rect.setFillColor(sf::Color::Cyan);
							rect.setPosition(sf::Vector2f(30 * (i + 23.5), 16));
							invaders.push_back(rect);
						}
					}
					state = main_menu;
				}
			}
		}

		if (state == playing)
		{
			if (event.KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Z)
				{
					if (!player1->isShooting())
					{
						playerBullet = new Bullet(player1->getShape().getPosition().x, player1->getShape().getPosition().y);
						player1->SetShooting();
					}
				}

				if (event.key.code == sf::Keyboard::Escape)
				{
					secondWindow = new sf::RenderWindow(sf::VideoMode(550, 400, 32), "Debug Window");
					state = paused;
				}

			}
		}

	}

}

void Game::update()
{
	std::stringstream s;
	s << score;
	scoreText.setString(s.str());

	if (state == playing)
	{
		if (invaderArmy.size() == 0)
		{
			state = you_win;
		}

		clock += 0.05f;
		alienSpawnBullet += 0.05f;

		if(bonusShip == nullptr)
		spawnBonusShip += 0.05f;

		if (invaders.size() == 0)
		{
			state = game_over;
		}

		//Enemy movements
		for (int i = 0; i < invaderArmy.size(); i++)
		{
			invaderArmy[i]->updateInvaders();

			if (invaderArmy[i]->getShape().getPosition().y > 500)
			{
				state = game_over;
			}
		}

		//Every 7.5 seconds the aliens will switch directions and drop down
		if (clock > timerDrop)
		{
			for (int i = 0; i < invaderArmy.size(); i++)
			{
				invaderArmy[i]->dropDown();
				invaderArmy[i]->stopMoving();
			}

			clock = 0;
		}

		if (alienSpawnBullet > 5)
		{
			if (invaderArmy.size() > 0)
			{
				int result = (rand() % invaderArmy.size()) + 0;

				invaderBullet = new Bullet(invaderArmy[result]->getShape().getPosition().x, invaderArmy[result]->getShape().getPosition().y);
			}

			alienSpawnBullet = 0;
		}

		if (spawnBonusShip > 20)
		{
			bonusShip = new MysteryShip();

			spawnBonusShip = 0;
		}

		if (playerBullet != nullptr && bonusShip != nullptr)
		{
			if (playerBullet->getBulletShape().getGlobalBounds().intersects(bonusShip->getMystery().getGlobalBounds()))
			{
				delete bonusShip;
				bonusShip = nullptr;
				delete playerBullet;
				playerBullet = nullptr;
				player1->SetShooting();
				score += 100;
			}
		}

		if (bonusShip != nullptr)
		{
			bonusShip->updateMystery();

			if (bonusShip->getMystery().getPosition().x < -20)
			{
				delete bonusShip;
				bonusShip = nullptr;
			}
		}

		if (invaderBullet != nullptr)
		{
			invaderBullet->enemyBullet();

			if (invaderBullet->collisionBottomScreen())
			{
				delete invaderBullet;
				invaderBullet = nullptr;
			}

			else if (invaderBullet->getBulletShape().getGlobalBounds().intersects(player1->getShape().getGlobalBounds()))
			{
				delete invaderBullet;
				invaderBullet = nullptr;
				invaders.pop_back();
			}

			else
			{
				for (int i = 0; i < bunker1.size(); i++)
				{
					if (invaderBullet->getBulletShape().getGlobalBounds().intersects(bunker1[i]->getBunker().getGlobalBounds()))
					{
						delete invaderBullet;
						invaderBullet = nullptr;
						bunker1.erase(bunker1.begin() + i);
						break;
					}
				}
			}
		}

		//Bullet Updates if bullet exist
		if (playerBullet != nullptr)
		{
			playerBullet->update();

			//If collides at the bottom of the screen delete bullet
			if (playerBullet->collisionBottomScreen())
			{
				delete playerBullet;
				playerBullet = nullptr;
				player1->SetShooting();
			}

			else
			{
				for (int i = 0; i < invaderArmy.size(); i++)
				{
					if (playerBullet->getBulletShape().getGlobalBounds().intersects(invaderArmy[i]->getShape().getGlobalBounds()) && playerBullet != nullptr)
					{
						delete playerBullet;
						playerBullet = nullptr;
						score += 10;
						player1->SetShooting();
						invaderArmy.erase(invaderArmy.begin() + i);
						break;
					}
				}

				if (playerBullet != nullptr)
				{
					for (int i = 0; i < bunker1.size(); i++)
					{
						if (playerBullet->getBulletShape().getGlobalBounds().intersects(bunker1[i]->getBunker().getGlobalBounds()) && playerBullet != nullptr)
						{
							delete playerBullet;
							playerBullet = nullptr;
							player1->SetShooting();
							bunker1.erase(bunker1.begin() + i);
							break;
						}
					}
				}
			}
		}

		//Player Updates
		player1->handleInputs();
	}

	if (state == paused && secondWindow != nullptr)
	{
		while (secondWindow->isOpen())
		{
			sf::Event secondevents;

			while (secondWindow->pollEvent(secondevents))
			{
				if (secondevents.type == sf::Event::Closed)
				{
					secondWindow->close();
					state = playing;
				}

				if (secondevents.KeyPressed)
				{
					if (secondevents.key.code == sf::Keyboard::A)
					{
						player1->setMovement();
					}

					if (secondevents.key.code == sf::Keyboard::D)
					{
						player1->setMovementNegative();
					}
				}
			}

			secondWindow->clear();
			secondWindow->draw(firstControls);
			secondWindow->display();
		}
	}
}

void Game::render()
{
	gameWindow.clear();

	if (state == playing || state == paused)
	{
		for (unsigned i = 0; i < invaderArmy.size(); i++)
		{
			invaderArmy[i]->render(&gameWindow);
		}

		for (int i = 0; i < bunker1.size(); i++)
		{
			bunker1[i]->render(&gameWindow);
		}


		for (int i = 0; i < invaders.size(); i++)
		{
			gameWindow.draw(invaders[i]);
		}

		player1->render(&gameWindow);
		if (playerBullet != nullptr)
		{
			playerBullet->renderBullet(&gameWindow);
		}

		if (invaderBullet != nullptr)
		{
			invaderBullet->renderBullet(&gameWindow);
		}

		if (bonusShip != nullptr)
		{
			bonusShip->render(&gameWindow);
		}

		if (secondWindow != nullptr)
		{
			secondWindow->clear();
			secondWindow->display();
		}

		gameWindow.draw(menuText);
		gameWindow.draw(scoreText);
		gameWindow.draw(livesText);
	}

	if (state == main_menu)
	{
		gameWindow.draw(mainMenu);
	}

	if (state == game_over)
	{
		gameWindow.draw(gameover);
	}

	if (state == you_win)
	{
		gameWindow.draw(youWin);
	}

	gameWindow.display();
}

Game::~Game()
{
	delete invaderBullet;
	delete playerBullet;
	delete bonusShip;
	delete secondWindow;
	delete player1;
	for (int i = 0; i < invaderArmy.size(); i++)
	{
		delete invaderArmy[i];
	}

	for (int i = 0; i < bunker1.size(); i++)
	{
		delete bunker1[i];
	}
}
