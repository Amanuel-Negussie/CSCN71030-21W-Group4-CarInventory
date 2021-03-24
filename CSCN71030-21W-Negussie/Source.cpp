/*
CSCN7103021W-Negussie 


*/

#include <iostream>
#include "Customer.h"

using namespace std;


int main(void){
	char firstName[FIRST_NAME_LEN] = "Hanan";
	char lastName[LAST_NAME_LEN] = "Mohammed";
	char secondFirstName[] = "WEiRDO";
	char secondLastName[] = "BOOGER";
	char longFName[] = "12345678901234567890123456789";

	Customer loser;
	Customer longCustomer(longFName, longFName, INT_MAX);
	Customer Hanan(firstName,lastName,24);
	Customer Hanadi(secondFirstName,secondLastName, 25);
	Hanan.printCustomer(); //print out Hanan
	Hanadi.printCustomer(); // print out Weirdo
	string noNameFile{ "Testing" };
	string textFile{ "Testing.txt" };
	ofstream out(textFile);
	Hanadi.save(out);
	out.close();
	ifstream in(textFile);
	Hanan.load(in);
	in.close();


	return 0;
}