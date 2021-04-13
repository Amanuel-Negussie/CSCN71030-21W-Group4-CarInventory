#pragma once
#include <iostream>
#include <string>
#include "SaveLoad.h"
#include "Inventory.h"
#include "Customer.h"
#include "Users.h"

#define MAX_LEN 30

using namespace std;

class TransactionHistory : public SAVELOAD {

private:

	char transactionID[MAX_LEN];
	Inventory* inventory;
	Customer* customer;
	Users* user;

public:

	TransactionHistory(char[MAX_LEN], Inventory*, Customer*, Users*);
	TransactionHistory(TransactionHistory&);
	~TransactionHistory();
	
	void save(ofstream& out) override;
	void load(ifstream& in) override;

	void printTransaction(void);


};

