//Included libraries
#include <sfml/Graphics.hpp> //Includes graphics
#include <SFML/Audio.hpp> //Includes audio
#include <string> //Include strings
#include <ctime> //gives access to randomness funcs
#include <cstdlib>//gives access to randomness funcs

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

	///Randomness

	//Seed our random number generation
	srand(time(NULL));

	///Class

	//Create an instance of our critter class
	Critter myCritter;

	///Fonts/text
	//Score Tracking
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");
	
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(50, 50);


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

			//Process input on Critters
			myCritter.Input(gameEvent);

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

		//See if there is a pending score
		score += myCritter.getPendingScore();
		myCritter.ClearPendingScore();
		scoreText.setString("Score: " + std::to_string(score));

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
		gameWindow.draw(scoreText);

		//Display window contents to the screen
		gameWindow.display();

		///---------------------------------------------
		///END DRAW
		///---------------------------------------------

	}//End of game while loop

	//Exit point for program
	return 0;
}//end of main function
