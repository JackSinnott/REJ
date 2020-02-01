#include "Player.h"



Player::Player() : m_position{ 30.0f, 580.0f },
				   m_velocity(0.0f, 0.0f)
{
	if (!m_playerTexture.loadFromFile("Assets/IMAGES/Solider_idle.png"))
	{
		std::cout << "Problems Heuston" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerFrame = sf::IntRect(0, 0, 22, 32);
	m_playerSprite.setTextureRect(m_playerFrame);
	m_playerSprite.setPosition(m_position);
	m_playerSprite.setOrigin(m_playerFrame.width / 2, m_playerFrame.height / 2);
	m_playerSprite.setScale(3.0f, 3.0f);
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
		//If the animation timer reached 0.
		if (animationTimer == 0)
		{
			
			//Jump to the next frame in line.
			m_playerFrame.left = m_playerFrame.left + m_playerFrame.width;

			//If we have reached the end of the sprite sheet we go back to the start.
			if (m_playerFrame.left == 66)
			{
				m_playerFrame.left = 0;
			}

			//Reset the animation timer back to max.
			animationTimer = 6;
		}
		animationTimer--;
	}
	else if (walkLeft == true)
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
	m_playerSprite.setTextureRect(m_playerFrame);
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

	if (t_cont->m_currentState.a == true && t_cont->m_previousState.a != true)
	{
		
		
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
	return m_playerSprite.getPosition();
}

void Player::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

void Player::pushBackToPrevious()
{
	m_playerSprite.setPosition(m_previousPos);
}
