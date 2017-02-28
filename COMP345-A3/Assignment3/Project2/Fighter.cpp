/*#include "Fighter.h"

const int Fighter::HP_START = 15;
const int Fighter::HP_PER_LEVEL = 6;

Fighter::Fighter(std::string name, int level) : Character(name, level)
{
	generateAttributes();
}

Fighter::~Fighter()
{
}

void Fighter::generateAttributes()
{
	currentHitPoints = HP_START + ((level - 1) * HP_PER_LEVEL) + curCon;

	armorClass = 10 + aModDex;

	attackBonus = aModStr + static_cast<int>(Character::level / 2);

	damageBonus = aModStr;




}

*/

#include"Fighter.h"

const int Fighter::HP_START = 15;
const int Fighter::HP_PER_LEVEL = 6;

Fighter::Fighter(std::string name, int level) : Character(name, level)
{
	generateAttributes();
}

Fighter::~Fighter()
{
}

void Fighter::generateAttributes()
{
	currentHitPoints = HP_START + ((level - 1) * HP_PER_LEVEL) + curCon;

	armorClass = 10 + aModDex;

	attackBonus = aModStr + static_cast<int>(Character::level / 2);

	damageBonus = aModStr;




}