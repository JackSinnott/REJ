#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enum.h"
#include "Player.h"
#include "Xbox360Controller.h"

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
	Xbox360Controller m_gameController;
	sf::View m_gameCamera;

	Player m_player;

	sf::Sprite m_floorSprite;
	sf::Texture m_floorTexture;
	
};

