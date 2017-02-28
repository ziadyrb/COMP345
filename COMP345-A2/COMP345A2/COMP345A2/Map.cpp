#include "Map.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

Map::Map()
{
}

Map::Map(int l, int h) {
	// Initialize variables
	length = l + 2;
	height = h + 2;


	// Create 2D array
	mArr = new char*[length];
	for (int i = 0; i < length; i++)
		mArr[i] = new char[length];

	// Fill the array with empty spaces (=)
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < height; j++)
			mArr[i][j] = '=';
		// Set up initial walls around
		for (int i = 0; i < height; i++) {
			mArr[i][0] = '|';
			mArr[i][height - 1] = '|';
		}
		for (int j = 0; j < length; j++) {
			mArr[0][j] = '-';
			mArr[length - 1][j] = '-';
		}
		// Set up corners
		mArr[0][0] = '+';
		mArr[length - 1][0] = '+';
		mArr[0][height - 1] = '+';
		mArr[length - 1][height - 1] = '+';
	}


}

void showMap(Map m)
{
	for (int i = 0; i < m.length; i++)
	{
		for (int j = 0; j < m.height; j++)
		{
			cout << m.mArr[i][j];
		}
		cout << endl;
	}
}

void printMap(Map m)
{
	ofstream outputFile;
	outputFile.open("mapPrint.txt");

	for (int i = 0; i < m.length; i++)
	{
		for (int j = 0; j < m.height; j++)
		{
			outputFile << m.mArr[i][j];
		}
		outputFile << endl;
	}

	outputFile.close();
}

bool validatePath(Map m)
{
	for (int i = 0; i < m.length; i++)
	{
		for (int j = 0; j < m.height; j++)
		{
			if (m.mArr[i][j] = 'd') // 'd' is for door
			{
				return true;
			}
			else
				return false;
		}
	}
}

void fillCell(int x, int y, char obj, Map m)
{
	m.mArr[x][y] = obj;
}


bool isOccupied(int x, int y, Map m)
{
	if (m.mArr[x][y] != '=')
	{
		return true;
	}
	return false;
}

int getLength(Map m)
{
	return m.length;
}
int getHeight(Map m)
{
	return m.height;
}

void makeRandomMap(Map m)
{
	int characterStart = 0;
	int maxDoor = 0;
	srand(time(NULL));
	for (int i = 1; i < getLength(m) - 1; i++)
	{

		for (int j = 1; j < getHeight(m) - 1; j++)
		{

			int num = (rand() % 100);
			cout << num << endl;
			if (num < 80)
			{
				fillCell(i, j, '=', m); //'=' is free space
			}
			else if (num >= 80 && num < 85)
			{
				if (characterStart == 0) {
					fillCell(i, j, '@', m);	//'@' is for character
					characterStart++;
				}
				else if (maxDoor < 5)
				{
					fillCell(i, j, 'd', m); // 'd' is for door
					maxDoor++;
				}
				else
					fillCell(i, j, '=', m); // free space for limit door
			}

			else if (num >= 85 && num < 90) {
				fillCell(i, j, 'c', m);	//'c' is for chest
			}

			else if (num >= 90 && num < 95) {
				fillCell(i, j, 'm', m);	//m is for monster
			}

			else
			{
				fillCell(i, j, '*', m);	//* is for wall
			}

		}

	}

}
