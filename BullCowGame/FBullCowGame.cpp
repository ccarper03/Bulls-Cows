#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame(){Reset();}
int32 FBullCowGame::GetMaxTries() const {return myMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return myCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return myHiddenWord.length();}
bool FBullCowGame::IsGameWon() const {return bGameIsWon;}

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
FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	myCurrentTry++;
	bool BgameOver = false;
	FBullCowCount bullCowCount; 
	int32 WordLength = myHiddenWord.length();// assuming same length as guess

	// loop through all letters in the hidden word
	for (int32 myHidWordChar = 0; myHidWordChar < WordLength; myHidWordChar++) 
	{
	// compare letters against the guess
		for(int32 GuessChar = 0; GuessChar < WordLength; GuessChar++)
		{
			// if they match then
			if (guess[GuessChar] == myHiddenWord[myHidWordChar]){
				if (myHidWordChar == GuessChar) { // if they're in the same place
					bullCowCount.bulls++; // increment bulls
				}
				else {
					bullCowCount.cows++; // must be a cow
				}
			}
		}
	}
	if (bullCowCount.bulls == WordLength)
	{
		BgameOver = true;
	}
	else 
	{
		BgameOver = false;
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