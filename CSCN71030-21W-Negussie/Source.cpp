/*
CSCN7103021W-Negussie 


*/

#include <iostream>
#include "Customer.h"
#include "Lists.h"
#include "Lists.cpp"
#include "Node.cpp"
#include "SaveLoad.h"
#include "Validation.h"

#define STRLEN_MAX 30

using namespace std;


int main(void){
	char firstName[] = "Hanan";
	char lastName[] = "Mohammed";
	char secondFirstName[] = "WEiRDO";
	char secondLastName[] = "BOOGER";
	char longFName[] = "12345678901234567890123456789";

	
	Customer longCustomer(longFName, longFName, INT_MAX);
	Customer Hanan(firstName,lastName,24);
	Customer Hanadi(secondFirstName,secondLastName, 25);
	Hanan.print(); //print out Hanan
	Hanadi.print(); // print out Weirdo
	string noNameFile{ "Testing" };
	string textFile{ "Testing.txt" };
	ofstream out(textFile);
	Hanadi.save(out);
	out.close();
	ifstream in(textFile);
	Hanan.load(in);
	in.close();

	Customer* newCustomer = new Customer(firstName, lastName, 24);
	Customer* newCustomer1 = new Customer(secondFirstName, secondLastName, 25);
	Lists<Customer> customers;
	customers.addToList(newCustomer);
	customers.addToList(newCustomer1);

	customers.save("Jacky.txt");
	
	customers.peekHead()->print();
	Lists<Customer> customersL1;
	customersL1.load("Jacky.txt");
	customersL1.peekHead()->print();
	customersL1.save("Amanuel.txt");

	string s("123456789012345678901234567890123456789012345678901234567890");
	string t("Hello YOU GUYS");
	char myCharArray[STRLEN_MAX];
	stringToCharArray(s, myCharArray,STRLEN_MAX);
	stringToCharArray(t, myCharArray, STRLEN_MAX);

	return 0;
}