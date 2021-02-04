// PalindromeNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int palNum;

void CheckPalindrome(int palNum);

int main()
{
	std::cout << "Hello World! Please enter an int\n";

	std::cin >> palNum;

	CheckPalindrome(palNum);

}

void CheckPalindrome(int palNum)
{
	if (palNum < 0)
	{
		std::cout << "all negative numbers are NOT palindromes\n";
		return;
	}
	else if (palNum % 10 == 0 && palNum !=0)
	{
		std::cout << "a number that ends in zero can NOT be a palindrome\n";
		return;
	}

	int backHalf = 0;
	while (palNum > backHalf)
	{
		backHalf = backHalf * 10 + palNum % 10;
		palNum /= 10;
	}

	if (palNum == backHalf || palNum == backHalf / 10)
	{
		std::cout << "the number IS a palindrome!\n";
		return;
	}
	
	std::cout << "the number is NOT a palindrome\n";
}
