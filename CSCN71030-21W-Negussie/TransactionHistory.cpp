#include "TransactionHistory.h"

TransactionHistory::TransactionHistory(char transactionID[MAX_LEN], Inventory* inventory, Customer* customer, Users* user) {

	strcpy_s(this->transactionID, MAX_LEN, transactionID);
	this->inventory = inventory;
	this->customer = customer;
	this->user = user;

}

TransactionHistory::TransactionHistory(TransactionHistory& rhs) {

	strcpy_s(this->transactionID, MAX_LEN, rhs.transactionID);
	*(this->inventory) = *(rhs.inventory);
	*(this->customer) = *(rhs.customer);
	*(this->user) = *(rhs.user);

}

TransactionHistory::~TransactionHistory() {

	delete this->inventory;
	delete this->customer;
	delete this->user;

}

void TransactionHistory::printTransaction(void) {

	cout <<"\nTransaction ID: " << this->transactionID << endl;
	this->inventory->printInventory();
	this->customer->printCustomer();
	this->user->displayUser();
	cout << endl;

}

void TransactionHistory::save(ofstream& out) {

	SAVE(this, sizeof(*this), out);

}

void TransactionHistory::load(ifstream& in) {

	LOAD(this, sizeof(*this), in);

}



