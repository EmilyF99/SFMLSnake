#pragma once
#include "Textbox.h"

enum states {
	STATE_START,
	STATE_PLAY,
	STATE_GAME_OVER
};

class States {
public:
	void StateControl(states m_currentState);
	void GameStart();
	void GamePlay();
	void GameOver();
private:
	states m_currentState;
	Textbox m_textbox;
};