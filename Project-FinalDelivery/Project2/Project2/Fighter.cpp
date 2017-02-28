#include "Fighter.h"

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
	maxHitPoints = currentHitPoints;

	armorClass = 10 + aModDex;

	attackBonus = aModStr + static_cast<int>(Character::level / 2);

	damageBonus = aModStr;
}

void Fighter::levelUp()
{
	string str;
	Dice *d = new Dice();
	maxHitPoints += d->roll("1d10") + aModCon;
	currentHitPoints = maxHitPoints;
	cout << maxHitPoints << "inside level up" << endl;
	cin >> str;
	++level;

	if (level >= 16)
	{
		attackBonus4 += 1;
		attackBonus3 += 1;
		attackBonus2 += 1;
		attackBonus += 1;
	}
	else if (level >= 11)
	{
		attackBonus3 += 1;
		attackBonus2 += 1;
		attackBonus += 1;
	}
	else if (level >= 6)
	{
		attackBonus2 += 1;
		attackBonus += 1;

	}
	else
		attackBonus += 1;

	
	
	
}