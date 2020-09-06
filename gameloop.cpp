/*	gameloop.cpp
 *	Contains functions related to the game loop and functionality
*/

#include <string>
#include <vector>
#include <iostream>

#include "myrandom.h"
#include "gameloop.h"

CurrentWord getRandomWord(std::vector<std::string> wordList)
{
	CurrentWord selectedWord{};
	int randomWordNumber{ getRandomInteger(0, wordList.size()) };
	selectedWord.word = wordList.at(randomWordNumber);
	for (size_t i = 0; i < selectedWord.word.length(); i++)
	{
		selectedWord.guess.append("*");
	}

    return selectedWord;
}

/*	letterGuess
 *	Checks a single-letter guess against the word to determine if it was correct or not. If it is correct, updates any matching letters in the guess to match.
 * 
 *	Parameters:
 *	CurrentWord& word -- the word to be comparing and the guess string
 *	std::string guess -- a string containing a single letter, the guess to check
 * 
 *	Return:
 *	Returns a boolean representing whether the guess was correct or not.
 */
bool letterGuess(CurrentWord& word, std::string guess)
{
	bool correctGuess{ false };
	for (size_t i = 0; i < word.word.length(); i++)
	{
		if (word.word.at(i) == guess.at(0))
		{
			word.guess.at(i) = guess.at(0);
			correctGuess = true;
		}
	}
	return correctGuess;
}

/*	wordGuess
 *	Checks a whole-word guess against the word to determine if it was correct or not.
 *
 *	Parameters:
 *	CurrentWord& word -- the word to be comparing and the guess string
 *	std::string guess -- a string containing the guess
 *
 *	Return:
 *	Returns a boolean representing whether the guess was correct or not.
 */
bool wordGuess(CurrentWord& word, std::string guess)
{
	bool correctGuess{ false };
	if (word.word == guess)
	{
		correctGuess = true;
	}
	return correctGuess;
}

void play(CurrentWord& word)
{
	std::cout << std::endl;

	int incorrectGuesses{ 0 };
	bool hasWon{ false };
	std::string guessedLetters{ "" };
	while (incorrectGuesses != 6 && (!hasWon))
	{
		std::cout << "So far, you have guessed: " << guessedLetters << "\n";

		std::cout << "The word is:   " << word.guess << "\n";
		std::cout << "Please enter your guess: ";

		std::string input{};
		std::cin >> input;

		if (input.length() == 1)
		{
			if (!letterGuess(word, input))
			{
				guessedLetters.append(input + " ");
				std::cout << "Sorry, " << input << "  is not in the word!\n";
				incorrectGuesses++;
			}
		}
		else if (input.length() == 0)
		{
			// Don't count a blank entry as a guess, just ignore it and ask for another guess
		}
		else
		{
			if (!wordGuess(word, input))
			{
				std::cout << "Sorry, " << input << " is not the word!\n";
				incorrectGuesses++;
			}
			else
			{
				hasWon = true;
			}
		}
		if (word.guess == word.word)
		{
			hasWon = true;
		}
	}
	if (hasWon)
	{
		std::cout << "Congrats, you guessed the word!\n";
	}
	else
	{
		std::cout << "Sorry, you did not guess the word. The word was " << word.word << ".\n";
	}
}

bool playAgain()
{
	std::string input{};
	std::cout << "Would you like to play again? Please enter \"yes\" or \"no\" \n";
	std::cin >> input;
	if (input == "yes")
	{
		return true;
	}
	else if (input == "no")
	{
		return false;
	}
	else
	{
		return playAgain();
	}
}
