#include "Builder.h"
// LOAD MAP FROM FILE

void EditBuilder::buildMap(string filename)
{
	ifstream active;
	active.open(filename);

	int x, y;
	char t;

	active >> y >> x;
	Map m = Map(x, y);

	for (unsigned int i = 0; i < y; i++)
	{
		for (unsigned int j = 0; j < x; j++)
		{
			active >> t;
			switch (t) {
			case 'n':
				map.fillCell(j, i, t, m);
				break;
			case 'd':
				map.fillCell(j, i, 'd', m);
				break;
			case 'c':
				map.fillCell(j, i, 'c', m);
				break;
			case 'e':
				map.fillCell(j, i, 'e', m);
				break;
			case 'w':
				map.fillCell(j, i, 'w', m);
				break;
			default:
				break;
			}
		}
	}

	active.close();
}