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
	


TransactionHistory::TransactionHistory(char transactionID [MAX_LEN], Inventory& inventory, Customer& customer, Users& user) {

	strcpy_s(this->transactionID, MAX_LEN, transactionID);
	this->inventory.copy(inventory);
	this->customer.copy(customer);
	this->user.copy(user);

}

TransactionHistory::TransactionHistory(TransactionHistory& rhs) {

	strcpy_s(this->transactionID, MAX_LEN, rhs.transactionID);
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

void TransactionHistory::save(ofstream& out) {
	SAVE(this, sizeof(*this), out);
}

void TransactionHistory::load(ifstream& in) {

	LOAD(this, sizeof(*this), in);

}



