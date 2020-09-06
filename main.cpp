/*	Word Guessing Game
 *	By: Joey Sachtleben
 *	Class: Principles of Computer Science II aka CSC 1820-01
 *	Programming Assignment 1
 * 
 *	A word guessing game in the same vein as Hangman. Images are too fancy for us so it doesn't have one. Hopefully meets the requirements in the PDF.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

#include "myrandom.h"
#include "gameloop.h"


/*	openFile
 *	Opens a file and returns the handle for reading. If the supplied filename cannot be opened, prompts the user to either provide a new filename or to terminate the program.
 * 
 *	Parameter:
 *	std::string fileName -- a string containing the file name to try and open
 * 
 *	Return:
 *	Returns an std::ifstream with the read handle of the opened file
 */
std::ifstream openFile(std::string fileName)
{
	std::ifstream file{ fileName };

	if (!file)
	{
		std::cerr << "The file " << fileName << " could not be opened.\n";
		std::cerr << "Please enter a new filename, or type \"exit\" to exit the program." << std::endl;
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

	std::vector<std::string> wordsList;

	while (wordsFile) // loop through the file and put all of the words into wordsList
	{
		std::string fileText{};
		wordsFile >> fileText;
		wordsList.push_back(fileText);
	}

	// Some introductry text for the player
	std::cout << std::endl;
	std::cout << "Welcome to WordGuess: the exciting word guessing game!\n";
	std::cout << "You will be shown a series of blank spaces representing letters in a word. Guess the letters, and when you're ready, try guessing the whole word!\n";
	std::cout << "But beware, if you make more than 6 wrong guesses, then you will lose!\n";

	bool playAGame{ true };

	while (playAGame)
	{
		CurrentWord roundWord{ getRandomWord(wordsList) };
		play(roundWord);
		playAGame = false;
	}

	return 0;
}