/*
CSCN7103021W-Negussie 


*/

#include <iostream>
#include "Customer.h"
#include "SaveLoad.h"
#include "Users.h"
#include "Inventory.h"
#include "Lists.h"
#include "Node.cpp"
#include "Lists.cpp"
#include "TransactionHistory.h"
#include "Validation.h"


using namespace std;


int main(void){

    initializeElementsUserArray();

    //---------------------------------------------------------------------
	//Testing Integration for Customer and Save/Load
    //---------------------------------------------------------------------
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
	printf("\nBEFORE LOAD:\n");
	EmptyCustomer.printCustomer(); //printing Customer prior to file load 
	EmptyCustomer.load(inputFile); //load object info from file into Customer object
	inputFile.close();
	printf("\nAFTER LOAD:\n");
	EmptyCustomer.printCustomer();
	//Expectations: Contents of John Doe object that was saved to Customer.txt file will
	//				be placed into Empty Customer object. Validated by contents printed out Empty Customer print call
	//RESULT: PASSED 
    
    //---------------------------------------------------------------------
    //Testing Integration for Users and Save/Load
    //---------------------------------------------------------------------
    //USR-SAV-001
    
    //Load input into variables
    char username[] = "Eazaz";
    char password[] = "Password1";
    char userID[] = "EazazJ1";

    //Create and open "Users.txt" file to save Users into
    outputFile.open("Users.txt");

    //Create a user of type Admin
    Admin Eazaz(username, password, userID);

    //Save the Admin object to the file "Users.txt"
    Eazaz.save(outputFile);
    outputFile.close();

    //Expectations: Users.txt file will be created, and in file User Eazaz
	//				and its contents will be present
    // RESULT: PASSED


    //USR-SAV-002

    //Open "Users.txt" file to load objects from
    inputFile.open("Users.txt");

    //Create empty object to load User object from "Users.txt" file into
    Admin EazazLoaded;

    printf("\nBEFORE LOAD:\n");
    EazazLoaded.displayUser();

    //Load the User object from file into empty User Object
    EazazLoaded.load(inputFile);

    inputFile.close();

    printf("\nAFTER LOAD:\n");
    EazazLoaded.displayUser();
    //Expectations: Contents of Eazaz object that was saved to Users.txt file will
	//				be placed into Empty Admin object. Validated by contents printed out 
    //Results: PASSED
    
    //---------------------------------------------------------------------
    //Testing Integration for Inventory and Save/Load
    //---------------------------------------------------------------------
    //INV-SVLD-001
    char myMake[MAX_LEN] = "Ford";
   	char myModel[MAX_LEN] = "Escape";
    char myVIN[MAX_LEN] = "ABC123";


    outputFile.open("Inventory.txt");  //ofstream with file name created
    Inventory myInventory(myMake, myModel, myVIN, SUV, 25999, 19999);
    myInventory.save(outputFile);
    outputFile.close();
    //Expectations: Inventory.txt file will be created, and in file Inventory object "myInventory"
    //				and its contents will be present
    //RESULT: PASSED
    

    //INV-SVLD-002
    inputFile.open("Inventory.txt");

    //Create empty object to load Inventory object from "Inventory.txt" file into
    Inventory emptyInventory; 

    printf("\nBEFORE LOAD:\n");
    emptyInventory.printInventory();

    //Load the User object from file into empty User Object
    emptyInventory.load(inputFile);

    inputFile.close();

    printf("\nAFTER LOAD:\n");
    emptyInventory.printInventory();
    //Expectations: Contents of myInventory object that was saved to Inventory.txt file will
    //				be placed into Empty Inventory object. Validated by contents printed out
    //Results: PASSED 

   //---------------------------------------------------------------------
   //Testing Integration for Customer and List
   //---------------------------------------------------------------------
   
    //CUS-LST-001
    Lists<Customer> myCustomerList;
    Customer* newCustomer = new Customer(firstName,lastName,30);
    myCustomerList.addToList(newCustomer);
    // PASSED with Bugs 4/13/2021 5:54pm ->RAISED ISSUE
    // PASSED 4/13/2021 

   //---------------------------------------------------------------------
   //Testing Integration for User and List
   //---------------------------------------------------------------------

    //USR-LST-001
   Lists<Users> myUserList;
   Users* newUser = new Admin(username, password, userID);
   myUserList.addToList(newUser);
   newUser->displayUser();
   //PASSED 
   
    //---------------------------------------------------------------------
   //Testing Integration for Inventory and List
   //---------------------------------------------------------------------
   
   //INV-LST-001
    Lists<Inventory> myInventoryList;
    Inventory* newInventory = new Inventory(myMake, myModel, myVIN, SUV, 25999, 19999);
    myInventoryList.addToList(newInventory);

    //PASSED 

     //---------------------------------------------------------------------
   //Testing Integration for Transaction History with Customer, User, Inventory
   //---------------------------------------------------------------------
   // CUS-TH-001 USR-TH-001 INV-TH-001
    TransactionHistory myTransactionHistory(firstName, newInventory, newCustomer, newUser);
    myTransactionHistory.printTransaction();
    //PASSED 

     //---------------------------------------------------------------------
   //Testing Integration for Transaction History with lists
   //---------------------------------------------------------------------
    //TH-LISTS-001
    Lists<TransactionHistory> myTransactionHistoryList;
    myTransactionHistoryList.addToList(new TransactionHistory(firstName, newInventory, newCustomer, newUser));
    myTransactionHistoryList.addToList(new TransactionHistory(lastName, newInventory, newCustomer, newUser));
    //PASSED

    //TH-SVLD-001
    outputFile.open("TransactionHistory.txt");
    myTransactionHistory.save(outputFile);
    outputFile.close(); 
    //PASSED 
    
    //TH-SVLD-002
    inputFile.open("TransactionHistory.txt");
    char emptyBlank [30] = "";
    TransactionHistory emptyTransactionHistory(emptyBlank, new Inventory, new Customer, new Users);
    emptyTransactionHistory.printTransaction();
    emptyTransactionHistory.load(inputFile);
    inputFile.close();
    emptyTransactionHistory.printTransaction();
    //PASSED 
    
    //---------------------------------------------------------------------
   //Testing Integration of LIST-SAV
   //---------------------------------------------------------------------

    //LIST-SAV-001 
    myCustomerList.addToList(new Customer(firstName, lastName, 45)); 
    
    myCustomerList.addToList(new Customer);
    myCustomerList.save("myCustomerList.txt");
    //PASSED

    //LIST-SAV-002
    Lists<Customer> emptyCustomer; 
    emptyCustomer.load("myCustomerList.txt");
    //PASSED 
   
    

  //---------------------------------------------------------------------
  //Testing integration of Lists and Customer 
  //---------------------------------------------------------------------

    //CUS-LST-002

    cout << "\nNumber before:" << myCustomerList.getNumOfItems() << endl;
    myCustomerList.removeFromList(1);
    cout << "Number after:" << myCustomerList.getNumOfItems() << endl;
    //PASSED

  //---------------------------------------------------------------------
  //Testing integration of Lists and Users 
  //---------------------------------------------------------------------

    //USR-LST-002

    cout << "\nNumber before:" << myUserList.getNumOfItems() << endl;
    //myUserList.removeFromList(1);                                                                      //check later
    cout << "Number after:" << myUserList.getNumOfItems() << endl;
    //PASSED


  //---------------------------------------------------------------------
  //Testing integration of Lists and Inventory 
  //---------------------------------------------------------------------

    //INV-LST-002

    cout << "\nNumber before:" << myInventoryList.getNumOfItems() << endl;
    myInventoryList.removeFromList(1);
    cout << "Number after:" << myInventoryList.getNumOfItems() << endl;
    //PASSED

  //---------------------------------------------------------------------
  //Testing integration of Lists and Transaction history 
  //---------------------------------------------------------------------

    //TH-LST-002

    cout << "\nNumber before:" << myTransactionHistoryList.getNumOfItems() << endl;
    myTransactionHistoryList.removeFromList(1);
    cout << "Number after:" << myTransactionHistoryList.getNumOfItems() << endl;
    //PASSED
  
  //---------------------------------------------------------------------
  //Testing integration of 2dArray and Save/Load
  //---------------------------------------------------------------------
    //VER-SAV-001

    

    cout << "Display Array:" << endl;
    displayArray();
    
    saveArray();
    //Passed

  //---------------------------------------------------------------------
  //Testing integration of 2dArray and Save/Load
  //---------------------------------------------------------------------
  //VER-SAV-001

    char me[] = "WOWIDK";
    Eazaz.changeUsername(me);

    cout << "Display Changed Array:" << endl;
    displayArray();

    loadArray();

    cout << "Display Loaded Array:" << endl;
    displayArray();
    //PASSED

  //---------------------------------------------------------------------
  //Testing integration of Validation
  //---------------------------------------------------------------------
  //VLD-MAIN-001
    
    string a = "Hel lo1";

    if (doesStringOnlyContain(a, NUMBER+LETTER+SPACE))
        cout << "String contains all number,letter and spaces." << endl;
    else
        cout << "String doesn't contain all number,letter and spaces." << endl;
    //PASSED

	return 0;
}