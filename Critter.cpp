//Included libraries

//Project Includes
#include "Critter.h"

Critter::Critter()
//Initialisation list
	: m_sprite()
	, m_texture()
{
	m_texture.loadFromFile("graphics/elephant.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(300, 300);
}

void Critter::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}