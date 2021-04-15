/*
CSCN7103021W-Negussie


*/

#include <iostream>
#include "Customer.h"
#include "SaveLoad.h"
#include "Users.h"
#include "Inventory.h"
#include "Lists.h"
//#include "Node.cpp"
//#include "Lists.cpp"
#include "TransactionHistory.h"
#include "Validation.h"
#include "UserInterface.h"


using namespace std;
/*
1. LOAD USER ARRAY DATA
2. RECEIVE INPUT OR IF FIRST USER->SET UP INFORMATION FOR PASSWORD
*/

int main (void) {


	
	//LOADING ARRAY AND SETTING UP ADMIN OR VERIFYING USER 
	initializeElementsUserArray();
	string userNameInput, userPasswordInput;
	char UserName[MAX_LEN];
	char UserPassword[MAX_LEN];
	if (!loadArray())
	{
		//setup UserName and Password for Admin 
		cout << "Did not load past user data." << endl;
		cout << "Please create a new ADMIN user." << endl;
		
	}
	else
	{
		//verification of User Input
		bool isVerified = false; 
		while (!isVerified)
		{
			cout << "\nHELLO: What's your username?";
			cin >> userNameInput;
			cout << "\nHELLO " << userNameInput << " what's your password?";
			cin >> userPasswordInput;

			stringToCharArray(userNameInput, UserName, MAX_LEN); //converting it to char array 
			stringToCharArray(userPasswordInput, UserPassword, MAX_LEN); //converting it to char array 


			if (verifyCredentials(UserName, UserPassword))
			{
				cout << "\nVerified!" << endl;
				isVerified = true;
			}
			else
			{
				cout << "\nIncorrect username or password! Try again.\n" << endl;
			}
		}


		//after a set amount of times shutdown// return -1;
	}
	//AFTER VERIFICATION 
	//
	Lists<Users> myUserList; 
	myUserList.load("Users.txt");
		
	//search through list find User and Password 
	Users* myUser = findUserInList(myUserList, UserName, UserPassword);
	if (!(myUser))
	{
		cout << "Something went wrong. We're sorry." << endl;
	}
	else
	{
		cout << "THIS WORKS" << endl;
	}

	mainMenu(myUser);

	/*
	* SETUP IS COMPLETE
	*/
	
	//while (true) {

	//	mainMenu(); // Takes the user type to the main menu. Menu will filter different options based on user type.

	//}

	return 0;

}



void mainMenu(Users* activeUser) {

	cout << "Welcome "<< activeUser->getUsername() <<" to Really Good Dealership Management System" << endl;
	
	string userInput;
	switch (activeUser->getUserType())
	{
	case ADM:

		cout << "You have Administrator level access:" << endl;
		cout << "1. Add an Inventory." << endl;
		cout << "2. Delete an Inventory." << endl;
		cout << "3. test " << endl;
		cout << "0. Save and Exit." << endl;

		cout << "Please a selection: " << endl;
		


		//MNG DUTIES

		//ADM DUTIES

		break;

	case MNG:

		cout << "Add an Inventory." << endl;
		cout << "Delete an Inventory." << endl;
		cout << "test " << endl;

		//MNG DUTIES

		break;

	case SAL:

		cout << "You have Sales Representative level access:" << endl;
		cout << "1. Add an Inventory." << endl;
		cout << "2. Delete an Inventory." << endl;
		cout << "3. test " << endl;
		cout << "0. Save and Exit." << endl;

		cout << "Please a selection: " << endl;
		string userInput;

		break;
	}

	return ;

	


}

