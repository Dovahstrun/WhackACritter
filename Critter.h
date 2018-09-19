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

	///-------------------------------------------------
	///END BEHAVIOUR
	///-------------------------------------------------


	///-------------------------------------------------
	///DATA
	///-------------------------------------------------



	///-------------------------------------------------
	///END DATA
	///-------------------------------------------------
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

}; //End Critter class