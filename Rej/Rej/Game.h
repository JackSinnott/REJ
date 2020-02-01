#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enum.h"
#include "Player.h"
#include "Xbox360Controller.h"
#include "NPC.h"
#include <vector>

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
	//sf::View m_gameCamera;

	Player m_player;
	std::vector<NPC>(m_zombies);

	sf::Sprite m_floorSprite;
	sf::Texture m_floorTexture;
	sf::Sprite m_grounds[4];

	sf::Sprite m_skySprite;
	sf::Texture m_skyTexture;
	
};

