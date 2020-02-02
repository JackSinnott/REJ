#include "Player.h"




Player::Player() : m_position{ 30.0f, 200.0f },
				   m_velocity(0.0f, 0.0f),
				   rotation(0.0f)
{
	if (!m_playerTexture.loadFromFile("Assets/IMAGES/mdh.png"))
	{
		std::cout << "Problems Heuston" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setPosition(m_position);
	m_playerSprite.setOrigin(m_playerTexture.getSize().x / 2, m_playerTexture.getSize().y / 2);
	m_playerSprite.setScale(0.1f, 0.1f);
}


Player::~Player()
{
}

void Player::update(sf::Time dt, Xbox360Controller* t_cont)
{
	m_playerSprite.setPosition(m_position);
	checkInput(t_cont);
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
		
	}
	if (t_cont->m_currentState.lTrigger < -50 && t_cont->m_previousState.lTrigger > -50)
	{
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
