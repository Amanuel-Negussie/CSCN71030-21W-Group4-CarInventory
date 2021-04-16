#include "Customer.h"
#include "Lists.cpp"
#include "Node.cpp"

#include <vector>

/*
Customer::Customer() {
	strncpy_s(this->firstName, " ", FIRST_NAME_LEN);
	strncpy_s(this->lastName, " ", LAST_NAME_LEN);
	this->age = -1;
}
*/



Customer::Customer() :firstName("Unset"), lastName("Unset"), age(-1) {

}

Customer::Customer(const Customer& copyObject) {
	strcpy_s(this->firstName, FIRST_NAME_LEN, copyObject.firstName);
	strcpy_s(this->lastName, LAST_NAME_LEN, copyObject.lastName);
	this->age = copyObject.age;
}

void Customer::copy( Customer& copyObject) {
	strcpy_s(this->firstName, FIRST_NAME_LEN, copyObject.firstName);
	strcpy_s(this->lastName, LAST_NAME_LEN, copyObject.lastName);
	this->age = copyObject.age;
}

Customer::~Customer()
{
	
}

Customer::Customer(char firstName[FIRST_NAME_LEN], char lastName[LAST_NAME_LEN], int age) {
	strcpy_s(this->firstName, FIRST_NAME_LEN, firstName);
	strcpy_s(this->lastName, LAST_NAME_LEN, lastName);
	this->age = age;
}

//setters and getters
//getters and setters 
char* Customer::getFirstName(void) {
	return this->firstName;
}
char* Customer::getLastName(void) {
	return this->lastName;
}
int Customer::getAge(void) {
	return this->age;
}

void Customer::setFirstName(char firstName[FIRST_NAME_LEN]) {
	strcpy_s(this->firstName, FIRST_NAME_LEN, firstName);
}
void Customer::setLastName(char lastName[LAST_NAME_LEN]) {
	strcpy_s(this->lastName, LAST_NAME_LEN, lastName);
}
void Customer::setAge(int age) {
	this->age = age;
}


//print and save and load functions//
void Customer::printCustomer(void)
{
	cout << "Customer Name is " << this->firstName << " " << this->lastName << " and their age is " << this->age << endl;
}

void printCustomer(void* customer)
{
  Customer* temp = (Customer*) customer;
	cout << "Customer Name is " << temp->getFirstName() << " " << temp->getLastName() << " and their age is " << temp->getAge() << endl;
}


//void Customer::printCustomerList(Lists<Customer> list) {
//	int num = list.getNumOfItems() + 1;
//	list.setLastVisitedToHead();
//	for (int i = 1; i < num; i++) {
//		cout << i << ". ";
//		list.getLastVistedNodeData()->printCustomer();
//		list.setLastVistedToNext();
//	}
//	list.setLastVisitedToNULL();
//}


void printCustomerList(Lists<Customer>* list)
{
	int num = list->getNumOfItems() + 1;
	list->setLastVisitedToHead();
	for (int i = 1; i < num; i++) {
		cout << i << ". ";
		list->getLastVistedNodeData()->printCustomer();
		list->setLastVistedToNext();
	}
	list->setLastVisitedToNULL();
}

void Customer::save(ofstream& out)
{
	SAVE(this, sizeof(*this), out);
}

void Customer::load(ifstream& in)
{
	LOAD(this, sizeof(*this), in);
}

/*
void write(const std::string& file_name, s& data)
{
	std::ofstream out(file_name.c_str());
	out.write(reinterpret_cast<char*>(&s), sizeof(s));
}
referenced from: https://forums.codeguru.com/showthread.php?269648-C-Structure-How-do-I-write-a-structure-to-a-file
void read(const std::string& file_name, s& data)
{
	std::ifstream in(file_name.c_str());
	in.read(reinterpret_cast<char*>(&s), sizeof(s));
}
*/









