#pragma once
#include <iostream>
#include <string>
#include "SaveLoad.h"

#define MAX_LEN 30

using namespace std;

typedef enum label { Unset, Sedan, SUV, Truck, Crossover, RV } LABEL;

class Inventory : public SAVELOAD {

private:

	char make[MAX_LEN];
	char model[MAX_LEN];
	char VIN[MAX_LEN];
	LABEL label;
	int price;
	int cost;

public:

	Inventory();
	Inventory(char[MAX_LEN], char[MAX_LEN], char[MAX_LEN], LABEL, int, int);//Parameterize
	Inventory(Inventory&);//Copy constructor
	~Inventory();//Destructor
	char* getMake(void);
	void setMake(char[MAX_LEN]);
	char* getModel(void);
	void setModel(char[MAX_LEN]);
	char* getVIN(void);
	void setVIN(char[MAX_LEN]);
	LABEL getLabel(void);
	void setLabel(LABEL label);
	int getPrice(void);
	void setPrice(int price);
	int getCost(void);
	void setCost(int cost);
	void printInventory(void);
	void save(ofstream& out) override;
	void load(ifstream& in) override;

	void labelToString(LABEL);

};
