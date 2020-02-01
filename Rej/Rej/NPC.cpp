#include "NPC.h"


NPC::NPC() : m_position{ 100.0f, 580.0f },
m_velocity(0.0f, 0.0f)
{
	if (!m_NPCTexture.loadFromFile("Assets/IMAGES/Solider_idle.png"))
	{
		std::cout << "Problems Heuston" << std::endl;
	}
	m_NPCSprite.setTexture(m_NPCTexture);
	m_playerFrame = sf::IntRect(0, 0, 22, 32);
	m_NPCSprite.setTextureRect(m_playerFrame);
	m_NPCSprite.setPosition(m_position);
	m_NPCSprite.setOrigin(m_playerFrame.width / 2, m_playerFrame.height / 2);
	m_NPCSprite.setScale(3.0f, 3.0f);
}


NPC::~NPC()
{
}

void NPC::update(sf::Time dt)
{
	m_NPCSprite.setPosition(m_position);
	updateNPCFrame();
}

void NPC::render(sf::RenderWindow& t_win)
{
	t_win.draw(m_NPCSprite);
}

void NPC::move(MyVector3 t_movement)
{
	m_previousPos = m_position;
	m_position += sf::Vector2f{ t_movement };
}

sf::Sprite* NPC::getBody()
{
	return &m_NPCSprite;
}

sf::Vector2f NPC::getPosition()
{
	return m_NPCSprite.getPosition();;
}

void NPC::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

void NPC::pushBackToPrevious()
{
	m_NPCSprite.setPosition(m_previousPos);
}

void NPC::updateNPCFrame()
{
	
	if (spawned == true)
	{
		if (animationTimer == 0)
		{
			if (m_playerFrame.left == 0)
			{
				m_playerFrame.left = 66;
			}
			m_playerFrame.left = m_playerFrame.left - m_playerFrame.width;
			animationTimer = 6;
		}
		animationTimer--;
	}
	else
	{

	}
	m_NPCSprite.setTextureRect(m_playerFrame);
	spawned = false;
	
}