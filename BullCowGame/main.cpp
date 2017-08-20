/* This is the console executable, that makes use of the BullCow Class.
This acts as the view in a MVC pattern, and is responsible for all 
user interaction. For game logic see the FBullCowGame class. 
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

// method declarations
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // struct

int main() 
{
	BCGame.Reset();
	std::cout << BCGame.GetCurrentTry();
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		std::cout << std:: endl;
	}while (bPlayAgain);
	return 0;
}

// introduce the game
void PrintIntro() 
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter Isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}
// Plays game loop
void PlayGame() 
{
	int32 myMaxTries = BCGame.GetMaxTries();

	// loop for the nummber of turns asking for guesses
	for (int32 i = 0; i < myMaxTries; i++)//TODO change from FOR to WHILE 
	{
		// Get guess and display it back to user
		FText guess = GetValidGuess(); // TODO make loop check for valid guesses

		// submit valid guess to the game, and receive counts
 		FBullCowCount bullCowCount = BCGame.SubmitValidGuess(guess);

		std::cout << "Bulls = " << bullCowCount.bulls;
		std::cout << ". Cows = " << bullCowCount.cows << "\n\n";
	}
	// TODO summarise game
	return;
}
// loop continually until user gives valid guess
FText GetValidGuess() 
{
	EGuessStatus status = EGuessStatus::Invalid_Status;
	do
	{
		// get a guess from the user
		int32 myCurrentTries = BCGame.GetCurrentTry();
		std::cout << "try " << myCurrentTries << " Enter your guess: ";
		FText guess = "";
		std::getline(std::cin, guess);

		// Check status and give feedback
		status = BCGame.CheckGuessValidity(guess);
		switch (status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters \n";
			break;
		default:
			return guess;
		}
		std::cout << std::endl;
	} while (status != EGuessStatus::OK); // Keep looping until no errors.
}
// Ask player to play again, returns bool
bool AskToPlayAgain() 
{
	std::cout << "Do you want to play again (y/n)? ";
	FText response = "";
	std::getline(std::cin, response);
	return (response[0] =='y'|| response[0] == 'Y');
}
