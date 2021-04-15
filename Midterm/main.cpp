#include <iostream>
#include <vector>
#include <fstream>
#include <ios>
#include <string>

void ReadCSV()
{
    std::fstream fileIn;
    
    fileIn.open("sample.csv", std::ios::in);

    int rollnum, roll2, count = 0;
    std::cout << "enter the line number you want to display : ";
    std::cin >> rollnum;

    std::vector<std::string> row;
    std::string line, word, temp;

    while (fileIn >> temp)
    {
        row.clear();

        getline(fileIn, line);

        std::stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        
        roll2 = std::stoi(row[0]);

        if (roll2 == rollnum)
        {
            count = 1;
            std::cout << "Student Number: " << row[0] << " : \n";
            std::cout << "Student Name: " << row[1] << "\n";
            std::cout << "Student UserName: " << row[2] << "\n";
            std::cout << "Student Email: " << row[3] << "\n";
            break;
        }
        if (count == 0)
        {
            std::cout << "record not found \n";
        }
        
    }
    
}

int main()
{

    return 0;
}