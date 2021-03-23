#include "Inventory.h"

Inventory::Inventory() {

	this->make = "Unset";
	this->model = "Unset";
	this->VIN = "Unset";
	this->label = Unset;
	this->price = 0;
	this->cost = 0;

}

Inventory::Inventory(string make, string model, string VIN, LABEL label, int price, int cost) { //Parameterize

	this->make = make;
	this->model = model;
	this->VIN = VIN;
	this->label = label;
	this->price = price;
	this->cost = cost;

}

Inventory::Inventory(Inventory& copyObject) { //Copy constructor

	this->make = copyObject.make;
	this->model = copyObject.model;
	this->VIN = copyObject.VIN;
	this->label = copyObject.label;
	this->price = copyObject.price;
	this->cost = copyObject.cost;

}

Inventory::~Inventory() { //Destructor

	delete this; //Nothing allocated on the heap. Does this clear the item from memory still?

}

string Inventory::getMake(void) {

	return this->make;

}

void Inventory::setMake(string make) {

	this->make = make;

}

string Inventory::getModel(void) {

	return this->model;

}

void Inventory::setModel(string model) {

	this->model = model;

}

string Inventory::getVIN(void) {

	return this->VIN;

}

void Inventory::setVIN(string VIN) {

	this->VIN = VIN;

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
	cout << "Label: " << this->label << endl;
	cout << "Price: " << this->price << endl;
	cout << "Cost: " << this->cost << endl;

}

//Inventory::save
//Inventory::load