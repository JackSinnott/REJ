#pragma once

#include "SFML/Graphics.hpp"
#include "MyVector3.h"
#include "Xbox360Controller.h"
#include "NPC.h"
#include "Enum.h"
#include <queue>



class Player
{
public:
	Player();
	~Player();
	void update(sf::Time dt, Xbox360Controller * t_cont);
	void render(sf::RenderWindow & t_win);
	void move(MyVector3 t_movement);
	sf::Sprite* getBody();
	void checkInput(Xbox360Controller* t_cont);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void pushBackToPrevious();

private:
	void updatePlayerFrame();

	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;

	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::Vector2f m_previousPos;
	

	float rotation;
	bool walkLeft{ false };
	bool walkRight{ false };

	int animationTimer{ 0 };
};

