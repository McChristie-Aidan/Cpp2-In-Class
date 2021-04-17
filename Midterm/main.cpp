#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ios>
#include <string>

void ReadCSV()
{
    std::fstream fileIn;
    
    fileIn.open("sample.csv", std::ios::in);

    int rollnum, roll2, count = 0;
    std::cout << "enter the line number you want to display : ";
    std::cin >> rollnum;

    std::cout << "taken in imput" << std::endl;

    std::vector<std::string> row;
    std::string line, word, temp;

    std::cout << "initialized vector and strings" << std::endl;

    while (fileIn >> temp)
    {
        row.clear();

        getline(fileIn, line);

        std::stringstream s(line);

        std::cout << "initialized string stream" << std::endl;

        while (getline(s, word, ','))
        {
            row.push_back(word);
            std::cout << "Pushed back word" << std::endl;
        }
        
        roll2 = std::stoi(row[0]);

        std::cout << "completed stoi on row 0" << std::endl;

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
    ReadCSV();
    return 0;
}
