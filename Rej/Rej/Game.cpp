#include "Game.h"

// Constructor

GameState Game::m_gameMode{ GameState::Gameplay };

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
	// initalize sf::view
	//m_gameCamera.setSize(1200, 800);
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
	m_player.update(t_deltaTime, &m_gameController);
	//m_gameCamera.setCenter(sf::Vector2f{ m_player.getPosition().x, m_player.getPosition().y - 300 });
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
	//m_renderWin.setView(m_gameCamera);
	m_renderWin.draw(m_floorSprite);
	m_player.render(m_renderWin);
	m_renderWin.display();
}
