#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enum.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void run();
	static GameState m_gameMode;

protected:
	void intialize();
	void update(sf::Time t_deltaTime);
	void processInput();
	void render();

	sf::RenderWindow m_renderWin;
	sf::View m_gameCamera;

	Player m_player;
};

