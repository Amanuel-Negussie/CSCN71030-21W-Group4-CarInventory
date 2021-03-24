#pragma once
#include <iostream>
#include <string>
#include "SaveLoad.h"

using namespace std;

typedef enum label { Unset, Sedan, SUV, Truck, Crossover, RV } LABEL;

class Inventory : public SAVELOAD {

private:

	string make;
	string model;
	string VIN;
	LABEL label;
	int price;
	int cost;

public:

	Inventory();
	Inventory(string, string, string, LABEL, int, int);//Parameterize
	Inventory(Inventory&);//Copy constructor
	~Inventory();//Destructor
	string getMake(void);
	void setMake(string make);
	string getModel(void);
	void setModel(string model);
	string getVIN(void);
	void setVIN(string VIN);
	LABEL getLabel(void);
	void setLabel(LABEL label);
	int getPrice(void);
	void setPrice(int price);
	int getCost(void);
	void setCost(int cost);
	void printInventory(void);
	void save(ofstream& out) override;
	void load(ifstream& in) override;

};
