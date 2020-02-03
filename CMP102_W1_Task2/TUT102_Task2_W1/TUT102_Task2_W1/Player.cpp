#include "Player.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
Player::Player()
{

}
Player::~Player()
{

}
bool Player::checkIfBullseye(float estimatedAccuracy)
{
	int rand_num = rand() % 100 + 1;
	if (rand_num < estimatedAccuracy)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::newSimulation(int& simulationThrows, int& simulationBulls, float& simulationAcc)
{
	totalNumberOfBulls += simulationBulls;
	totalNumberOfThrows += simulationThrows;
	overallAccuracy = ((float)totalNumberOfBulls / (float)totalNumberOfThrows);
}
std::string Player::simulateTurn()
{
	if (numberOfBulls != 10)
	{
		if (checkIfBullseye(fixedAccuracy) == true)
		{
			numberOfBulls++;
			numberOfThrows++;
			accuracy = ((float)numberOfBulls / (float)numberOfThrows);
			return "Hit! - Accuracy = ";
		}
		else
		{
			numberOfThrows++;
			accuracy = ((float)numberOfBulls / (float)numberOfThrows);
			return "Missed! - Accuracy = ";
		}
	}
}
bool Player::checkForWinner()
{
	if (numberOfBulls == 10)
	{
		return true;
	}
	else
	{
		return false;
	}

}