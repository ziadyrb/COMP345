#include "Map.h"
#include "Builder.h"

using namespace std;

int main() {

	Map map1 = Map(15 , 15);
	printMap(map1);

	EditBuilder b;

	b.buildMap("mapPrint.txt");


	system("PAUSE");

	return 0;
}