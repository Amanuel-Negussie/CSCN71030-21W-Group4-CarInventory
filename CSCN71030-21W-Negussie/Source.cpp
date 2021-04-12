/*
CSCN7103021W-Negussie 


*/

#include <iostream>
#include "Customer.h"
#include "SaveLoad.h"

using namespace std;


int main(void){
	//Testing Integration for Save/Load Customer
	//CUS-SVLD-001 
	char firstName[] = "John";
	char lastName[] = "Doe";
	ofstream outputFile("Customer.txt");  //ofstream with file name created
	Customer JohnDoe (firstName,lastName,30); //Customer object created
	JohnDoe.save(outputFile);
	outputFile.close(); 
	//Expectations: Customer.txt file will be created, and in file Customer John Doe
	//				and its contents will be present

	//CUS-SVLD-002 
	ifstream  inputFile("Customer.txt"); //ifstream with file name 
	Customer EmptyCustomer; //Empty Customer created
	printf("BEFORE LOAD:\n");
	EmptyCustomer.printCustomer(); //printing Customer prior to file load 
	EmptyCustomer.load(inputFile); //load object info from file into Customer object
	inputFile.close();
	printf("AFTER LOAD:\n");
	EmptyCustomer.printCustomer();
	//Expectations: Contents of John Doe object that was saved to Customer.txt file will
	//				be placed into Empty Customer object. Validated by contents printed out Empty Customer print call
	
	


	return 0;
}