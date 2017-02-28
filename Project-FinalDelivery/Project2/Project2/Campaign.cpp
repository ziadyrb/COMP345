#include "Campaign.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include"MapEditor.h"
using namespace std;

Campaign::Campaign() {

}

Campaign::Campaign(string s) {
	name = s;
}

void Campaign::saveCampaign()
{
	string campaignFile;
	cout << "Please enter the name of the campaign that will be saved. (ex:Campaign.txt)";
	cin >> campaignFile;
	ofstream out(campaignFile);  // file.txt can be any name that your file might have
	

	for (unsigned int i = 0; i < mapNames.size(); i++)
	{
			out << mapNames[i]; // setw(n) -- n means that your string will have a field of 'n' spaces reserved
		out << "\n";
	}


}

void Campaign::loadCampaign()
{
	string campaignFile;
	cout << "Please enter name of campaign file. (ex:Campaign.txt)" << endl;
	cin >> campaignFile;
	std::ifstream input(campaignFile);
	std::string line;
	input.open(campaignFile,ios::in);
	input >> line;

	std::ifstream file(campaignFile);
	std::string str;
	std::string file_contents;
	
	while (std::getline(file,str)) {
		file_contents += str;
		file_contents.push_back('\n');
		mapNames.push_back(str);
	
	}
	for (unsigned int i = 0; i < mapNames.size(); i++) {
		cout << mapNames[i] << endl;
	}
	
	cout << mapNames.size();
	cin >> campaignFile;
	input.close();
	numberOfMaps = mapNames.size();
	Map m;
	MapEditor me;
	
	for (unsigned int i = 0; i < mapNames.size(); i++) {
		m = me.loadMap(mapNames[i]);
		loadMaptoCampaign(mapNames[i], m);
		cout << mapOfGameMaps.find(mapNames[i])->second;
	}
	cin >> campaignFile;

}

void Campaign::loadCampaign(string campaignFile)
{
	std::ifstream input(campaignFile);
	std::string line;
	input.open(campaignFile, ios::in);
	input >> line;

	std::ifstream file(campaignFile);
	std::string str;

	while (std::getline(file, str)) {
		mapNames.push_back(str);
		
	}

	input.close();
	numberOfMaps = mapNames.size();
	Map m;
	MapEditor me;

	for (unsigned int i = 0; i < mapNames.size(); i++) {
		m = me.loadMap(mapNames[i]);
		loadMaptoCampaign(mapNames[i], m);
	}

}

void Campaign::loadMaptoCampaign(string mapName, Map m)
{
	mapOfGameMaps.insert(std::make_pair(mapName, m));
}

void Campaign::addMaptoCampaign(string mapName, Map m) {
	mapOfGameMaps.insert(std::make_pair(mapName, m));
	mapNames.push_back(mapName + ".txt");
}



