/*#pragma once
#include "Subject.h"
//#include "Map.h"
class Subject;
class Observer {
public:
	virtual ~Observer() {};
	virtual void update(Subject* o) = 0;
protected:
	Observer() {};
};
*/

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
