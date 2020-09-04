/*	Word Guessing Game
 *	By: Joey Sachtleben
 *	Class: Principles of Computer Science II aka CSC 1820-01
 *	Programming Assignment 1
 * 
 *	A word guessing game in the same vein as Hangman. Images are too fancy for us so it doesn't have one. Hopefully meets the requirements in the PDF.
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

std::ifstream openFile(std::string fileName)
{
	std::ifstream file{ fileName };

	if (!file)
	{
		std::cerr << "The file " << fileName << " could not be opened.\n";
		std::cerr << "Please enter a new filename, or type \"exit\" to exit the program.\n";
		std::string input;
		std::cin >> input;
		if (input != "exit" )
		{
			file = openFile(input);
		}
		else
		{
			std::exit(EXIT_FAILURE);
		}
	}

	return file;
}

int main()
{
	std::string wordFileName{ "words.txt" };
	std::ifstream wordsFile{ openFile(wordFileName) };

	while (wordsFile)
	{
		std::string fileText{};
		wordsFile >> fileText;
		std::cout << fileText << "\n";
	}

	return 0;
}