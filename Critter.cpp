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
{
	m_texture.loadFromFile("graphics/elephant.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width, rand() % sf::VideoMode::getDesktopMode().height);

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

			}
		}//End if event statement
	}
}