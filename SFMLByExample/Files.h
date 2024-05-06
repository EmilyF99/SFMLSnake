#pragma once
#include <string>

class Files
{
public:
	Files(const std::string& fileName);
	~Files();
	void CreateFile();
	void LocateFile();
	void AddScore(int score);
	void SearchScore();
	const std::string& GetFileName() const { return m_fileName; }
private:
	std::string m_fileName = "scores.txt";
};

