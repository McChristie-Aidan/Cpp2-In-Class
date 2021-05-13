#include "FileData.h"
#include <iostream>
#include <vector>
#include <string>

void FileData::printRow(int rowNumber)
{
    //lets me know what the input is
    std::cout << "printing line : " << rowNumber << std::endl;

    int correctedRowNum = rowNumber;

    if (correctedRowNum <= 0)
    {
        correctedRowNum = 0;
    }
    else
    {
    correctedRowNum -= 1;
    }       

    std::cout << "corrected number" << std::endl;

    for (size_t i = 0; i < rows[correctedRowNum].size(); i++)
    {
        std::cout << rows[correctedRowNum][i] << std::endl;
    }       
}

std::vector<std::string> FileData::GetColumn(int columnNum)
{
    //lets me know what the input is
    //std::cout << "printing line : " << rowNumber << std::endl;

    int correctedColumnNum = columnNum;
    std::vector<std::string> temp;

    if (correctedColumnNum <= 0)
    {
        correctedColumnNum = 0;
    }
    else
    {
        correctedColumnNum -= 1;
    }       


    //seg fault here i need to fix
    //for (size_t i = 0; i < rows.size(); i++)
    for (size_t i = 0; i < 219747; i++)
    {
        std::cout << "printing row " << i << " : " << rows[i][correctedColumnNum] << std::endl;
        temp.push_back(rows[i][correctedColumnNum]);
    }      

    std::cout << "returning column" << std::endl;

    return temp;
}
