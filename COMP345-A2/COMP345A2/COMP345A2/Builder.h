#pragma once
#ifndef Builder_h
#define Builder_h

#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"

using namespace std;

class Builder
{

public:
	Map map;
public:
	virtual void buildMap(string) = 0;
};

class EditBuilder : public Builder
{

public:
	void buildMap(string);
};

#endif /* Builder_h */