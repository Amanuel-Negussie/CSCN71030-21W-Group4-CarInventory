/*
CSCN7103021W-Negussie


*/

#include "UserInterface.h"

using namespace std;
/*
1. LOAD USER ARRAY DATA
2. RECEIVE INPUT OR IF FIRST USER->SET UP INFORMATION FOR PASSWORD
*/

int main (void) {

	Lists<Users> myUserList;
	
	//LOADING ARRAY AND SETTING UP ADMIN OR VERIFYING USER 
	initializeElementsUserArray();

	string userNameInput, userPasswordInput;
	char UserName[MAX_LEN];
	char UserPassword[MAX_LEN];
	if (!loadArray())
	{
		
		char usernameChoice[MAX_LEN] = "";
		char passwordChoice[MAX_LEN] = "";
		char useridChoice[MAX_LEN] = "";

		//setup UserName and Password for Admin 

		cout << "...Could not load any previous user data..." << endl;
		cout << endl;
		cout << "Let's set up your new Administrator!" << endl;
		cout << endl;

		cout << "Please enter the username for the Admin:" << endl;
		cin >> usernameChoice;
		cout << "Please enter the user ID for the Admin:" << endl;
		cin >> useridChoice;
		cout << "Please enter the password for the Admin:" << endl;
		cin >> passwordChoice;
		
		myUserList.addToList(new Admin(usernameChoice, passwordChoice, useridChoice));
		myUserList.save(USR_FILE);
		saveArray();

		cout << "Your Administrator has been set-up. Please restart the program for full integration." << endl;

		return 0;

	}
	else
	{
		//verification of User Input
		bool isVerified = false; 
		while (!isVerified)
		{
			cout << "\nGreetings. Please enter your username: ";
			cin >> userNameInput;
			cout << "\nHello " << userNameInput << "." << " Please enter your password: ";
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

	}
		
	//search through list find User and Password 
	myUserList.load(USR_FILE);
	Users* myUser = findUserInList(myUserList, UserName, UserPassword);

	if (!(myUser))
	{
		cout << "Something went wrong. We're sorry." << endl;
	}
	else
	{
		cout << "THIS WORKS" << endl;
	}

	Lists<Customer> myCustomerList; 
	myCustomerList.load(CUS_FILE);
	//myCustomerList.getItemFromList(1)->printCustomer();
	//printCustomerList(&myCustomerList);

	Lists<Inventory> myInventoryList;
	myInventoryList.load(INV_FILE);
	//printInventoryList(&myInventoryList);
	//myInventoryList.getItemFromList(1)->printInventory();

	Lists<TransactionHistory> myTransactionHistoryList;
	//TransactionHistory a (30, *(myInventoryList.getHeadOfList()->getNodeData()), *(myCustomerList.getHeadOfList()->getNodeData()), *(myUserList.getHeadOfList()->getNodeData()));
	myTransactionHistoryList.load(TH_FILE);
	//printTransactionHistoryList(&myTransactionHistoryList);
	//myTransactionHistoryList.getItemFromList(1)->printTransaction();
	
	//myCustomerList.printingFunction(printCustomer);

	mainMenu(myUser, myUserList, myInventoryList, myCustomerList, myTransactionHistoryList);

	return 0;

}





