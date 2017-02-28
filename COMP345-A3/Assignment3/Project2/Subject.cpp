#include <list>
#include <iterator>
#include "Observer.h"
#include "Subject.h"
#include "Map.h"
using namespace std;

void Subject::attach(Observer* o)
{
	observers.push_back(o);
}

void Subject::detach(Observer* o)
{
	observers.remove(o);
}

void Subject::notify() {
	for (auto observer : observers) {
		observer->update();
	}
}

void Subject::confirmMessage()
{
	message = ""; // message that will get writting to GameLog
}
