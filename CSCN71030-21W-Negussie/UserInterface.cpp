#include "UserInterface.h"

using namespace std;

void mainMenu(Users* activeUser, Lists<Users> myUserList) {

	cout << "Welcome " << activeUser->getUsername() << " to Really Good Dealership Management System" << endl;
	
	
	

	switch (activeUser->getUserType())
	{
	case ADM:
		cout << "You have Admin level access:" << endl;
		cout << "ONLY ADMIN LEVEL" << endl; 
		cout << "____________________" << endl;
		cout << "1. Add User" << endl;
		cout << "2. Remove User" << endl;
		cout << "____________________" << endl;
		cout << "3. Add Inventory" << endl;
		cout << "4. Remove Inventory" << endl;
		cout << "5. Make a Sale" << endl;
		cout << "6. View Inventory" << endl;
		cout << "7. View Customer" << endl;
		cout << "8. View Transaction History" << endl;
		cout << "0. Save and Exit." << endl;


		//MNG DUTIES

		//ADM DUTIES

		break;

	case MNG:
		cout << "You have Manager level access:" << endl;
		cout << "ONLY MANAGER LEVEL" << endl;
		cout << "____________________" << endl;
		cout << "1. Add Inventory" << endl;
		cout << "2. Remove Inventory" << endl;
		cout << "____________________" << endl;
		cout << "3. Make a Sale" << endl;
		cout << "4. View Inventory" << endl;
		cout << "5. View Customer" << endl;
		cout << "6. View Transaction History" << endl;
		cout << "0. Save and Exit." << endl;

		//MNG DUTIES

		break;

	case SAL:

		cout << "You have Sales Representative level access:" << endl;
		cout << "1. Make a Sale" << endl;
		cout << "2. View Inventory List" << endl;
		cout << "3. View Customer List" << endl;
		cout << "4. View Transaction History" << endl;
		cout << "0. Save and Exit." << endl;

		cout << "Please a selection: " << endl;
		string userInput;

		break;
	}

	return;




}