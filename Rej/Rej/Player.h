#pragma once

#include "SFML/Graphics.hpp"
#include "MyVector3.h"

class Player
{
public:
	Player();
	~Player();
	void update(sf::Time dt);
	void render(sf::RenderWindow & t_win);
	void move(MyVector3 t_movement);
	void jump();
	void updatePlayerFrame();
	sf::Sprite* getBody();
	void checkInput();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void pushBackToPrevious();

private:
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;

	sf::Vector2f m_gravity;
	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::Vector2f m_previousPos;

	sf::IntRect m_playerFrame;

	bool walkLeft{ false };
	bool walkRight{ false };

	int animationTimer{ 0 };
};

