#include "FBullCowGame.h"
#include <map>
#define TMap std::map 

using FString = std::string;
using int32 = int; // default constructor

FBullCowGame::FBullCowGame(){Reset();}
int32 FBullCowGame::GetMaxTries() const {return myMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return myCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return myHiddenWord.length();}
bool FBullCowGame::IsGameWon() const {return bGameIsWon;}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ { 3,4 },{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return WordLengthToMaxTries[myHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "plane";// this MUST be an isogram
	myHiddenWord = HIDDEN_WORD;
	myCurrentTry = 1;
	bGameIsWon = false;
	return;
}
EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!IsIsogram(guess)) //if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if(!IsLowerCase(guess))//if the guess isn't all lowercase
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

bool FBullCowGame::IsLowerCase(FString Word) const 
{
	for(auto letter:Word)
	{
		if (!islower(letter)) // if not all lowercase
		{
			return false;
		}
	}
	return true;
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

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 as an isogram
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> letterSeen; // Setup our map
	for (auto letter : Word)      // for all letters 
	{
		letter = tolower(letter);// handle mixed case
		if (letterSeen[letter]) {
			return false; // we do NOT have an isogram 
		} else {
			letterSeen[letter] = true; // add letter to the map as seen
		}
	}
	return true;
}

