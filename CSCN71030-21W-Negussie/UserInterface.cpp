#include "UserInterface.h"


using namespace std;

void mainMenu(Users* activeUser, Lists<Users>& myUserList, Lists<Inventory>& myInventoryList, Lists<Customer>& myCustomerList, Lists<TransactionHistory>& myTransactionHistoryList) {
	system("cls");
	srand(time(NULL));


	cout << "Welcome, " << activeUser->getUsername() << ", to Really Good Dealership Management System" << endl;
	cout << endl;

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



	bool isDone = false;
	
	userType myUserType = activeUser->getUserType();

	while (!isDone)
	{
	
		switch (myUserType)
		{
		case ADM:
			cout << "You have Admin level access." << endl;
			cout << endl;

			cout << "ADMIN FUNCTIONS:" << endl;
			cout << "---------------------" << endl;
			cout << "1. Add User" << endl;
			cout << "2. Remove User" << endl;
			cout << "3. View Users List" << endl;
			cout << "---------------------" << endl;
			cout << "4. Add Inventory" << endl;
			cout << "5. Remove Inventory" << endl;
			cout << "6. Make a Sale" << endl;
			cout << "7. View Inventory List" << endl;
			cout << "8. View Customer List" << endl;
			cout << "9. View Transaction History" << endl;
			cout << "0. Save and Exit." << endl;
			cout << endl;

			cout << "Please make a selection: " << endl;

			cin >> adminInput;

			int userTypeChoice;
			system("cls");

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
			

				addInventory(myInventoryList);



				break;

			case 5:		//Remove Inventory
				removeInventory(myInventoryList);

				break;

			case 6:		//Make a sale

				makeAsale(myCustomerList, myInventoryList, myTransactionHistoryList, *activeUser);

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

				myTransactionHistoryList.save(TH_FILE);
				myCustomerList.save(CUS_FILE);
				myInventoryList.save(INV_FILE);
				myUserList.save(USR_FILE);
				saveArray();


				isDone = true;

				break;

			default:
				cout << "Please choose a valid number" << endl;
				break;
			}

			//MNG DUTIES

			//ADM DUTIES

			break;

		case MNG:
			cout << "You have Manager level access." << endl;
			cout << endl;

			cout << "MANAGER FUNCTIONS:" << endl;
			cout << "---------------------" << endl;
			cout << "1. Add Inventory" << endl;
			cout << "2. Remove Inventory" << endl;
			cout << "---------------------" << endl;
			cout << "3. Make a Sale" << endl;
			cout << "4. View Inventory List" << endl;
			cout << "5. View Customer List" << endl;
			cout << "6. View Transaction History" << endl;
			cout << "0. Save and Exit." << endl;
			cout << endl;

			cout << "Please make a selection:";

			cin >> managerInput;

			switch (managerInput)
			{
			case 1:		//Add Inventory
				addInventory(myInventoryList);
				break;

			case 2:		//Remover Inventory
				removeInventory(myInventoryList);
				break;

			case 3:		//Make a sale
				makeAsale(myCustomerList, myInventoryList, myTransactionHistoryList, *activeUser);
				break;

			case 4:		//View Inventory List
				viewInventoryList(myInventoryList);
				break;

			case 5:		//View Customer List
				viewCustomerList(myCustomerList);
				break;

			case 6:		//View Transaction History
				viewTransactionHistoryList(myTransactionHistoryList);
				break;

			case 0:		//Save and Exit
				myTransactionHistoryList.save(TH_FILE);
				myCustomerList.save(CUS_FILE);
				myInventoryList.save(INV_FILE);
				myUserList.save(USR_FILE);
				saveArray();				

				isDone = true;

				break;

			default:

				break;
			}


			//MNG DUTIES

			break;

		case SAL:

			cout << "You have Sales Representative level access." << endl;
			cout << endl;

			cout << "1. Make a Sale" << endl;
			cout << "2. View Inventory List" << endl;
			cout << "3. View Customer List" << endl;
			cout << "4. View Transaction History" << endl;
			cout << "0. Save and Exit." << endl;
			cout << endl;

			cout << "Please make a selection: " << endl;

			cin >> salesrepInput;

			switch (salesrepInput)
			{
			case 1:		//Make a sale
				makeAsale(myCustomerList, myInventoryList, myTransactionHistoryList, *activeUser);
				break;

			case 2:		//View Inventory List
				viewInventoryList(myInventoryList);
				break;

			case 3:		//View Customer List
				viewCustomerList(myCustomerList);
				break;

			case 4:		//View Transaction History
				viewTransactionHistoryList(myTransactionHistoryList);
				break;

			case 0:		//Save and Exit

				isDone = true;

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

	cout << "Please choose the type of user you would like to add:\n1. Admin\n2. Manager\n3. Sales Rep\n0. Return to Main Menu." << endl;

	cin >> userTypeChoice;

	switch (userTypeChoice)
	{
	case 1:

		system("cls");
		cout << "Please enter the username for the Admin:" << endl;

		//displayArray();

		cin >> usernameChoice;

		cout << "Please enter the user ID for the Admin:" << endl;

		cin >> useridChoice;

		cout << "Please enter the password for the Admin:" << endl;

		cin >> passwordChoice;


		myUserList.addToList(new Admin(usernameChoice, passwordChoice, useridChoice));

		system("cls");
		cout << "\nUser succesfully Added." << endl;

		break;

	case 2:

		system("cls");
		cout << "Please enter the username for the Manager:" << endl;

		//displayArray();

		cin >> usernameChoice;

		cout << "Please enter the user ID for the Manager:" << endl;

		cin >> useridChoice;

		cout << "Please enter the password for the Manager:" << endl;

		cin >> passwordChoice;

		myUserList.addToList(new Manager(usernameChoice, passwordChoice, useridChoice));
		
		system("cls");
		cout << "\nUser succesfully Added." << endl;
		
		break;

	case 3:

		system("cls");
		cout << "Please enter the username for the Sales Rep:" << endl;

		//displayArray();

		cin >> usernameChoice;

		cout << "Please enter the user ID for the Sales Rep:" << endl;

		cin >> useridChoice;

		cout << "Please enter the password for the Sales Rep:" << endl;

		cin >> passwordChoice;

		myUserList.addToList(new SalesRep(usernameChoice, passwordChoice, useridChoice));

		system("cls");
		cout << "\nUser succesfully Added." << endl;

		break;

	case 0:

		system("cls");
		return;

	}
}

void removeUser(Lists<Users>& myUserList)
{
	int removeUserChoice;

	cout << "Please choose the User you would like to remove:" << endl;

	myUserList.printingFunction(printUser);

	cin >> removeUserChoice;

	myUserList.removeFromList(removeUserChoice);

	system("cls");
	cout << "\nUser removed succesfully." << endl;


}

void viewUserList(Lists<Users>& myUserList)
{
	cout << "List of Users" << endl;

	myUserList.printingFunction(printUser);
	cout << endl;
}

void viewCustomerList(Lists<Customer>& myCustomerList)
{
	myCustomerList.printingFunction(printCustomer);
	cout << endl;
}

void viewInventoryList(Lists<Inventory>& myInventoryList)
{
	myInventoryList.printingFunction(printInventory);
	cout << endl;
}

void viewTransactionHistoryList(Lists<TransactionHistory>& myTransactionHistoryList)
{
	myTransactionHistoryList.printingFunction(printTransaction);
	cout << endl;
}

void makeAsale(Lists<Customer>& myCustomerList, Lists<Inventory>& myInventoryList, Lists<TransactionHistory>& myTransactionHistoryList, Users& user)
{

	int transactionHistoryChoice;
	int THCustomerChoice;
	int THInventoryChoice;


	string inputFirstName, inputLastName; 
	char firstName[FIRST_NAME_LEN];
	char lastName[LAST_NAME_LEN];
	int age;
	bool isTrue = false;

	cout << "1. Select Existing Customer" << endl;
	cout << "2. Create a new Customer" << endl;
	cout << "0. Abort and Return Previous Menu" << endl;
	cin >> transactionHistoryChoice;
	Customer* cp = NULL;
	Inventory* ip = NULL;
	switch (transactionHistoryChoice)
	{
	case 1:
		isTrue = false;
		cout << "Choose one of the following customers:" << endl;
		myCustomerList.printingFunction(printCustomer);

		cin >> THCustomerChoice;

		cp = myCustomerList.getItemFromList(THCustomerChoice);

		cout << "Customer " << cp->getFirstName() << " has been chosen." << endl;
		while (!isTrue)
		{
			cout << "Select Vehicle from Inventory" << endl;
			myInventoryList.printingFunction(printInventory);
			cin >> THInventoryChoice;
			ip = myInventoryList.getItemFromList(THInventoryChoice);
			if (!ip)
			{
				cout << "Please enter a valid number from the inventory list." << endl;
			}
			else
				isTrue = true;
		}
		isTrue = false;
		ip->printInventory();
		cout << endl;
		myTransactionHistoryList.addToList(new TransactionHistory(RandInt(MIN_TRANSACTIONID, MAX_TRANSACTIONID), *ip, *cp, user));


		break;
	case 2:
		isTrue = false;
		while (!isTrue)
		{
			cout << "What is your customer's first name: ";
			cin >> inputFirstName;
			if (!stringToCharArray(inputFirstName, firstName, FIRST_NAME_LEN))
				cout << "Sorry that first name is too long please try again." << endl;
			else
				isTrue = true;
		}
		isTrue = false;
		while (!isTrue)
		{
			cout << "\nWhat is your customer's last name: ";
			cin >> inputLastName;
			if (!stringToCharArray(inputLastName, lastName, LAST_NAME_LEN))
				cout << "Sorry that last name is too long please try again." << endl;
			else
				isTrue = true;
		}
		isTrue = false;

		while (!isTrue)
		{
			cout << "\nWhat is your customer's age: ";
			cin >> age;
			if (!isAgeValid(age))
			{
				cout << "Sorry, customer does not meet age requirements. (Age must be between 18-110 years)" << endl;
			}
			else
				isTrue = true;
		}
		isTrue = false;
		//make customer 
		cp = new Customer(firstName, lastName, age);
		myCustomerList.addToList(cp);
		cout << "Successfully added " << cp->getFirstName() << " to our Customer List." << endl;
		//choose from Inventory 
		while (!isTrue)
		{
			cout << "Select Vehicle from Inventory" << endl;
			myInventoryList.printingFunction(printInventory);
			cin >> THInventoryChoice;
			ip = myInventoryList.getItemFromList(THInventoryChoice);
			if (!ip)
			{
				cout << "Please enter a valid number from the inventory list." << endl;
			}
			else
				isTrue = true;
		}
	
		cout <<cp->getFirstName()<< " has chosen Make:" << ip->getMake() << " and Model:" << ip->getModel() << endl;
		myTransactionHistoryList.addToList(new TransactionHistory(RandInt(MIN_TRANSACTIONID, MAX_TRANSACTIONID), *ip, *cp, user));
		myInventoryList.removeFromList(THInventoryChoice);



		


		break;
	default:

		break;

	}
}

void removeInventory(Lists<Inventory>& myInventoryList)
{
	cout << "Which Vehicle would you like to remove?" << endl;
	bool isTrue = false;
	int THInventoryChoice;
	while (!isTrue)
	{
		cout << "Select Vehicle from Inventory" << endl;
		myInventoryList.printingFunction(printInventory);
		cin >> THInventoryChoice;
		if (!myInventoryList.removeFromList(THInventoryChoice))
			cout << "Sorry but that Inventory is not listed in our Inventory list." << endl;
		else
			isTrue = true;
	}
}

void addInventory(Lists<Inventory>& myInventoryList)
{
	string inputMake, inputModel, inputVIN;
	char make[MAX_LEN];
	char model[MAX_LEN];
	char VIN[MAX_LEN];
	LABEL label;
	int inputLabel;
	int price;
	int cost;

	bool isTrue = false;
	while (!isTrue)
	{
		cout << "What is the make of the vehicle: ";
		cin >> inputMake;

		if (!stringToCharArray(inputMake, make, MAX_LEN) || (!doesStringContainOnlyAndOptional(inputMake, LETTER, LETTER + SPACE)))
		{
			cout << "\n Sorry the vehicle make name does not fit our requirements. Try again!" << endl;
		}
		else
			isTrue = true;
	}
	isTrue = false;
	while (!isTrue)
	{
		cout << "What is the model of the vehicle: ";
		cin >> inputModel;

		if (!stringToCharArray(inputModel, model, MAX_LEN) || (!doesStringContainAnyOf(inputModel, LETTER + SPACE + NUMBER)))
		{
			cout << "\n Sorry the vehicle model name does not fit our requirements. Try again!" << endl;
		}
		else
			isTrue = true;
	}
	isTrue = false;
	while (!isTrue)
	{
		cout << "What is the VIN of the vehicle: ";
		cin >> inputVIN;

		if (!stringToCharArray(inputVIN, VIN, MAX_LEN) || !doesStringContainOnly(inputVIN, NUMBER))
		{
			cout << "\n Sorry the vehicle VIN does not fit our requirements. It should have only numbers. Try again!" << endl;
		}
		else
			isTrue = true;
	}
	isTrue = false;

	while (!isTrue)
	{
		cout << "What is the type of vehicle?" << endl;
		cout << "1. Sedan\n2. SUV\n3. Truck\n4. Crossover\n5. RV" << endl;
		cin >> inputLabel;
		if (inputLabel >= Sedan && inputLabel <= RV)
		{
			label = (LABEL)inputLabel;
			isTrue = true;
		}
		else
		cout << "Choose a valid option." << endl;

		
	}
	isTrue = false;
	cout << "What is the price: ";
	cin >> price;
	cout << "\nWhat is the cost: ";
	cin >> cost;
	myInventoryList.addToList(new Inventory(make, model, VIN, label, price, cost));
	system("cls");
	cout << "THE INVENTORY BELOW HAS BEEN ADDED." << endl;
	myInventoryList.getTailOfList()->getNodeData()->printInventory();
}

int RandInt(int min, int max)
{
	return min + (rand() % (max - min + 1));
}