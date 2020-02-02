#include "NPC.h"


NPC::NPC() : m_velocity(0.0f, 0.0f)

{
	if (!m_NPCTexture.loadFromFile("Assets/IMAGES/sprite sheet.png"))
	{
		std::cout << "Problems Heuston" << std::endl;
	}
	m_NPCSprite.setTexture(m_NPCTexture);
	m_NPCFrame = sf::IntRect(425, 15, 25, 32);
	m_NPCSprite.setTextureRect(m_NPCFrame);
	m_NPCSprite.setOrigin(m_NPCFrame.width / 2, m_NPCFrame.height / 2);
	m_NPCSprite.setScale(3.0f, 3.0f);
	m_NPCSprite.setPosition(100.0f, 1500.0f);

}




NPC::~NPC()
{
}

void NPC::update(sf::Time dt)
{
	m_NPCSprite.setPosition(m_position);
	if (getMoving)
	{
		move(MyVector3{ 5,0,0 });
	}
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

	if (animationTimer == 0)
	{
		if (m_NPCFrame.left == 425)
		{
			m_NPCFrame.left = 500;
		}
		m_NPCFrame.left = m_NPCFrame.left - m_NPCFrame.width;
		animationTimer = 18;
	}
	animationTimer--;
	
	m_NPCSprite.setTextureRect(m_NPCFrame);

}

bool NPC::areWeMoving()
{
	if (!getMoving)
	{
		getMoving = true;
	}
	return getMoving;
}

void NPC::setRandomPosition()
{
	randomPos = { static_cast<float>(rand() % 100), 580 };
	m_position = randomPos;
}

