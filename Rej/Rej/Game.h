#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Xbox360Controller.h"
#include "NPC.h"
#include <vector>
#include <array>
#include "Zombie.h"



class Game
{
public:
	Game();
	~Game();
	void run();
	

protected:
	void intialize();
	void update(sf::Time t_deltaTime);
	void processInput();
	void render();
	void checkButtonInput(Xbox360Controller * t_cont);

	sf::RenderWindow m_renderWin;
	Xbox360Controller m_gameController;
	sf::View m_gameCamera;

	Player m_player;

	sf::Sprite m_floorSprite;
	sf::Texture m_floorTexture;
	sf::Sprite m_grounds[4];

	sf::Sprite m_skySprite;
	sf::Texture m_skyTexture;

	sf::Sprite m_carSprite;
	sf::Texture m_carTexture;

	sf::IntRect m_carFrame;

	sf::Sprite m_builderSprite;
	sf::Texture m_builderTexture;

	sf::IntRect m_builderFrame;

	int index = 0;

	int timer = 0;

	int animationTimer = 0;
	std::array<NPC, 10> m_soliders;
	std::array<Zombie, 20> m_zombie;
	
};

