/*	gameloop.h
 *	Header file for gameloop.cpp
 *	Exposes functions related to the core game loop and functionality
 */

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <string>
#include <vector>

/*	CurrentWord
 *	A struct holding two strings, "word" and "guess"
 * 
 *	Members:
 *	std::string word -- The word represented by the variable
 *	std::string guess -- the user's guess of "word"
 */
struct CurrentWord
{
	std::string word;
	std::string guess;
};

/*	getRandomWord
 *	Selects a random word from a provided word list, and prepares both the word and a obscured guessing version.
 * 
 *	Parameters:
 *	std::vector<std::string> wordList -- a vector of strings, with each string containing one word.
 * 
 *	Return:
 *	Returns a CurrentWord with "word" set to the selected word and "guess" filled with asterisks to the same length as "word".
 */
CurrentWord getRandomWord(std::vector<std::string> wordList);

/*	play
 *	Plays a round of WordGuess. Asks the player to make a guess, and checks if their guess is valid or not. 
 * 
 *	Parameters:
 *	CurrentWord& word -- the word to be guessed.
 * 
 *	Return:
 *	No return.
 */
void play(CurrentWord& word);

/*	playAgain
 *	Asks the user if they would like to play another round.
 *	
 *	Parameters:
 *	None.
 * 
 *	Return
 *	Returns a boolean representing if the user wanted to play another round or not.
 */
bool playAgain();

#endif // !GAMELOOP_H

