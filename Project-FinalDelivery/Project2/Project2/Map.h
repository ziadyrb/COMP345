#pragma once
#include <iostream>
#include <string>
#include "Subject.h"
#include "Item.h"
#include <vector>

using namespace std;

//Pair structure that indicates the indices of the door that connects to the next map. It includes the map name as well.
class Map : public Subject
{

private:
	int height;
	int length;
	char** mArr;
	int tempX, tempY, playerX, playerY, monsterX, monsterY, tempsX, tempsY;
	char current, currents;

public:
	string name;
	Map();
	Map(int w, int h);
	friend void showMap(Map map);
	string showMap();
	friend bool validatePath(Map map);
	friend void fillCell(int x, int y, char obj, Map &map);
	friend bool isOccupied(int x, int y, Map map);
	friend int getLength(Map map);
	friend int getHeight(Map map);
	friend char** getMapElements(Map map);
	friend void setLength(int x, Map map);
	friend void setHeight(int y, Map map);
	friend void makeRandomMap(Map &map);
	//bool move(char dir, Map map);
	friend ostream& operator << (ostream &stream, Map &m);
	bool move(char dir, Map m, Character  *& player, int currentMap);
	Item openChest(char dir, Character *& player);
	//Pair moveMonster(int x, int y);
	/*Map(int height, int length);
	bool validatePath();
	void fillCell(int x, int y, char obj);
	bool isOccupied(int x, int y);
	friend void showMap(Map map);
	*/
};

