#pragma once

#include "Subject.h"

class Subject;
class Observer
{
public:
	Subject *subject;
	virtual ~Observer();
	virtual void update() = 0;
	virtual void logMessage();

protected:
	Observer();
};

