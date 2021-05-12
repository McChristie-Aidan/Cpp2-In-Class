#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::string targetFile = "Food_Inspections.csv";
int columNumber = 4;

struct FileData
{
    std::vector<std::vector<std::string>> rows;   

    void printRow(int rowNumber)
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

    void printColumn(int columnNum)
    {
        //lets me know what the input is
        //std::cout << "printing line : " << rowNumber << std::endl;

        int correctedColumnNum = columnNum;

        if (correctedColumnNum <= 0)
        {
            correctedColumnNum = 0;
        }
        else
        {
            correctedColumnNum -= 1;
        }       

        for (size_t i = 0; i < rows.size(); i++)
        {
            std::cout << rows[i][correctedColumnNum] << std::endl;
        }       
    }
};


FileData readCSVToObject(std::string fileName)
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
                
        //print this to vector instead of console
        //std::cout << line << std::endl;

        std::stringstream ss(line);

        std::vector<std::string> currentRow;

        while (ss.good())
        {      
            std::string columnValue;

            getline(ss, columnValue, ',');

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
    FileData myData = readCSVToObject(targetFile);

    std::cout << "data read" << std::endl;

    myData.printRow(0);
    //myData.printColumn(6);
    return 0;
}