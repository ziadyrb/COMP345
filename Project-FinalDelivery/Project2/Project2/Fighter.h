#pragma once

#include "character.h"

class Fighter : public Character
{
public:
	//Static constans related to hit points
	static const int HP_START;
	static const int HP_PER_LEVEL;

	//Constructor and destructor
	Fighter(std::string name = "Default Character", int level = 1);
	~Fighter();

	//Method to assign class (e.g. Fighter) specific data members
	void generateAttributes();
	bool wear(string itemType) { return false; };
	void remove(string itemType) {};
	void displayBackPack() {};
	void displayEquipped() {};
	virtual void levelUp();
};