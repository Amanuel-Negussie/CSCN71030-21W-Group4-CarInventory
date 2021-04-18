#pragma once
#include <iostream>
#include <string>
#include "SaveLoad.h"
#include "Lists.h"


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
	Inventory(char make[MAX_LEN], char model[MAX_LEN], char VIN[MAX_LEN], LABEL label, int price, int cost);//Parameterize
	Inventory(Inventory&);//Copy constructor
	void copy(Inventory& copyObject); //copy
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

	friend void printInventory(void* inventory);
};
void printInventoryList(Lists<Inventory>* list);

void printInventory(void* inventory);