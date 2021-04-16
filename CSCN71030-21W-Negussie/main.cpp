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

	Lists<Customer> myCustomerList; 
	myCustomerList.load("Customer.txt"); 
	myCustomerList.getItemFromList(1)->printCustomer();
	printCustomerList(&myCustomerList);
	Lists<Inventory> myInventoryList;
	myInventoryList.load("Inventory.txt");
	printInventoryList(&myInventoryList);
	myInventoryList.getItemFromList(1)->printInventory();
	Lists<TransactionHistory> myTransactionHistoryList;
	char hello[30] = "FRIENDS";
	TransactionHistory a (hello, *(myInventoryList.getHeadOfList()->getNodeData()), *(myCustomerList.getHeadOfList()->getNodeData()), *(myUserList.getHeadOfList()->getNodeData()));
	myTransactionHistoryList.load("TransactionHistory.txt");
	printTransactionHistoryList(&myTransactionHistoryList);
	myTransactionHistoryList.getItemFromList(1)->printTransaction();
	
	myCustomerList.printingFunction(printCustomer);

	mainMenu(myUser, myUserList);

	/*
	* SETUP IS COMPLETE
	*/
	
	//while (true) {

	//	mainMenu(); // Takes the user type to the main menu. Menu will filter different options based on user type.

	//}

	return 0;

}





