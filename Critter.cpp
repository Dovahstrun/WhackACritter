//Included libraries
#include <cstdlib>

//Project Includes
#include "Critter.h"

Critter::Critter()
//Initialisation list
	: m_sprite()
	, m_texture()
	, m_alive(true)
	, m_deathSound()
	, m_deathBuffer()
	, m_pendingScore(0)
	, m_scoreValue(1)
{
	
	//Setting up death sounds
	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathSound.setBuffer(m_deathBuffer);

}

void Critter::Draw(sf::RenderTarget& _target)
{
	if (m_alive)
	{
		_target.draw(m_sprite);
	}
}

void Critter::Input(sf::Event _gameEvent)
{
	//Only handle input if alive
	if (m_alive)
	{
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{
			//Did the click on the sprite
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{

				//We die
				m_alive = false;

				//Play death sound
				m_deathSound.play();

				//Add to pending score
				m_pendingScore += m_scoreValue;

			}
		}//End if event statement
	}
}

int Critter::getPendingScore()
{
	return m_pendingScore;
}

void Critter::ClearPendingScore()
{
	m_pendingScore = 0;
}

void Critter::Setup(std::string _textureFile, int _pointValue)
{
	m_texture.loadFromFile(_textureFile);//Load t
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition((rand() % sf::VideoMode::getDesktopMode().width - 2*m_sprite.getGlobalBounds().width) + m_sprite.getGlobalBounds().width, rand() % sf::VideoMode::getDesktopMode().height - m_sprite.getGlobalBounds().height);
	m_scoreValue = _pointValue;

}