// Casino Game.cpp : This file contains the 'main' function. Program execution begins and ends there
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#include "pch.h"
#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;

void drawLine(int n, char symbol);
void rules();

int main()
{
	string playerName;
	int amount; // hold player's balance amount
	int bettingAmount;
	int guess;
	int dice; // hold computer generated number
	char choice;

	srand(time(0)); // "Seed" the random generator

	drawLine(60, '_');
	cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
	drawLine(60, '_');

	cout << "\n\nEnter Your Name : ";
	getline(cin, playerName);

	cout << "\n\nEnter Deposit amount to play game : $";
	cin >> amount;

	do
	{
		system("cls");
		rules();
		cout << "\n\nYour current balance is $ " << amount << "\n";

		// Get player's betting amount
		do
		{
			cout << playerName << ", enter money to bet : $";
			cin >> bettingAmount;
			if (bettingAmount > amount)
				cout << "Your betting amount is more than your current balance\n"
				<< "\nRe-enter data\n ";
		} while (bettingAmount > amount);

		// Get player's numbers
		do
		{
			cout << "Guess your number to bet between 1 to 10 :";
			cin >> guess;
			if (guess <= 0 || guess > 10)
				cout << "Please check the number!! should be between 1 to 10\n"
				<< "\nRe-enter data\n ";
		} while (guess <= 0 || guess > 10);

		dice = rand() % 10 + 1; // Will hold the randomly generated integer between 1 and 10

		if (dice == guess)
		{
			cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
			amount = amount + bettingAmount * 10;
		}
		else
		{
			cout << "Bad Luck this time !! You lost $ " << bettingAmount << "\n";
			amount = amount - bettingAmount;
		}

		cout << "\nThe winning number was : " << dice << "\n";
		cout << "\n" << playerName << ", You have $ " << amount << "\n";
		if (amount == 0)
		{
			cout << "You have no money to play ";
			break;
		}
		cout << "\n\n-->Do you want to play again (y/n)? ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	cout << "\n\n\n";
	drawLine(70, '=');
	cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
	drawLine(70, '=');

	return 0;
}

void drawLine(int n, char symbol)
{
	for (int i = 0; i < n; i++)
		cout << symbol;
	cout << "\n";
}

void rules()
{
	system("cls");
	cout << "\n\n";
	drawLine(80, '-');
	cout << "\t\tRULES OF THE GAME\n";
	drawLine(80, '-');
	cout << "\t1. Choose any number between 1 to 10\n";
	cout << "\t2. If you win you will get 10 times of money you bet\n";
	cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
	drawLine(80, '-');
}

// END OF PROGRAM
