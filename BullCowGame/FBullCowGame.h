#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

// Two integers initialized to zero
struct FBullCowCount 
{
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EGuessStatus 
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; // TODO Make a more rich return value

	void Reset(); // TODO make a more rich return value
	FBullCowCount SubmitGuess(FString); // struct

private:
	// See constructor for initialization
	int myCurrentTry;
	int myMaxTries; 
	FString myHiddenWord;
};