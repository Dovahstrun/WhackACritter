#pragma once

//Included libraries
#include <sfml/Graphics.hpp> //Includes graphics
#include <SFML/Audio.hpp> //Includes audio
#include <string> //Include strings
//End libraries
class Critter
{

	///-------------------------------------------------
	///BEHAVIOUR
	///-------------------------------------------------
	
public:

	//Constructor
	Critter();

	//Render the Critter to the target
	void Draw(sf::RenderTarget& _target);

	//Process input on the Critter
	void Input(sf::Event _gameEvent);

	int getPendingScore();

	void ClearPendingScore();
	///-------------------------------------------------
	///END BEHAVIOUR
	///-------------------------------------------------


	///-------------------------------------------------
	///DATA
	///-------------------------------------------------

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;
	int m_pendingScore;

	///-------------------------------------------------
	///END DATA
	///-------------------------------------------------


}; //End Critter class