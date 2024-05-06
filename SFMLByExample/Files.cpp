#include "Files.h"
#include <fstream>
#include <iostream>

Files::Files() 
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
void addScore();
void searchScore();