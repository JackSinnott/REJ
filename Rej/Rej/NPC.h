#pragma once

#include "SFML/Graphics.hpp"
#include "MyVector3.h"

class NPC
{
public:
	NPC();
	~NPC();
	void update(sf::Time dt);
	void render(sf::RenderWindow& t_win);
	void move(MyVector3 t_movement);
	sf::Sprite* getBody();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void pushBackToPrevious();

private:
	void updateNPCFrame();

	sf::Texture m_NPCTexture;
	sf::Sprite m_NPCSprite;

	sf::Vector2f m_velocity;
	sf::Vector2f m_position;
	sf::Vector2f m_previousPos;

	sf::IntRect m_playerFrame;

	bool spawned = true;

	int animationTimer{ 0 };
};

