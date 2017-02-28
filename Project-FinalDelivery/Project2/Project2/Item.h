#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CharacterDecorator.h"	
using namespace std;

class Item :public CharacterDecorator {
public:
	string type;
	vector<int> enhancement;
	vector <string> bonus;


	Item(string type, vector <int> enhancement, vector <string> bonus);
	Item();
	Item(Character *decoratedCharacter) : CharacterDecorator(decoratedCharacter) {}
	Item(Character *decoratedCharacter, string type, vector <int> enhancement, vector <string> bonus) : CharacterDecorator(decoratedCharacter)
	{
		this->type = type;
		this->enhancement = enhancement;
		this->bonus = bonus;
	}
	Item(Character *decoratedCharacter, Item i) : CharacterDecorator(decoratedCharacter) {
		this->type = i.type;
		this->enhancement = i.enhancement;
		this->bonus = i.bonus;
	}
	friend vector<string> itemInfo(Item &i);
	friend bool itemCheck(Item &i);
	friend void addEnhancement(Item &i, int enhancement, string bonus);
	friend string getType(Item &i);
	friend vector<int> getEnhancement(Item &i);
	friend vector<string> getBonus(Item &i);
	friend ostream & operator<<(ostream &stream, Item &i);
	bool wear(string itemType);
	void remove(string itemType);
	void generateAttributes() {};
	void displayBackPack();
	void displayEquipped();
	void levelUp();
	string randomItem();
};