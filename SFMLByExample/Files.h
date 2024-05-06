#pragma once
#include <string>

class Files
{
public:
	Files();
	~Files();
	void CreateFile();
	void LocateFile();
	void addScore();
	void searchScore();
private:
	std::string m_fileName = "scores.txt";
	std::string m_scoreToAdd;
};

