#include "Player.h"



Player::Player() : m_position{ 10.0f, 15.0f },
				   m_velocity(0.0f, 0.0f)
{
	if (!m_playerTexture.loadFromFile("Assets/IMAGES/Solider_idle.png"))
	{
		std::cout << "Problems Heuston" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerFrame = sf::IntRect(0, 0, 22, 65);
	m_playerSprite.setTextureRect(m_playerFrame);
	m_playerSprite.setPosition(m_position);
	m_playerSprite.setOrigin(m_playerFrame.width / 2, m_playerFrame.height / 2);
}


Player::~Player()
{
}

void Player::update(sf::Time dt)
{
	updatePlayerFrame();
}

void Player::render(sf::RenderWindow & t_win)
{
	t_win.draw(m_playerSprite);
}

void Player::move(MyVector3 t_movement)
{
	m_previousPos = m_position;
	m_position += sf::Vector2f{ t_movement };
}

void Player::updatePlayerFrame()
{
	if (walkRight == true)
	{
		if (animationTimer == 0)
		{
			if (m_playerFrame.left = 89)
			{
				m_playerFrame.left = 0;
			}
			m_playerFrame.left = m_playerFrame.left + m_playerFrame.width;

			m_playerFrame.top = 455;
		}

		animationTimer = 4;
	}
	else if (walkLeft == true)
	{
		if (animationTimer == 0)
		{
			if (m_playerFrame.left == 0)
			{
				m_playerFrame.left = 89;
			}
			m_playerFrame.left = m_playerFrame.left - m_playerFrame.width;
			animationTimer = 4;
		}
		animationTimer--;
	}
	else
	{
		if (animationTimer == 0)
		{
			if (m_playerFrame.left == 89)
			{
				m_playerFrame.left = 0;
			}
			m_playerFrame.left = m_playerFrame.left + m_playerFrame.width;
			m_playerFrame.top = 37;
			animationTimer = 4;
		}
		animationTimer--;
	}
	walkLeft = false;
	walkRight = false;
}

sf::Sprite * Player::getBody()
{
	return &m_playerSprite;
}

void Player::checkInput()
{
}

sf::Vector2f Player::getPosition()
{
	return m_playerSprite.getPosition();;
}

void Player::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

void Player::pushBackToPrevious()
{
	m_playerSprite.setPosition(m_previousPos);
}
