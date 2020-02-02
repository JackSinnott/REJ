#include "Game.h"

// Constructor

Game::Game() : m_renderWin{ sf::VideoMode{1200,800,1}, "REF"}
{
	// Load Textures here
	if (!m_floorTexture.loadFromFile("ASSETS/IMAGES/floor.png"))
	{
		std::cout << "Problemo" << std::endl;
	}
	m_floorSprite.setTexture(m_floorTexture);
	m_floorSprite.setOrigin(m_floorSprite.getGlobalBounds().width / 2, m_floorSprite.getGlobalBounds().height / 2);
	m_floorSprite.setPosition(0, 750);

	if (!m_carTexture.loadFromFile("ASSETS/IMAGES/sprite sheet.png"))
	{
		std::cout << "Why do you hate me so" << std::endl;
	}
	m_carSprite.setTexture(m_carTexture);
	m_carFrame = sf::IntRect(25, 28, 209, 86);
	m_carSprite.setTextureRect(m_carFrame);
	m_carSprite.setPosition(-1900, 600);
	m_carSprite.setScale(1.6f, 2.3f);
	m_builderSprite.setScale(4.0f, 4.0f);

	if (!m_builderTexture.loadFromFile("ASSETS/IMAGES/sprite sheet.png"))
	{
		std::cout << "AHHHHHHHHHHH" << std::endl;
	}
	m_builderSprite.setTexture(m_builderTexture);
	m_builderFrame = sf::IntRect(813, 56, 20, 38);
	m_builderSprite.setTextureRect(m_builderFrame);
	m_builderSprite.setPosition(-1950, 600);

	for (int i = 0; i < 4; i++)
	{
		m_grounds[i].setTexture(m_floorTexture);
		m_grounds[i].setOrigin(m_floorSprite.getGlobalBounds().width / 2, m_floorSprite.getGlobalBounds().height / 2);
		m_grounds[i].setPosition(0 + i * 3070, 750);
	}

	m_skyTexture.loadFromFile("ASSETS/IMAGES/dubSky.png");
	m_skySprite.setTexture(m_skyTexture);
	m_skySprite.setOrigin(m_skySprite.getGlobalBounds().width / 2, m_skySprite.getGlobalBounds().height / 2);
	m_skySprite.setPosition(m_floorSprite.getPosition().x, m_floorSprite.getPosition().y - (m_floorSprite.getGlobalBounds().height / 2 + m_skySprite.getGlobalBounds().height / 2) + 1);
	for (int i = 0; i < m_soliders.size(); i++)
	{
		m_soliders[i].setRandomPosition();
	}
	for (int i = 0; i < m_zombie.size(); i++)
	{
		m_zombie[i].setRandomPosition();
	}
	// initalize sf::view
	m_gameCamera.setSize(1200, 800);


}

// Destructor

Game::~Game()
{
}

// Loop designed to work at equal speed on all PCs 
// If a PC is slower, it will update the same amount of times
// and render less often
void Game::run()
{
	sf::Clock gameClock;
	sf::Time timeTakenForUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	while (m_renderWin.isOpen())
	{
		processInput();												// Check for input
		timeTakenForUpdate += gameClock.restart();
		while (timeTakenForUpdate > timePerFrame)					// Update enough times to catch up on updates missed during the lag time
		{
			timeTakenForUpdate -= timePerFrame;
			processInput();
			update(timePerFrame);
		}
		render();
	}
	 
}

void Game::intialize()
{
}

void Game::update(sf::Time t_deltaTime)
{
	
	m_gameController.update();
	for (int i = 0; i < m_soliders.size(); i++)
	{
		m_soliders[i].update(t_deltaTime);
	}
	for (int i = 0; i < m_zombie.size(); i++)
	{
		m_zombie[i].update(t_deltaTime);
	}

	m_player.update(t_deltaTime, &m_gameController);
	
	checkButtonInput(&m_gameController);
	m_gameCamera.setCenter(sf::Vector2f{ m_player.getPosition().x, m_player.getPosition().y + 200 });

	if (animationTimer == 0)
	{
		if (m_builderFrame.left == 833)
		{
			m_builderFrame.left = 813;
		}
		m_builderFrame.left = m_builderFrame.left + m_builderFrame.width;
		animationTimer = 18;
	}
	animationTimer--;

	m_builderSprite.setTextureRect(m_builderFrame);
}

void Game::processInput()
{
	sf::Event event;
	while (m_renderWin.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_renderWin.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_renderWin.close();
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
		}
	}
}

void Game::render()
{
	m_renderWin.clear(sf::Color::White);
	m_renderWin.draw(m_floorSprite);

	m_renderWin.setView(m_gameCamera);

	for (int i = 0; i < 4; i++)
	{
		m_renderWin.draw(m_grounds[i]);
	}
	
	for (int i = 0; i < 3; i++)
	{
		m_renderWin.draw(m_skySprite);
		m_skySprite.setPosition(m_skySprite.getPosition().x + m_skySprite.getGlobalBounds().width, m_skySprite.getPosition().y);
	}
	
	m_skySprite.setPosition(m_floorSprite.getPosition().x, m_floorSprite.getPosition().y - (m_floorSprite.getGlobalBounds().height / 2 + m_skySprite.getGlobalBounds().height / 2) + 1); // Reset

	for (auto& npc : m_soliders)
	{
		m_renderWin.draw(*npc.getBody());
	}
	for (auto& zom : m_zombie)
	{
		m_renderWin.draw(*zom.getBody());
	}
	
	m_renderWin.draw(m_carSprite);
	m_renderWin.draw(m_builderSprite);

	m_player.render(m_renderWin);
	m_renderWin.display();
}

void Game::checkButtonInput(Xbox360Controller * t_cont)
{
	

	if (t_cont->m_currentState.a == true && timer == 0)
	{
		m_soliders[index].areWeMoving();
		timer = 15;
		if (index < 9)
		{
			index++;
		}
	}
	if (timer > 0)
	{
		timer--;
	}
	
}
