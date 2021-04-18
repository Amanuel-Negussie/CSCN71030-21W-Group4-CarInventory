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
#include "time.h"

#define MIN_TRANSACTIONID 1000
#define MAX_TRANSACTIONID 9999

#define TH_FILE "TransactionHistory.txt"
#define CUS_FILE "Customer.txt"
#define USR_FILE "Users.txt"
#define INV_FILE "Inventory.txt"
//using namespace std; 

//void mainMenu(Users* activeUser, Lists<Users> myUserList);

void mainMenu(Users* activeUser, Lists<Users>& myUserList, Lists<Inventory>& myInventoryList, Lists<Customer>& myCustomerList, Lists<TransactionHistory>& myTransactionHistoryList);


void addUser(Lists<Users>& myUserList);

void removeUser(Lists<Users>& myUserList);

void viewUserList(Lists<Users>& myUserList);

void viewCustomerList(Lists<Customer>& myCustomerList);

void addInventory(Lists<Inventory>& myInventoryList);

void removeInventory(Lists<Inventory>& myInventoryList);

void viewInventoryList(Lists<Inventory>& myInventoryList);

void viewTransactionHistoryList(Lists<TransactionHistory>& myTransactionHistoryList);

void makeAsale(Lists<Customer>& myCustomerList, Lists<Inventory>& myInventoryList, Lists<TransactionHistory>& myTransactionHistoryList, Users& user);

int RandInt(int min, int max);