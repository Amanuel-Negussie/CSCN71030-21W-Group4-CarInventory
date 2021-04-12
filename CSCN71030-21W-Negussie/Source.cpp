/*
CSCN7103021W-Negussie 


*/

#include <iostream>
#include "Customer.h"
#include "SaveLoad.h"
#include "Users.h"

using namespace std;


int main(void){
    //---------------------------------------------------------------------
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
    //RESULT: PASSED
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
	//RESULT: PASSED 
    //---------------------------------------------------------------------

    //Testing Integration for Users and Save/Load
    //USR-SAV-001
    
    //Load input into variables
    char username[] = "Eazaz";
    char password[] = "Password1";
    char userID[] = "EazazJ1";

    //Create and open "Users.txt" file to save Users into
    ofstream userOutputFile("Users.txt");

    //Create a user of type Admin
    Admin Eazaz(username, password, userID);

    //Save the Admin object to the file "Users.txt"
    Eazaz.save(userOutputFile);
    userOutputFile.close();

    //Expectations: Users.txt file will be created, and in file User Eazaz
	//				and its contents will be present
    // RESULT: PASSED


    //USR-SAV-002

    //Open "Users.txt" file to load objects from
    ifstream userInputFile("Users.txt");

    //Create empty object to load User object from "Users.txt" file into
    Admin EazazLoaded;

    printf("BEFORE LOAD:\n");
    EazazLoaded.displayUser();

    //Load the User object from file into empty User Object
    EazazLoaded.load(userInputFile);

    userInputFile.close();

    printf("AFTER LOAD:\n");
    EazazLoaded.displayUser();
    //Expectations: Contents of Eazaz object that was saved to Users.txt file will
	//				be placed into Empty Admin object. Validated by contents printed out 
    //Results: PASSED
    //---------------------------------------------------------------------



	return 0;
}