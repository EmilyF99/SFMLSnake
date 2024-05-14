#pragma once

class Files
{
public:
	Files(const std::string& fileName);
	~Files();
	void CreateFile() const;
	void LocateFile() const;
	void AddScore(int score) const;
	void SearchScore();
	void SaveTopScores(const std::vector<int>& scores);
	const std::string& GetFileName() const { return m_fileName; }
	std::vector<int> GetTopScores();
private:
	std::string m_fileName = "scores.txt";
};

