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

using namespace std; 

void mainMenu(Users* activeUser, Lists<Users> myUserList);