/*#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Item.h"
#include "ItemContainer.h"
#include "Dice.h"
//#include "Observable.h"
#include <cstdlib>
class Character 
{
public:
	virtual ~Character();
	Character(std::string name = "Default Name", int level = 1);
	bool validateNewCharacter();
	void hit(int);

	int modifyAbility(int mod);
	void generateAbilityScores();
	virtual void generateAttributes() = 0;
	//void wearItem(Item& item);
	//vector<string> split(const string & s, char delim);
	std::string printCharDetailsSheet();
	void increaseStat(int enh, string bonus);

protected:
	std::string name;
	int currentHitPoints;
	int armorClass;
	int attackBonus;
	int damageBonus;
	int level;

	int curStr,
		curDex,
		curCon,
		curInt,
		curWis,
		curCha;

	int aModStr,
		aModDex,
		aModCon,
		aModInt,
		aModWis,
		aModCha;

	ItemContainer inventory = ItemContainer("Backpack");
	ItemContainer wornItems = ItemContainer("Equipped");
	// Equiped Items
	// 1: Weapon
	// 2: Shield
	// 3: Helmet
	// 4: Armour
	// 5. Belt
	// 6. Boots
	// 7. Ring
	std::vector<Item> slot;


};

*/

#pragma once
#include<string>
#include <iostream>
//#include"CharacterItemContainers.h"
using namespace std;

class Character {
public:
	virtual ~Character();
	virtual void wear(string itemType) = 0;
	virtual void remove(string itemType) = 0;
	virtual void generateAttributes() = 0;
	virtual void displayBackPack() = 0;
	virtual void displayEquipped() = 0;

	int modifyAbility(int mod);
	void generateAbilityScores();
	Character(string name = "Default Name", int level = 1);
	void hit(int);
	bool validateNewCharacter();
	std::string printCharDetailsSheet();
	void increaseStat(int enh, string bonus);
	void saveCharacter();
	void LoadCharacter();
	std::string name;
	int currentHitPoints;
	int armorClass;
	int attackBonus;
	int damageBonus;
	int level;

	int curStr,
		curDex,
		curCon,
		curInt,
		curWis,
		curCha;

	int aModStr,
		aModDex,
		aModCon,
		aModInt,
		aModWis,
		aModCha;
};

