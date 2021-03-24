#include "Customer.h"
/*
Customer::Customer() {
	strncpy_s(this->firstName, " ", FIRST_NAME_LEN);
	strncpy_s(this->lastName, " ", LAST_NAME_LEN);
	this->age = -1;
}
*/


Customer::Customer() :firstName(""), lastName(""), age(-1) {
}

Customer::~Customer()
{
}

Customer::Customer(char firstName [FIRST_NAME_LEN], char lastName [LAST_NAME_LEN], int age) {
	strcpy_s(this->firstName, FIRST_NAME_LEN, firstName);
	strcpy_s(this->lastName, LAST_NAME_LEN, lastName);
	this->age = age;
}

void Customer::printCustomer(void)
{
	cout << "Customer Name is " << this->firstName << " " << this->lastName << " and their age is " << this->age << endl;
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








