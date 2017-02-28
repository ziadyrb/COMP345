#include "Dice.h"

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
	 std::cout <<"Result: "<< n << endl;

	 std::cout << "Rolling a d6 1 time." << endl;
	 n = d.roll("1d6");
	 std::cout << "Result: " << n << endl;


	 system("PAUSE");

	 return 0;

};