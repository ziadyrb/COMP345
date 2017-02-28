#pragma warning(disable: 4996)
#include "Map.h"
#include "Campaign.h"
#include "MapObserver.h"
#include <vector>
#include <iostream>
#include "InputManager.h"
#include "Windows.h"
#include "MapEditor.h"
#include "Dice.h"
#include "Item.h"
#include <ctime>
#include <conio.h>
#include <string>
#include "Fighter.h"
#include"Character.h"
#include "CharacterDecorator.h"
#include "FighterDirector.h"
#include "BullyFighterBuilder.h"
#include "NimbleFighterBuilder.h"
#include "TankFighterBuilder.h"
#include"ConsoleLogger.h"
#include"ItemContainer.h"
#include"CharacterItemContainers.h"
#include<cstdlib>
#include <fstream>
#include"Subject.h"
#include"Observer.h"

/*This program was designed to implement a dungeon and dragons board game. The use of the external library ConsoleLogger
and its helper application called ConsoleLoggerHelper are used to create secondary console windows in order to output
things such as equipped items, backpack and character stats. The rest of the included libraries are from C++.
While playing the game, used w a s d or arrow keys to move, press i to open item inventory or o to open the character statistics.
*/
using namespace std;

//Method that plays the game once the paramaters have been set.
void playGame(Campaign camp, Map m,Character *&player) {
	int choice;
	int currentMap = 0;
	bool end = false;
	bool continueGame = true;
	do {
		//showMap(c.mapOfGameMaps.find("spawn")->second);
		showMap(m);
		cout << m.name << endl;
		cout << "Use the arrow keys or w, a, s, d to move your character '@'." << endl;
		//cout << m.showMap() << "Use the arrow keys or w, a, s, d to move your character '@'." << endl;
		vector<InputEvent> events;
		// Map w, a, s, d keypresses to Input Events
		events.push_back(InputEvent("w", 0x57));
		events.push_back(InputEvent("s", 0x53));
		events.push_back(InputEvent("a", 0x41));
		events.push_back(InputEvent("d", 0x44));
		events.push_back(InputEvent("i", 0x49));
		events.push_back(InputEvent("o", 0x4f));
		// Map arrow keypresses to Input Events
		events.push_back(InputEvent("w", VK_UP));
		events.push_back(InputEvent("s", VK_DOWN));
		events.push_back(InputEvent("a", VK_LEFT));
		events.push_back(InputEvent("d", VK_RIGHT));
		//events.push_back(InputEvent("i", VK_EXECUTE));
		//This one should always be last
		events.push_back(InputEvent("q", VK_ESCAPE));


		string dir;
		dir = InputManager::getInput(events);
		end = m.move(dir.at(0), m, player,currentMap);
		while (end == false && dir != "q")
		{
			showMap(m);
			dir = InputManager::getInput(events);
			end = m.move(dir.at(0), m, player, currentMap);
			//	system("CLS");


			//Sleep(1);
		}
		if (end == true)
		{
			Sleep(1);
			cout << "You've reached the door. Moving onto the next map." << endl;
		

			if (currentMap == camp.mapNames.size() - 1) {
				cout << "Congratulations! You beat the game." << endl;
				std::cin >> choice;
				continueGame = false;

			}

			else {
				currentMap += 1;
				m = camp.mapOfGameMaps.find(camp.mapNames[currentMap])->second;
				end = false;
			}
		}

		std::cin.get();
		std::cin.get();
	} while (continueGame);
}

using namespace std;
int main()
{	
	//! unifed log file for game
	ofstream myfile("GameLog.txt");

	//! clear contents of file from previous game
	if (myfile.is_open())
	{
		myfile.close();
	}
	
	srand(time(NULL));
	MapEditor me = MapEditor();
	bool end = false;
	Map m;
	Character *player = new Fighter();
	Campaign camp = Campaign();
	int choice;	//Used for user input.
	string str;	//Used for user input.
	do {
		cout << "Welcome to the menu! Please select an option and hit enter." << endl;
		cout << "1.Load a character." << endl;
		cout << "2.Load a map." << endl;
		cout << "3.Load a campaign." << endl;
		cout << "4.Play a test campaign." << endl;
		cout << "5.Create and save a character." << endl;
		cout << "6.Create/Edit maps." << endl;
		cout << "7.Create/Edit campaigns." << endl;
		cout << "8.Play!" << endl;
		cin >> choice;

		//If statements represent each menu choice.
		if (choice == 1) {	//Load a character.
			player->LoadCharacter();
			cout << player->printCharDetailsSheet();
		}
		else if (choice == 2) {	//Load a map.
			m = me.loadMap();
			camp.addMaptoCampaign(m.name, m);
			cout << "The map has been loaded!" << endl;
		}

		else if (choice == 3) {	//Load a campaign.
			cout << "What is the name of the campaign you want to load? (ex:Campaign.txt)" << endl;
			cin >> str;
			camp.loadCampaign(str);
			m = camp.mapOfGameMaps.find("spawn.txt")->second;
			cout << "Campaign has been loaded!";
		}
		else if (choice == 4) {	//Play a test campaign.
			camp.loadCampaign("testCampaign.txt");
			m = camp.mapOfGameMaps.find("spawn.txt")->second;
			cout << "The campaign has been loaded!" << endl;
		}
		else if (choice == 5) {	//Create and save a character.
			FighterDirector director;
			FighterBuilder* bullyBuilder;
			FighterBuilder* nimbleBuilder;
			FighterBuilder* tankBuilder;

			cout << "What type of fighter would you like to create?" << endl
				<< "Press 1 for Bully, 2 for Nimble or 3 for Tank." << endl;
			int fighterType;
			cin >> fighterType;
			if (fighterType == 1)
			{
				bullyBuilder = new BullyFighterBuilder;
				director.setFighterBuilder(bullyBuilder);
				director.constructFighter();
				//Fighter* bully = director.getFighter();
				player = director.getFighter();
				cout << "Enter a name: ";
				std::string name;
				cin >> name;
				player->name = "Bully Fighter " + name;
				cout << player->printCharDetailsSheet() << endl;
				
			}
			if (fighterType == 2)
			{
				nimbleBuilder = new NimbleFighterBuilder;
				director.setFighterBuilder(nimbleBuilder);
				director.constructFighter();
				player = director.getFighter();
				cout << "Enter a name: ";
				std::string name;
				cin >> name;
				player->name = "Nimble Fighter " + name;
				cout << player->printCharDetailsSheet() << endl;
			

			}
			if (fighterType == 3)
			{
				tankBuilder = new TankFighterBuilder;
				director.setFighterBuilder(tankBuilder);
				director.constructFighter();
				player = director.getFighter();
				cout << "Enter a name: ";
				std::string name;
				cin >> name;
				player->name = "Tank Fighter " + name;
				cout << player->printCharDetailsSheet() << endl;
		
			}

			cout << "Do you want to save your character? Press 1 to save or 2 to go back to the menu." << endl;
			cin >> choice;
			if (choice == 1)
				player->saveCharacter();
		}
		else if (choice == 6) {	//Create/Edit maps.
			m = me.createMap(m);
		}
		else if (choice == 7) {	//Create/Edit campaigns.
			me.createCampaign(camp);
			m = camp.mapOfGameMaps.find("spawn.txt")->second;
		}
		else if (choice == 8) {	//Play the game with the loaded characters and maps.
		}
		cout << "Press any key to continue." << endl;
		cin >> str;
		system("CLS");
	} while (choice != 8);


	//Equipping the player with the basic equipment.
	Item basicWeapon = Item("weapon", { 5 }, { "ATKBONUS" });
	Item basicShield = Item("shield", { 5 }, { "ARMORCLASS" });
	Item basicHelmet = Item("helmet", { 6 }, {"ARMORCLASS"});
	Item basicArmor = Item("armor", { 10 }, { "ARMORCLASS" });
	Item basicRing = Item("ring", { 2 }, { "ARMORCLASS" });
	Item basicBelt = Item("belt", { 4 }, { "STR" });
	Item basicBoots = Item("boots", { 3 }, { "DEX" });

	player = new Item(player, basicWeapon);
	player->wear("weapon");
	player = new Item(player, basicShield);
	player->wear("shield");
	player = new Item(player, basicHelmet);
	player->wear("helmet");
	player = new Item(player, basicArmor);
	player->wear("armor");
	player = new Item(player, basicRing);
	player->wear("ring");
	player = new Item(player, basicBelt);
	player->wear("belt");
	player = new Item(player, basicBoots);
	player->wear("boots");



	playGame(camp, m, player);
	cin >> choice;
	return 0;
}





/*
int main() {

	int n;

	srand(static_cast<unsigned int>(time(0))); //reset srand to give a different number everytime
	Dice d;

	std::cout << "Rolling a d100 4 times." << endl;
	n = d.roll("4d100");
	std::cout << "Result: " << n << endl;

	std::cout << "Rolling a d10 5 times." << endl;
	n = d.roll("5d10");
	std::cout << "Result: " << n << endl;

	std::cout << "Rolling a d20 9 times." << endl;
	n = d.roll("9d20");
	std::cout << "Result: " << n << endl;

	std::cout << "Rolling a d6 1 time." << endl;
	n = d.roll("1d6");
	std::cout << "Result: " << n << endl;


	system("PAUSE");

	return 0;

};

*/

