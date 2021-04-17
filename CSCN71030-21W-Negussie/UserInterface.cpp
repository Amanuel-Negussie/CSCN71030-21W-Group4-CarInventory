#include "UserInterface.h"

using namespace std;

void mainMenu(Users* activeUser, Lists<Users>& myUserList, Lists<Inventory>& myInventoryList, Lists<Customer>& myCustomerList, Lists<TransactionHistory>& myTransactionHistoryList) {

	system("cls");

	cout << "Welcome " << activeUser->getUsername() << " to Really Good Dealership Management System" << endl;

	int adminInput;
	int managerInput;
	int salesrepInput;

	/*char usernameChoice[MAX_LEN] = "";
	char passwordChoice[MAX_LEN] = "";
	char useridChoice[MAX_LEN] = "";*/

	//Inventory variables

	/*char make[MAX_LEN];
	char model[MAX_LEN];
	char VIN[MAX_LEN];
	LABEL label;
	int price;
	int cost;*/

	//Transaction History Variables

	/*int transactionHistoryChoice;
	int THCustomerChoice;
	int THInventoryChoice;*/
	//
	//
	//

	//int removeUserChoice;



	bool exit = false;

	while (!exit)

	{
		switch (activeUser->getUserType())
		{
		case ADM:
			cout << "You have Admin level access:" << endl;
			cout << "ONLY ADMIN LEVEL" << endl;
			cout << "____________________" << endl;
			cout << "1. Add User" << endl;
			cout << "2. Remove User" << endl;
			cout << "3. View Users List" << endl;
			cout << "____________________" << endl;
			cout << "4. Add Inventory" << endl;
			cout << "5. Remove Inventory" << endl;
			cout << "6. Make a Sale" << endl;
			cout << "7. View Inventory List" << endl;
			cout << "8. View Customer List" << endl;
			cout << "9. View Transaction History" << endl;
			cout << "0. Save and Exit." << endl;

			cout << "Please make a selection: " << endl;

			cin >> adminInput;

			int userTypeChoice;


			switch (adminInput)
			{
			case 1:		//Add User

				addUser(myUserList);

				break;

			case 2:		//Remover User

				removeUser(myUserList);

				break;

			case 3:		//View Users List

				viewUserList(myUserList);

				break;

			case 4:		//Add Inventroy
				/*char make[MAX_LEN];
				char model[MAX_LEN];
				char VIN[MAX_LEN];
				LABEL label;
				int price;
				int cost;*/


				break;

			case 5:		//Remove Inventory

				break;

			case 6:		//Make a sale

				//makeAsale(myCustomerList, myInventoryList, myTransactionHistoryList);

				break;

			case 7:		//View Inventory List

				viewInventoryList(myInventoryList);

				break;

			case 8:		//View Customer List

				viewCustomerList(myCustomerList);

				break;

			case 9:		//View Transaction History

				viewTransactionHistoryList(myTransactionHistoryList);

				break;

			case 0:		//Save and Exit

				exit = true;

				break;

			default:

				break;
			}

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
			cout << "4. View Inventory List" << endl;
			cout << "5. View Customer List" << endl;
			cout << "6. View Transaction History" << endl;
			cout << "0. Save and Exit." << endl;


			cout << "Please make a selection: " << endl;

			cin >> managerInput;

			switch (managerInput)
			{
			case 1:		//Add Inventory

				break;

			case 2:		//Remover Inventory

				break;

			case 3:		//Make a sale

				break;

			case 4:		//View Inventory List

				break;

			case 5:		//View Customer List

				break;

			case 6:		//View Transaction History

				break;

			case 0:		//Save and Exit

				exit = true;

				break;

			default:

				break;
			}


			//MNG DUTIES

			break;

		case SAL:

			cout << "You have Sales Representative level access:" << endl;
			cout << "1. Make a Sale" << endl;
			cout << "2. View Inventory List" << endl;
			cout << "3. View Customer List" << endl;
			cout << "4. View Transaction History" << endl;
			cout << "0. Save and Exit." << endl;

			cout << "Please make a selection: " << endl;

			cin >> salesrepInput;

			switch (salesrepInput)
			{
			case 1:		//Make a sale

				

				break;

			case 2:		//View Inventory List

				break;

			case 3:		//View Customer List

				break;

			case 4:		//View Transaction History

				break;

			case 0:		//Save and Exit

				exit = true;

				break;

			default:

				break;
			}

			break;
		}


	}
	return;




}

void addUser(Lists<Users>& myUserList)
{

	int userTypeChoice;

	char usernameChoice[MAX_LEN] = "";
	char passwordChoice[MAX_LEN] = "";
	char useridChoice[MAX_LEN] = "";

	cout << "Please choose the type of user you would like to add:\n1. Admin\n2. Manager\n3. Sales Rep" << endl;

	cin >> userTypeChoice;

	switch (userTypeChoice)
	{
	case 1:

		cout << "Please enter the username for the User:" << endl;

		//displayArray();

		cin >> usernameChoice;

		cout << "Please enter the user ID for the User:" << endl;

		cin >> useridChoice;

		cout << "Please enter the password for the User:" << endl;

		cin >> passwordChoice;


		myUserList.addToList(new Admin(usernameChoice, passwordChoice, useridChoice));

		cout << "\nUser succesfully Added." << endl;

		/*myUserList.printingFunction(printUser);

		displayArray();*/

		break;

	case 2:

		cout << "Please enter the username for the User:" << endl;

		//displayArray();

		cin >> usernameChoice;

		cout << "Please enter the user ID for the User:" << endl;

		cin >> useridChoice;

		cout << "Please enter the password for the User:" << endl;

		cin >> passwordChoice;

		myUserList.addToList(new Manager(usernameChoice, passwordChoice, useridChoice));

		cout << "\nUser succesfully Added." << endl;

		break;

	case 3:

		cout << "Please enter the username for the User:" << endl;

		//displayArray();

		cin >> usernameChoice;

		cout << "Please enter the user ID for the User:" << endl;

		cin >> useridChoice;

		cout << "Please enter the password for the User:" << endl;

		cin >> passwordChoice;

		myUserList.addToList(new SalesRep(usernameChoice, passwordChoice, useridChoice));

		cout << "\nUser succesfully Added." << endl;

		break;
	}
}

void removeUser(Lists<Users>& myUserList)
{
	int removeUserChoice;

	cout << "Please choose the User you would like to remove:" << endl;

	myUserList.printingFunction(printUser);

	cin >> removeUserChoice;

	myUserList.removeFromList(removeUserChoice);

	cout << "\nUser removed succesfully." << endl;


}

void viewUserList(Lists<Users>& myUserList)
{
	cout << "List of Users" << endl;

	myUserList.printingFunction(printUser);
}

void viewCustomerList(Lists<Customer>& myCustomerList)
{
	myCustomerList.printingFunction(printCustomer);
}

void viewInventoryList(Lists<Inventory>& myInventoryList)
{
	myInventoryList.printingFunction(printInventory);
}

void viewTransactionHistoryList(Lists<TransactionHistory>& myTransactionHistoryList)
{
	myTransactionHistoryList.printingFunction(printTransaction);
}

void makeAsale(Lists<Customer>& myCustomerList, Lists<Inventory>& myInventoryList, Lists<TransactionHistory>& myTransactionHistoryList)
{
	//Choose existing customer
				//create new customer
				//choose inventory

				//system("cls");

				//----- Create Sale -----
				//Trans
				//Customer Information:
				//Inventory Information:
				//User
				//1. Select Customer
				//2. Select Inventory
				//3. Comfirm 
				//0. Abort and Return Main Menu
				//


	
}