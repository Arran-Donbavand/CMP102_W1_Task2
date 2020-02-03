#include "Player.h"
#include <iostream>
char answer = 'n';
int NumberOfSimulations = 0;
std::string message = "";
using namespace std;
int main()
{
	Player Sid;
	Player Joe;
	srand(time(0));


	cout << "Please enter the success rate for Sid (1-100)" << endl;
	cin >> Sid.fixedAccuracy;
	if (Sid.fixedAccuracy >= 100)
	{
		Sid.fixedAccuracy = 99;
	}
	else if (Sid.fixedAccuracy <= 0)
	{
		Sid.fixedAccuracy = 1;
	}
	cout << "Please enter the success rate for Joe (1-100)" << endl;
	cin >> Joe.fixedAccuracy;
	if (Joe.fixedAccuracy >= 100)
	{
		Joe.fixedAccuracy = 99;
	}
	else if (Joe.fixedAccuracy <= 0)
	{
		Joe.fixedAccuracy = 1;
	}

	cout << "Please enter a number to indicate if Sid goes first or second (1 = first, 2 = second" << endl;
	cin >> Sid.turnNumber;
	if (Sid.turnNumber > 2)
	{
		Sid.turnNumber = 2;
	}
	else if (Sid.turnNumber < 1)
	{
		Sid.turnNumber = 2;
	}

	for (;Sid.numberOfBulls < 10 && Joe.numberOfBulls < 10;)
	{
		if (Sid.turnNumber == 1)
		{
			if (Joe.checkForWinner() == false)
			{
				message = Sid.simulateTurn();
				cout << "Sid " << message << Sid.accuracy * 100 << endl;
			}
		    
			if (Sid.checkForWinner() == true && Joe.checkForWinner() == false)
			{
				std::cout << "Sid is the winner!" << endl;
				std::cout << "Sid took " << Sid.numberOfThrows << " turns to win while Joe took " << Joe.numberOfThrows << " throws during the simulation" << endl;
				Sid.numberOfWins++;
			}

			if (Sid.checkForWinner() == false)
			{
				message = Joe.simulateTurn();
				cout << "Joe " << message << Joe.accuracy * 100 << endl;
			}

			if (Joe.checkForWinner() == true && Sid.checkForWinner() == false)
			{
				std::cout << "Joe is the winner!" << endl;
				std::cout << "Joe took " << Joe.numberOfThrows << " turns to win while Sid took " << Joe.numberOfThrows << " throws during the simulation" << endl;
				Joe.numberOfWins++;
			}
			
		}
		if (Sid.turnNumber == 2)
		{
			if (Sid.checkForWinner() == false)
			{
				message = Joe.simulateTurn();
				cout << "Joe " << message << Joe.accuracy * 100 << endl;
			}

			if (Joe.checkForWinner() == true && Sid.checkForWinner() == false)
			{
				std::cout << "Joe is the winner!" << endl;
				std::cout << "Joe took " << Joe.numberOfThrows << " turns to win while Sid took " << Joe.numberOfThrows << " throws during the simulation" << endl;
				Joe.numberOfWins++;
			}

			if (Joe.checkForWinner() == false)
			{
				message = Sid.simulateTurn();
				cout << "Sid " << message << Sid.accuracy * 100 << endl;
			}

			if (Sid.checkForWinner() == true && Joe.checkForWinner() == false)
			{
				std::cout << "Sid is the winner!" << endl;
				std::cout << "Sid took " << Sid.numberOfThrows << " turns to win while Joe took " << Joe.numberOfThrows << " throws during the simulation" << endl;
				Sid.numberOfWins++;
			}
		}
		
		if (Sid.numberOfBulls == 10 || Joe.numberOfBulls == 10)
		{
			NumberOfSimulations++;
			Sid.winRate = Sid.numberOfWins / (float)NumberOfSimulations;
			Joe.winRate = Joe.numberOfWins / (float)NumberOfSimulations;

			cout << "Sid's win rate is: " << Sid.winRate * 100 << endl;
			cout << "Joe's win rate is: " << Joe.winRate * 100 << endl;

			
			cout << "Simulate another game? (Y/N)" << endl;
			cin >> answer;
			if ((answer == 'Y') || (answer == 'y'))
			{
				Sid.newSimulation(Sid.numberOfThrows, Sid.numberOfBulls, Sid.accuracy);
				Joe.newSimulation(Joe.numberOfThrows, Joe.numberOfBulls, Joe.accuracy);
				Sid.numberOfThrows = 0;
				Sid.numberOfBulls = 0;
				Sid.accuracy = 0;
				Joe.numberOfThrows = 0;
				Joe.numberOfBulls = 0;
				Joe.accuracy = 0;
				
			}
			else
			{
				system("CLS");
				Sid.totalNumberOfBulls += Sid.numberOfBulls;
				Sid.totalNumberOfThrows += Sid.numberOfThrows;
				Sid.avgNumOfThrows = (float)Sid.totalNumberOfThrows / (float)Sid.totalNumberOfBulls;
				Sid.overallAccuracy = ((float)Sid.totalNumberOfBulls / (float)Sid.totalNumberOfThrows);

				cout << "Sid's win rate is: " << Sid.winRate * 100 << endl;
				cout << "Sid's average number of throws for a bullseye: " << Sid.avgNumOfThrows << endl;
				cout << "Sid's average overall accuracy: " << Sid.overallAccuracy << "%" << endl;

				Joe.totalNumberOfBulls += Joe.numberOfBulls;
				Joe.totalNumberOfThrows += Joe.numberOfThrows;
				Joe.avgNumOfThrows = (float)Joe.totalNumberOfThrows / (float)Joe.totalNumberOfBulls;
				Joe.overallAccuracy = ((float)Joe.totalNumberOfBulls / (float)Joe.totalNumberOfThrows);

				cout << "Joe's win rate is: " << Joe.winRate * 100 << endl;
				cout << "Joe's average number of throws for a bullseye: " << Joe.avgNumOfThrows << endl;
				cout << "Joe's average overall accuracy: " << Joe.overallAccuracy << "%" << endl;
			}
		}
	}
}
