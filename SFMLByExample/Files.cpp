#include "Files.h"
#include <fstream>
#include <iostream>

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
    std::ofstream file(m_fileName, std::ios_base::app); // Open file in append mode
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file for appending: " << m_fileName << std::endl;
        return;
    }
    file << score << " "; 
    file.close();
}
void SearchScore();