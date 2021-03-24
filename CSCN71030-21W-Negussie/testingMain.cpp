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
	cout << endl << endl;

	char newMake[MAX_LEN] = "Tesla";
	char newModel[MAX_LEN] = "Model 3";
	char newVIN[MAX_LEN] = "D4E5F6";

	Inventory newInventory(newMake, newModel, newVIN, Sedan, 59999, 45999);
	newInventory.printInventory();
	
	cout << endl << endl;
	cout << newInventory.getMake() << endl;
	cout << newInventory.getModel() << endl;
	cout << newInventory.getVIN() << endl;
	cout << newInventory.getLabel() << endl;
	cout << newInventory.getPrice() << endl;
	cout << newInventory.getCost() << endl;
	cout << endl << endl;

	char newMakeUpdate[MAX_LEN] = "Mazda";
	char newModelUpdate[MAX_LEN] = "CX-7";
	char newVINUpdate[MAX_LEN] = "AAA111";

	newInventory.setMake(newMakeUpdate);
	newInventory.setModel(newModelUpdate);
	newInventory.setVIN(newVINUpdate);
	newInventory.setLabel(Crossover);
	newInventory.setPrice(17999);
	newInventory.setCost(15999);

	newInventory.printInventory();


	return 0;

}



