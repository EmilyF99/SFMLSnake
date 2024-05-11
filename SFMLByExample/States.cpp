#include "States.h"
#include <iostream>

void States::StateControl(states m_currentState)
{
	//Space for switch that controls game state
	switch (m_currentState)
	{
	case STATE_START:
		GameStart();
		break;
	case STATE_PLAY:
		GamePlay();
		break;
	case STATE_GAME_OVER:
		GameOver();
		break;
	}
}

void States::GameStart()
{
	std::cout << "\nGame Start";
	//m_file.LocateFile();
	
	//blank start screen and text box draw 
	//handle input for start (Such as press space to start) 

}

void States::GamePlay()
{
	std::cout << "\nGame Play";
	//code that calls the main game 
	//m_game.InitialTextBoxSetup();
}

void States::GameOver()
{
	std::cout << "\nGame Over";
	//Shows a game over text box
	//Shows the score list 
}