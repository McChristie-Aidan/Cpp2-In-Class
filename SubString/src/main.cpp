#include <iostream>
#include <set>
#include <cmath>

std::string s;

int shortestSubString(std::string s);

void main()
{
    std::cout << "Please enter a string";

    std::cin >> s;
    std::cout << shortestSubString(s);
}

int shortestSubString(std::string s)
{
    std::set<char> window;

    int frontLetter = 0;
    int backLetter = 0;
    int longestStreak = 0;

    //so i dont have to find the length twice every time
    int stringLength = s.length();

    while (frontLetter < stringLength && backLetter < stringLength)
    {
        if(window.find(s.at(backLetter)) != window.end())
        {
            window.emplace(s.at(backLetter));
            backLetter++;

            longestStreak = std::max(longestStreak, backLetter - frontLetter);
        }
        else
        {
            window.erase(s.at(frontLetter));
            frontLetter++;
        }
    }

    return longestStreak;
}