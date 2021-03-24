#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;

int main(void) {

	char myMake[MAX_LEN] = "Ford";
	char myModel[MAX_LEN] = "Escape";
	char myVIN[MAX_LEN] = "ABC123";

	Inventory myInventory(myMake, myModel, myVIN, SUV, 25999, 19999);
	myInventory.printInventory();

	cout << endl << endl;
	cout << myInventory.getMake() << endl;
	cout << myInventory.getModel() << endl;
	cout << myInventory.getVIN() << endl;
	cout << myInventory.getLabel() << endl;
	cout << myInventory.getPrice() << endl;
	cout << myInventory.getCost() << endl;
	
	return 0;

}


