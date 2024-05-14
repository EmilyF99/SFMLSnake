#pragma once

class Files
{
public:
	Files(const std::string& fileName);
	~Files();
	void CreateFile();
	void LocateFile();
	void AddScore(int score);
	void SearchScore();
	void SaveTopScores(const std::vector<int>& scores);
	const std::string& GetFileName() const { return m_fileName; }
	std::vector<int> GetTopScores();
private:
	std::string m_fileName = "scores.txt";
};

