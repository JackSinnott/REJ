#pragma once

#include "SFML/Graphics.hpp"
#include "MyVector3.h"
#include <ctime>
#include <cstdlib>


class Zombie
{
public:
	Zombie();
	~Zombie();
	void update(sf::Time dt);
	void render(sf::RenderWindow& t_win);
	void move(MyVector3 t_movement);
	sf::Sprite* getBody();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void pushBackToPrevious();
	void setRandomPosition();

private:
	void updateZombieFrame();



	sf::Texture m_zombieTexture;
	sf::Sprite m_zombieSprite;

	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::Vector2f randomPos;
	sf::Vector2f m_previousPos;

	sf::IntRect m_zombieFrame;

	

	int animationTimer{ 0 };
};

