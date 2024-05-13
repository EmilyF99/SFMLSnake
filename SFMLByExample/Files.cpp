#include "defaultHeader.h"

#include "Files.h"


Files::Files(const std::string& fileName) : m_fileName(fileName)
{

}

Files::~Files(){}

void Files::CreateFile()
{
    std::ofstream file(m_fileName);
    // File created successfully
    std::cout << "File created: " << m_fileName << std::endl;
    file.close();
}

void Files::LocateFile()
{
    std::ifstream file(m_fileName);
    bool fileExists = file.good();
    file.close();
    std::cout << "File Found: " << m_fileName << std::endl;
    if (!fileExists)
    {
        CreateFile();
    }
}
void Files::AddScore(int score) {
    std::ofstream file;
    file.open(m_fileName, std::ios_base::app); // Open file in append mode
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file for appending: " << m_fileName << std::endl;
        return;
    }
    file << score << " "; 
    std::cout << "\nData added to file";
    file.close();
}
void Files::SearchScore()
{
    std::ifstream file(m_fileName);
    int score;

    std::vector<int> scores;
    while (file >> score) {
        scores.push_back(score);
    }
    file.close();

    std::sort(scores.rbegin(), scores.rend()); // Sort scores in descending order

    if (scores.size() > 5) {
        scores.erase(scores.begin() + 5, scores.end()); // Keep only the top 5 scores
    }

    SaveTopScores(scores);
}

void Files::SaveTopScores(const std::vector<int>& scores)
{
    std::ofstream file(m_fileName);
  
    for (int score : scores) {
        file << score << " ";
    }
    file.close();
}