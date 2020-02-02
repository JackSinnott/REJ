#include "Player.h"




Player::Player() : m_position{ 30.0f, 200.0f },
				   m_velocity(0.0f, 0.0f),
				   rotation(0.0f)
{
	if (!m_playerTexture.loadFromFile("Assets/IMAGES/sprite sheet.png"))
	{
		std::cout << "Problems Heuston" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerFrame = sf::IntRect(295, 167, 130, 130);
	m_playerSprite.setTextureRect(m_playerFrame);
	m_playerSprite.setPosition(m_position);
	m_playerSprite.setOrigin(m_playerFrame.width / 2, m_playerFrame.height / 2);
	m_playerSprite.setScale(1.0f, 1.0f);
}


Player::~Player()
{
}

void Player::update(sf::Time dt, Xbox360Controller* t_cont)
{
	m_playerSprite.setPosition(m_position);
	checkInput(t_cont);
	updatePlayerFrame();
	m_playerSprite.setTextureRect(m_playerFrame);
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
		
	m_playerSprite.rotate(10);
			
	}
	else if (walkLeft == true)
	{
		m_playerSprite.rotate(-10);
	}
	else
	{
		rotation = m_playerSprite.getRotation();
		if (rotation == 0)
		{

		}
		else if (rotation > 180)
		{
			m_playerSprite.rotate(10);
		}
		else if (rotation < 359)
		{
			m_playerSprite.rotate(-10);
		}
	}

	walkLeft = false;
	walkRight = false;
}

sf::Sprite * Player::getBody()
{
	return &m_playerSprite;
}

void Player::checkInput(Xbox360Controller* t_cont)
{

	if (t_cont->m_currentState.dPadRight == true || t_cont->m_currentState.leftThumbStick.x > 50)
	{
		this->move(sf::Vector2f{ 10, 0 });
		walkRight = true;
	}
	if (t_cont->m_currentState.dPadLeft == true || t_cont->m_currentState.leftThumbStick.x < -50)
	{

		this->move(sf::Vector2f{ -10, 0 });
		walkLeft = true;

	}
	
	if (t_cont->m_currentState.rTrigger > 50 && t_cont->m_previousState.rTrigger < 50)
	{
		m_playerFrame.left = m_playerFrame.left - m_playerFrame.width;

		if (firstLoop == true && m_playerFrame.left <= 0)
		{
			firstLoop = false;
			secondLoop = true;
			m_playerFrame.left = 295;
		}
		if (secondLoop == true && m_playerFrame.left <= 0)
		{
			secondLoop = false;
			thirdLoop = true;
			m_playerFrame.left = 295;
		}
		if (thirdLoop == true && m_playerFrame.left <= 0)
		{
			firstLoop = true;
			secondLoop = false;
			m_playerFrame.left = 295;
		}

		if (firstLoop == true)
		{
			m_playerFrame.top = 167;
		}
		else if (secondLoop == true)
		{
			m_playerFrame.top = 308;
		}
		else if (thirdLoop == true)
		{
			m_playerFrame.top = 630;
		}
		
	}
	if (t_cont->m_currentState.lTrigger < -50 && t_cont->m_previousState.lTrigger > -50)
	{
		m_playerFrame.left = m_playerFrame.left + m_playerFrame.width;
	
		if (firstLoop == true && m_playerFrame.left >= 295)
		{
			firstLoop = false;
			secondLoop = true;
			m_playerFrame.left = 5;
		}
		if (secondLoop == true && m_playerFrame.left >= 295)
		{
			secondLoop = false;
			thirdLoop = true;
			m_playerFrame.left = 5;
		}
		if (thirdLoop == true && m_playerFrame.left >= 295)
		{
			firstLoop = true;
			secondLoop = false;
			m_playerFrame.left = 5;
		}

		if (firstLoop == true)
		{
			m_playerFrame.top = 167;
		}
		else if (secondLoop == true)
		{
			m_playerFrame.top = 308;
		}
		else if (thirdLoop == true)
		{
			m_playerFrame.top = 630;
		}
	}
	t_cont->m_previousState = t_cont->m_currentState;
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
