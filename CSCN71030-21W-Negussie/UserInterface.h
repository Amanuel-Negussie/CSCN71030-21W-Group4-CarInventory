#pragma once
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

//using namespace std; 

//void mainMenu(Users* activeUser, Lists<Users> myUserList);

void mainMenu(Users* activeUser, Lists<Users>& myUserList, Lists<Inventory>& myInventoryList, Lists<Customer>& myCustomerList, Lists<TransactionHistory>& myTransactionHistoryList);


void addUser(Lists<Users>& myUserList);

void removeUser(Lists<Users>& myUserList);

void viewUserList(Lists<Users>& myUserList);

void viewCustomerList(Lists<Customer>& myCustomerList);

void viewInventoryList(Lists<Inventory>& myInventoryList);

void viewTransactionHistoryList(Lists<TransactionHistory>& myTransactionHistoryList);

void makeAsale(Lists<Customer>& myCustomerList, Lists<Inventory>& myInventoryList, Lists<TransactionHistory>& myTransactionHistoryList);