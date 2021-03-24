#include "Inventory.h"

Inventory::Inventory():make("Unset"), model("Unset"), VIN("Unset"), label(Unset), price(0), cost(0) {

}

Inventory::Inventory(char make[MAX_LEN], char model[MAX_LEN], char VIN[MAX_LEN], LABEL label, int price, int cost) { //Parameterize

	strcpy_s(this->make, MAX_LEN, make);
	strcpy_s(this->model, MAX_LEN, model);
	strcpy_s(this->VIN, MAX_LEN, VIN);	
	this->label = label;
	this->price = price;
	this->cost = cost;

}

Inventory::Inventory(Inventory& copyObject) { //Copy constructor

	strcpy_s(this->make, MAX_LEN, copyObject.make);
	strcpy_s(this->model, MAX_LEN, copyObject.model);
	strcpy_s(this->VIN, MAX_LEN, copyObject.VIN);
	this->label = copyObject.label;
	this->price = copyObject.price;
	this->cost = copyObject.cost;

}

Inventory::~Inventory() { //Destructor



}

char* Inventory::getMake(void) {

	return this->make;

}

void Inventory::setMake(char make[MAX_LEN]) {

	strcpy_s(this->make, MAX_LEN, make);

}

char* Inventory::getModel(void) {

	return this->model;

}

void Inventory::setModel(char model[MAX_LEN]) {

	strcpy_s(this->model, MAX_LEN, model);

}

char* Inventory::getVIN(void) {

	return this->VIN;

}

void Inventory::setVIN(char VIN[MAX_LEN]) {

	strcpy_s(this->VIN, MAX_LEN, VIN);

}

LABEL Inventory::getLabel(void) {

	return this->label;

}

void Inventory::setLabel(LABEL label) {

	this->label = label;

}

int Inventory::getPrice(void) {

	return this->price;

}

void Inventory::setPrice(int price) {

	this->price = price;

}

int Inventory::getCost(void) {

	return this->cost;

}

void Inventory::setCost(int cost) {

	this->cost = cost;
}

void Inventory::printInventory(void) {

	cout << "Make: " << this->make << endl;
	cout << "Model: " << this->model << endl;
	cout << "VIN: " << this->VIN << endl;
	labelToString(this->label);
	cout << "Price: " << this->price << endl;
	cout << "Cost: " << this->cost << endl;

}

void Inventory::save(ofstream& out) {
	
	SAVE(this, sizeof(*this), out);

}

void Inventory::load(ifstream& in) {
	
	LOAD(this, sizeof(*this), in);

}

void Inventory::labelToString(LABEL label) {

	cout << "Type: ";

	switch (label)
	{

	case Unset: 

		cout << "Unset" <<endl;
		break;

	case Sedan:

		cout << "Sedan" << endl;
		break;

	case SUV:

		cout << "SUV" << endl;
		break;

	case Truck:

		cout << "Truck" << endl;
		break;

	case Crossover:

		cout << "Crossover" << endl;
		break;

	case RV:

		cout << "RV" << endl;
		break;

	default:

		break;

	}

}
