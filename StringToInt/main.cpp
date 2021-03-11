#include <iostream>
#include <string>

int stringToInt(std::string s);

std::string input;

int main()
{
    std::cout << "enter a string to convert into an int" << std::endl;
    std::cin >> input;
    std::cout << "the answer is:" << stringToInt(input) << std::endl;
}

int stringToInt(std::string s)
{
    int currentChar = 0;
    int sign = 1;
    int result = 0;
    
    //debug
    //std::cout << "checking for space" << std::endl;
    while (currentChar < s.length() && s.at(currentChar) == ' ')
    {

        std::cout << "found a space" << std::endl;
        currentChar++;
    }
    
    //debug
    //std::cout << "checking for signs" << std::endl;
    if (currentChar < s.length() && (s.at(currentChar) == '+' || s.at(currentChar) == '-'))
    {
        if (s.at(currentChar) == '+')
        {
            std::cout << "found a positive" << std::endl;
            sign = 1;
        }
        if (s.at(currentChar) == '-')
        {
            std::cout << "found a negative" << std::endl;
            sign = -1;
        }
        currentChar++;
    }
    
    //debug
    //std::cout << "checking for overflow" << std::endl;
    while (currentChar < s.length() && (s.at(currentChar) >= '0' && s.at(currentChar) <= '9'))
    {
        if (result > INT32_MAX / 10 || 
        (result == INT32_MAX / 10 && s.at(currentChar) - '0' > INT32_MAX % 10))
        {
            return (sign == 1)? INT32_MAX : INT32_MIN;
        }

        result = result * 10 + (s.at(currentChar) - '0');
        std::cout << "the current result is: " << result * sign << std::endl;
        currentChar++;
    }
    return result * sign;
}