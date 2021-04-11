/*
CSCN7103021W-Negussie


*/

#include <iostream>
#include "Customer.h"

using namespace std;


int main(void) {
	//creating variables that would be input paramater
	char AmanuelFirstName[FIRST_NAME_LEN] = "Amanuel";
	char AmanuelLastName[LAST_NAME_LEN] = "Negussie";
	char WRONG_FIRST_NAME[FIRST_NAME_LEN] = "WRONG FIRST NAME";
	char WRONG_LAST_NAME[LAST_NAME_LEN] = "WRONG LAST NAME";
	int AmanuelAge = 25;

	//paramaterized constructor
	Customer Amanuel(AmanuelFirstName, AmanuelLastName, AmanuelAge);

	//Customer print Customer
	cout << "PRINT FUNCTION PARAMATERIZED CONSTRUCTION " << endl;
	Amanuel.printCustomer();
	cout << endl;

	//Customer save Customer to File
	cout << "SAVING TO CUSTOMER.TXT" << endl;
	ofstream out("Customer.txt");
	Amanuel.save(out);
	out.close();
	cout << endl;

	//Default Constructor 
	cout << "DEFAULT CONSTRUCTOR USED:" << endl;
	Customer AmanuelCopy;  //default constructor
	cout << "Here is AmanuelCopy before loading the Object in File into the AmanuelCopy: " << endl;
	AmanuelCopy.printCustomer();

	//Using Setters: setting Amanuel to different info (WRONG INFO)
	Amanuel.setAge(250);
	Amanuel.setFirstName(WRONG_FIRST_NAME);
	Amanuel.setLastName(WRONG_LAST_NAME);
	cout << "Amanuel info after setting it to WRONG INFO" << endl;

	//Using Getters 
	cout << "FIRST NAME: " << Amanuel.getFirstName() << "\tLAST NAME: " << Amanuel.getLastName() << "\tAGE: " << Amanuel.getAge() << endl;

	//LOAD 
	ifstream in("Customer.txt");
	AmanuelCopy.load(in);
	in.close();

	//Print AmanuelCopy -> should print out contents of Amanuel
	cout << "\nHere is the AmanuelCopy after loading the Object into AmanuelCopy: " << endl;
	AmanuelCopy.printCustomer();

	//Print Amanuel 
	cout << "HERE IS AMANUEL'S INFO BEFORE COPYING AMANUELCOPY INTO Amanuel" << endl;
	Amanuel.printCustomer();

	//COPY CONSTRUCTOR: printing Amanuel after copying info from AmanuelCopy 
	Amanuel = *(new Customer(AmanuelCopy));
	cout << "\nHERE IS AMANUEL'S INFO AFTER COPYING AMANUEL COPY" << endl;
	Amanuel.printCustomer();

	//main
	//
	//INSTATIATE LISTS LOAD OBJECTS INTO LISTS 
	//VALIDATE USER  
	// char* userArray[MAX_USERS][MAX_PARAMS];

	// USER: Amanuel Negussie Password: Hello123 
	// USER: Jacky Password Jack123 

	char* myArray[10][2];
	char myArray[10][2][30];
	memset(myArray, NULL, 20 * sizeof(char*));
	char myName[30] = "amanuel";
	myArray[0][0] = myName;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 2; j++)
		{
			myArray[i][j] = myName;
		}

	ofstream fp("ARRAY.txt");
	SAVE(myArray, 20 * sizeof(char), fp);
	fp.close();
	ifstream OP("ARRAY.txt");
	char* myFriendArray[10][2];
	memset(myFriendArray, NULL, 20 * sizeof(char*));

	LOAD(myFriendArray, 20 * sizeof(char*), OP);















	return 0;
}



