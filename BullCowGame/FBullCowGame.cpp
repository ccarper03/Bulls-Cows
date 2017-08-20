#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame(){Reset();}
int32 FBullCowGame::GetMaxTries() const {return myMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return myCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return myHiddenWord.length();}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (false) //if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if(false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length()!= GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
	// if the guess isn't all lowercase, 
		// return an error 
	// if the guess length is wrong, 
		// return an error 
	// otherwise   
		// return ok 
}

// Receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	// increment the turn number
	myCurrentTry++;
	// setup a return variable
	FBullCowCount bullCowCount; 
	
	// loop through all letters in the guess
	int32 HiddenWordLength = myHiddenWord.length();
	for (int32 myHidWordChar = 0; myHidWordChar < HiddenWordLength; myHidWordChar++) 
	{
	// compare letters against the hidden word
		for(int32 GuessChar = 0; GuessChar < HiddenWordLength; GuessChar++)
		{
			// if they match then
			if (guess[GuessChar] == myHiddenWord[myHidWordChar])
			{
				if (myHidWordChar == GuessChar) 
				{ // if they're in the same place
					bullCowCount.bulls++; // increment bulls
				}
				else 
				{
					bullCowCount.cows++; // must be a cow
				}
			}
		}
	}
	return bullCowCount;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	myMaxTries = MAX_TRIES;
	myHiddenWord = HIDDEN_WORD;
	myCurrentTry = 1;
	return;
}