/*#include "Character.h"
#include <sstream>

Character::Character(std::string name, int level)
{
	Character::level = level;
	Character::name = name;
	generateAbilityScores();

}


Character::~Character()
{

}

bool Character::validateNewCharacter()
{
	
	if ((curStr < 3 || curStr > 18) || (curDex < 3 || curDex > 18) || (curCon < 3 || curCon > 18) ||
		(curInt < 3 || curInt > 18) || (curWis < 3 || curWis > 18) || (curCha < 3 || curCha > 18))
		return false;
	return true;

}

void Character::hit(int damage)
{
	currentHitPoints = currentHitPoints - damage;
}


int Character::modifyAbility(int modifier)
{
	return static_cast<int>(floor((modifier - 10) / 2));
}

void Character::generateAbilityScores()
{
	curStr = rand() % (18 - 3 + 1) + 3;
	curDex = rand() % (18 - 3 + 1) + 3;
	curCon = rand() % (18 - 3 + 1) + 3;
	curInt = rand() % (18 - 3 + 1) + 3;
	curWis = rand() % (18 - 3 + 1) + 3;
	curCha = rand() % (18 - 3 + 1) + 3;

	aModStr = modifyAbility(curStr);
	aModDex = modifyAbility(curDex);
	aModCon = modifyAbility(curCon);
	aModInt = modifyAbility(curInt);
	aModWis = modifyAbility(curWis);
	aModCha = modifyAbility(curCha);

}

std::string Character::printCharDetailsSheet()
{
	std::stringstream s;

	s << "Name: " << name << " level: " << level << std::endl << std::endl
		<< "STR: " << curStr << std::endl
		<< "DEX: " << curDex << std::endl
		<< "CON: " << curCon << std::endl
		<< "INT: " << curInt << std::endl
		<< "WIS: " << curWis << std::endl
		<< "CHA: " << curCha << std::endl
		<< "HP: " << currentHitPoints << std::endl
		<< "Attack Bonus: " << attackBonus << std::endl
		<< "Damage Bonus: " << damageBonus << std::endl
		<< "Armor Class: " << armorClass << std::endl;

	return s.str();

}




void Character::increaseStat(int enh, string bonus)
{
	if (bonus == "STR") {
		curStr += enh;
	}
	if (bonus == "DEX") {
		curDex += enh;
	}
	if (bonus == "CON") {
		curCon += enh;
	}
	if (bonus == "INT") {
		curInt += enh;
	}
	if (bonus == "WIS") {
		curWis += enh;
	}
	if (bonus == "CHA") {
		curCha += enh;
	}
	if (bonus == "DMGBONUS") {
		damageBonus += enh;
	}
}

*/

#include "Character.h"
#include <sstream>
#include <iostream>
#include<string>
using namespace std;



Character::Character(string name, int level)
{
	Character::level = level;
	Character::name = name;
	generateAbilityScores();

}

Character::~Character()
{

}

bool Character::validateNewCharacter()
{

	if ((curStr < 3 || curStr > 18) || (curDex < 3 || curDex > 18) || (curCon < 3 || curCon > 18) ||
		(curInt < 3 || curInt > 18) || (curWis < 3 || curWis > 18) || (curCha < 3 || curCha > 18))
		return false;
	return true;

}

void Character::hit(int damage)
{
	currentHitPoints = currentHitPoints - damage;
}


int Character::modifyAbility(int modifier)
{
	return static_cast<int>(floor((modifier - 10) / 2));
}

void Character::generateAbilityScores()
{
	curStr = rand() % (18 - 3 + 1) + 3;
	curDex = rand() % (18 - 3 + 1) + 3;
	curCon = rand() % (18 - 3 + 1) + 3;
	curInt = rand() % (18 - 3 + 1) + 3;
	curWis = rand() % (18 - 3 + 1) + 3;
	curCha = rand() % (18 - 3 + 1) + 3;

	aModStr = modifyAbility(curStr);
	aModDex = modifyAbility(curDex);
	aModCon = modifyAbility(curCon);
	aModInt = modifyAbility(curInt);
	aModWis = modifyAbility(curWis);
	aModCha = modifyAbility(curCha);

}

std::string Character::printCharDetailsSheet()
{
	std::stringstream s;

	s << "Name: " << name << " level: " << level << std::endl << std::endl
		<< "STR: " << curStr << std::endl
		<< "DEX: " << curDex << std::endl
		<< "CON: " << curCon << std::endl
		<< "INT: " << curInt << std::endl
		<< "WIS: " << curWis << std::endl
		<< "CHA: " << curCha << std::endl
		<< "HP: " << currentHitPoints << std::endl
		<< "Attack Bonus: " << attackBonus << std::endl
		<< "Damage Bonus: " << damageBonus << std::endl
		<< "Armor Class: " << armorClass << std::endl;

	return s.str();

}




void Character::increaseStat(int enh, string bonus)
{
	if (bonus == "STR") {
		curStr += enh;
	}
	if (bonus == "DEX") {
		curDex += enh;
	}
	if (bonus == "CON") {
		curCon += enh;
	}
	if (bonus == "INT") {
		curInt += enh;
	}
	if (bonus == "WIS") {
		curWis += enh;
	}
	if (bonus == "CHA") {
		curCha += enh;
	}
	if (bonus == "DMGBONUS") {
		damageBonus += enh;
	}
}

void Character::saveCharacter()
{
	string characterName;
	cout << "Please enter the name of the character that will be saved. (ex:Character.txt)";
	cin >> characterName;
	//ofstream out(characterName);

}

void Character::LoadCharacter()
{
}






