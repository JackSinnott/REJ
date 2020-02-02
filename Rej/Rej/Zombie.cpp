#include "Zombie.h"


Zombie::Zombie() : m_velocity(0.0f, 0.0f)

{
	if (!m_zombieTexture.loadFromFile("Assets/IMAGES/sprite sheet.png"))
	{
		std::cout << "Problems Heuston" << std::endl;
	}
	m_zombieSprite.setTexture(m_zombieTexture);
	m_zombieFrame = sf::IntRect(664, 140, 22, 48);
	m_zombieSprite.setTextureRect(m_zombieFrame);
	m_zombieSprite.setOrigin(m_zombieFrame.width / 2, m_zombieFrame.height / 2);
	m_zombieSprite.setScale(3.0f, 3.0f);
	m_zombieSprite.setPosition(900.0f, 1500.0f);

}




Zombie::~Zombie()
{
}

void Zombie::update(sf::Time dt)
{
	m_zombieSprite.setPosition(m_position);
	move(MyVector3{ -5,0,0 });
	updateZombieFrame();
}

void Zombie::render(sf::RenderWindow& t_win)
{
	t_win.draw(m_zombieSprite);
}

void Zombie::move(MyVector3 t_movement)
{
	m_previousPos = m_position;
	m_position += sf::Vector2f{ t_movement };
}

sf::Sprite* Zombie::getBody()
{
	return &m_zombieSprite;
}

sf::Vector2f Zombie::getPosition()
{
	return m_zombieSprite.getPosition();;
}

void Zombie::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}

void Zombie::pushBackToPrevious()
{
	m_zombieSprite.setPosition(m_previousPos);
}

void Zombie::setRandomPosition()
{
	randomPos = { static_cast<float>(1500 + rand() % (2000 -1500 + 1)), 580 };
	m_position = randomPos;
}

void Zombie::updateZombieFrame()
{

	if (animationTimer == 0)
	{
		if (m_zombieFrame.left >= 744)
		{
			m_zombieFrame.left = 664;
		}
		m_zombieFrame.left = m_zombieFrame.left + m_zombieFrame.width;
		animationTimer = 18;
	}
	animationTimer--;

	m_zombieSprite.setTextureRect(m_zombieFrame);

}


