//Included libraries
#include <sfml/Graphics.hpp> //Includes graphics
#include <SFML/Audio.hpp> //Includes audio
#include <string> //Include strings

//Project includes
#include "Critter.h"

int main()
{
	///-------------------------------------------------
	///SETUP
	///-------------------------------------------------

	//Make a variable called gameWindow of type renderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", sf::Style::Titlebar | sf::Style::Close);

	///Time

	//Create time variable
	sf::Clock gameClock;

	///Class

	//Create an instance of our critter class
	Critter myCritter;


	///-------------------------------------------------
	///Game Loop
	///-------------------------------------------------
	while (gameWindow.isOpen())
	{
		///---------------------------------------------
		///INPUT
		///---------------------------------------------

		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			//Process Events

			//Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				//Close the game window
				gameWindow.close();
			}//End Closed event
		}//End input polling while loop

		///---------------------------------------------
		///END INPUT
		///---------------------------------------------



		///---------------------------------------------
		///UPDATE
		///---------------------------------------------

		sf::Time frameTime = gameClock.restart();

		///---------------------------------------------
		///END UPDATE
		///---------------------------------------------



		///---------------------------------------------
		///DRAW
		///---------------------------------------------

		//Clear window to a single colour
		gameWindow.clear(sf::Color::Magenta);

		//Draw everything
		myCritter.Draw(gameWindow);

		//Display window contents to the screen
		gameWindow.display();

		///---------------------------------------------
		///END DRAW
		///---------------------------------------------

	}//End of game while loop

	//Exit point for program
	return 0;
}//end of main function
