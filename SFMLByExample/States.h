#pragma once

enum states {
	STATE_START,
	STATE_PLAY,
	STATE_GAME_OVER
};

class States {
public:
	void StateControl();
	void GameStart();
	void GamePlay();
	void GameOver();
private:
	states m_currentState;
};