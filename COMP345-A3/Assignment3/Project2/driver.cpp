#include "Map.h"
#include "Campaign.h"
#include "MapObserver.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "InputManager.h"
#include "Windows.h"
#include "MapEditor.h"
#include "Dice.h"
#include "Item.h"
#include "Observer.h"
#include "Subject.h"
#include <ctime>
#include <conio.h>
#include <string>
#include "Fighter.h"
#include"Character.h"
#include "CharacterDecorator.h"
#include<cstdlib>


using namespace std;

void moveOnMap(Map m) {
	bool end = false;
	cout << "Now try moving around the map." << endl;
	showMap(m);
	cout << "Use the arrow keys or w, a, s, d to move your character '@'." << endl;
	//cout << m.showMap() << "Use the arrow keys or w, a, s, d to move your character '@'." << endl;
	vector<InputEvent> events;
	// Map w, a, s, d keypresses to Input Events
	events.push_back(InputEvent("w", 0x57));
	events.push_back(InputEvent("s", 0x53));
	events.push_back(InputEvent("a", 0x41));
	events.push_back(InputEvent("d", 0x44));
	// Map arrow keypresses to Input Events
	events.push_back(InputEvent("w", VK_UP));
	events.push_back(InputEvent("s", VK_DOWN));
	events.push_back(InputEvent("a", VK_LEFT));
	events.push_back(InputEvent("d", VK_RIGHT));
	//This one should always be last
	events.push_back(InputEvent("q", VK_ESCAPE));

	string dir;

	while (end == false && dir != "q")
	{
		dir = InputManager::getInput(events);
		end = m.move(dir.at(0), m);
		showMap(m);

	}
	if (end == true)
	{
		cout << "You've reached the door. press q to quit" << endl;
		//Finding where character is located, then opening corresponding map associated to that door spot.

	}

	cin.get();
	cin.get();

}
int main()
{	
	srand(time(NULL));
	
	//! unifed log file for game
	ofstream myfile("GameLog.txt");

	//! clear contents of file from previous game
	if (myfile.is_open())
	{
		myfile.close();
	}

	MapEditor me = MapEditor();
	bool end = false;
	Map m;
	Character *c;
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
			//me.createMap(m);
		}
		else if (choice == 2) {	
			m = me.loadMap();
			camp.addMaptoCampaign(m.name, m);
			cout << "The map has been loaded!" << endl;
			m.message = "The map has been loaded!";
			m.notify();
		}

		else if (choice == 3) {	//Load a campaign.
			cout << "What is the name of the campaign you want to load? (ex:Campaign.txt)" << endl;
			cin >> str;
			camp.loadCampaign(str);
			m = camp.mapOfGameMaps.find("spawn.txt")->second;
			cout << "Campaign has been loaded!";
			m.message = "Campaign has been loaded!";
			m.notify();
		}
		else if (choice == 4) {	//Play a test campaign.
			camp.loadCampaign("testCampaign.txt");
			m = camp.mapOfGameMaps.find("spawn.txt")->second;
			m.message = "Play test campaign";
			m.notify;
		}
		else if (choice == 5) {	//Create and save a character.
			m.message = "Character created and saved";
			m.notify;

		}
		else if (choice == 6) {	//Create/Edit maps.
			m = me.createMap(m);
			m.message = "create and edit map";
			m.notify;
		}
		else if (choice == 7) {	//Create/Edit campaigns.
			me.createCampaign(camp);
			m.message = "create and edit campaign";
			m.notify;
		}
		else if (choice == 8) {	//Play the game with the loaded characters and maps.
			m.message = "Game started";
			m.notify;
		}
	} while (choice != 8);
	cout << "Outputting campaign maps" << endl;
	m.message = "Outputting campaign maps";
	m.notify;
	// Iterate through all elements in std::map
	std::map<std::string, Map>::iterator it = camp.mapOfGameMaps.begin();
	while (it != camp.mapOfGameMaps.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}
	
	int currentMap = 0;
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
	//	events.push_back(InputEvent("i", 0x49));
		// Map arrow keypresses to Input Events
		events.push_back(InputEvent("w", VK_UP));
		events.push_back(InputEvent("s", VK_DOWN));
		events.push_back(InputEvent("a", VK_LEFT));
		events.push_back(InputEvent("d", VK_RIGHT));
		//events.push_back(InputEvent("i", VK_EXECUTE));
		//This one should always be last
		events.push_back(InputEvent("q", VK_ESCAPE));
		

		string dir;

		while (end == false && dir != "q")
		{
			dir = InputManager::getInput(events);
			end = m.move(dir.at(0), m);
			showMap(m);
		}
		if (end == true)
		{
			cout << "You've reached the door. Moving onto the next map." << endl;
			m.message = "You've reached the door. Moving onto the next map.";


			if (currentMap == camp.mapNames.size() - 1) {
				cout << "Congratulations! You beat the game." << endl;
				m.message = "Congratulations! You beat the game.";
				cin >> choice;
				continueGame = false;
				
			}

			else {
				currentMap += 1;
				m = camp.mapOfGameMaps.find(camp.mapNames[currentMap])->second;
				end = false;
			}
		}

		cin.get();
		cin.get();
	} while (continueGame);
	cin >> choice;
	return 0;
}





