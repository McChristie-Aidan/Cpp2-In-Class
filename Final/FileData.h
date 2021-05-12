#pragma once
#include <vector>
#include <string>

struct FileData
{
    std::vector<std::vector<std::string>> rows;

    void printRow(int row);
    std::vector<std::string> GetColumn(int column);
};
