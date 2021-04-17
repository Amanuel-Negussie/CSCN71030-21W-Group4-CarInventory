#include "TransactionHistory.h"

void printTransactionHistoryList(Lists<TransactionHistory>* list)
{
	int num = list->getNumOfItems() + 1;
	list->setLastVisitedToHead();
	for (int i = 1; i < num; i++) {
		cout << i << ". ";
		list->getLastVistedNodeData()->printTransaction();
		list->setLastVistedToNext();
	}
	list->setLastVisitedToNULL();
}

TransactionHistory::TransactionHistory() {

}
	


TransactionHistory::TransactionHistory(int transactionID, Inventory& inventory, Customer& customer, Users& user) {

	this->transactionID = transactionID;
	this->inventory.copy(inventory);
	this->customer.copy(customer);
	this->user.copy(user);

}

TransactionHistory::TransactionHistory(TransactionHistory& rhs) {

	this->transactionID = rhs.transactionID;
	this->inventory.copy(rhs.inventory);
	this->customer.copy(rhs.customer);
	this->user.copy(rhs.user);
}

TransactionHistory::~TransactionHistory() {

	//delete this->inventory;
	//delete this->customer;
	//delete this->user;

}

void TransactionHistory::printTransaction(void) {
	cout <<"\nTransaction ID: " << this->transactionID << endl;
	this->inventory.printInventory();
	this->customer.printCustomer();
	this->user.displayUser();
	cout << endl;
}

void printTransaction(void* transaction) {
	TransactionHistory* temp = (TransactionHistory*)transaction;
	cout <<"\nTransaction ID: " << temp->transactionID << endl;
	temp->inventory.printInventory();
	temp->customer.printCustomer();
	temp->user.displayUser();
	cout << endl;
}

void TransactionHistory::save(ofstream& out) {
	SAVE(this, sizeof(*this), out);
}

void TransactionHistory::load(ifstream& in) {

	LOAD(this, sizeof(*this), in);

}



