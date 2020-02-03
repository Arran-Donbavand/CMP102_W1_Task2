#pragma once
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

class Player
{
public:
	Player();
	~Player();
	bool checkIfBullseye(float);
	void newSimulation(int&, int&, float&);
	std::string simulateTurn();
	bool checkForWinner();
	int turnNumber = 0;
	float fixedAccuracy = 0;
	int numberOfThrows = 0;
	int numberOfBulls = 0;
	float accuracy = 0;
	int totalNumberOfThrows = 0;
	int totalNumberOfBulls = 0;
	float overallAccuracy = 0;
	float avgNumOfThrows = 0;
	int numberOfWins = 0;
	float winRate = 0;
}; 
