#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame(){Reset();}
int32 FBullCowGame::GetMaxTries() const {return myMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return myCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return myHiddenWord.length();}
bool FBullCowGame::IsGameWon() const {return bGameIsWon;}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	myMaxTries = MAX_TRIES;
	myHiddenWord = HIDDEN_WORD;
	myCurrentTry = 1;
	bGameIsWon = false;
	return;
}
EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (false) //if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; //TODO write funtion
	}
	else if(false)//if the guess isn't lowercase
	{
		return EGuessStatus::Not_Lowercase; //TODO write funtion
	}
	else if (guess.length()!= GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length; //TODO write funtion
	}
	else
	{
		return EGuessStatus::OK;
	}
}
// Receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	myCurrentTry++;
	FBullCowCount bullCowCount; 
	int32 WordLength = myHiddenWord.length();// assuming same length as guess

	// loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
	// compare letters against the guess
		for(int32 GuessChar = 0; GuessChar < WordLength; GuessChar++)
		{
			// if they match then
			if (guess[GuessChar] == myHiddenWord[MHWChar]){
				if (MHWChar == GuessChar) { // if they're in the same place
					bullCowCount.bulls++; // increment bulls
				}
				else { // if not
					bullCowCount.cows++; // increment cows
				}
			}
		}
	}
	if (bullCowCount.bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else 
	{
		bGameIsWon = false;
	}
	return bullCowCount;
}

