#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include "FileData.h"

std::string targetFile = "Food_Inspections.csv";
int columNumber = 4;

FileData myData;

void CompileColumnToMap(std::vector<std::string> column) 
{
    std::map<std::string, int> map;

    std::cout << "map created" << std::endl; 

    for (size_t i = 0; i < column.size(); i++)
    {
        
        if (map.count(column[i]))
        {
            map[column[i]] += 1;
        }
        else
        {
            map[column[i]] = 1;
        }
        
    }

    std::cout << "reading map" << std::endl;

    for (auto item : map)
    {
        std::cout << item.first << " appears ";

        std::cout << item.second << " times" << std::endl;
    }
}

FileData ReadCSVToObject(std::string fileName)
{   
    std::ifstream myFile;
    FileData fileData;

    std::vector<std::vector<std::string>> r;

    fileData.rows = r;

    myFile.open(fileName);

    while (myFile.good())
    {
        std::string line;
        getline(myFile, line);
                
        //int count;

        //print this to vector instead of console
        //std::cout << "line number : " << ++count << std::endl;

        std::stringstream ss(line);

        std::vector<std::string> currentRow;      
        

        // while (ss >> std::ws)
        // {
        //     std::string columnValue;

        //     if (ss.peek() == '"')
        //     {0
        //         //no c++14 :(
        //         ss >> std::quoted(columnValue);
        //         std::string discard;
        //         std::getline(ss, discard, ',');
        //     }
        //     else
        //     {
        //         std::getline(ss, columnValue, ',');
        //     }
            
        //     currentRow.push_back(columnValue);
        // }
        
        //fix this to parse the quotes as well
        //fixing this would probably make everything work right.
        while (ss.good())
        {      
            std::string columnValue;

            getline(ss >> std::ws, columnValue, ',');
            
            //print this to vector instead of console
            //std::cout << columnValue << std::endl;

            currentRow.push_back(columnValue);
        }

        fileData.rows.push_back(currentRow);
    }  

    // while (myFile.good())
    // {
    //    std::string line;
    //    getline(myFile, line, ',');
    //    std::cout << line << std::endl;
    // }
    
    myFile.close();
    return fileData;
}

int main()
{
    myData = ReadCSVToObject(targetFile);

    //myData.printRow(219747);
   
    std::cout << "csv reading complete" << std::endl;
    
    CompileColumnToMap(myData.GetColumn(6));

    return 0;
}