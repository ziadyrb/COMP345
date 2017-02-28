#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Builder.h"
using namespace std;

class Map
{
private:
	int height;
	int length;

	


public:
	char** mArr;
	Map();
	Map(int w, int h);
	friend void showMap(Map map);
	friend void printMap(Map map);
	friend bool validatePath(Map map);
	void fillCell(int x, int y, char obj,Map map);
	friend bool isOccupied(int x, int y, Map map);
	friend int getLength(Map map);
	friend int getHeight(Map map);
	friend void makeRandomMap(Map map);
};

