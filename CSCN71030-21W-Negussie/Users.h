#pragma once

#include "SaveLoad.h"
#include "Lists.h"
#include "Lists.cpp"
#include "Node.cpp"
#include <iostream>
#include <fstream>

using namespace std;


#define MAX_USERS 10
#define MAX_PARAMS 2

#define MAX_LEN 20



enum userType { ADM, MNG, SAL, UNSET };

class Users: public SAVELOAD
{
protected:

	char username[MAX_LEN];
	char password[MAX_LEN];
	char userid[MAX_LEN];
	enum userType type;

public:
	Users();

	void copy(Users& copyObject);

	void displayUser();	

	void changeUsername(char name[MAX_LEN]);	

	void changePassword(char password[MAX_LEN]);
	
	void changeUserId(char ID[MAX_LEN]);	

	char* getUsername();
	char* getPassword();
	char* getUserID();
	userType getUserType();

	string getUserTypeString();

	void addArray();

	void save(ofstream& out) override;

	void load(ifstream& in) override;

	


};



class Admin : public Users
{

public:
	Admin();
	
	Admin(char user[MAX_LEN], char pass[MAX_LEN], char id[MAX_LEN]);	

	void displayAdmin();
	


};

class Manager : public Users
{

public:
	Manager();	

	Manager(char user[MAX_LEN], char pass[MAX_LEN], char id[MAX_LEN]);

};



class SalesRep : public Users
{

public:
	SalesRep();
	
	SalesRep(char user[MAX_LEN], char pass[MAX_LEN], char id[MAX_LEN]);

};

Users* findUserInList(Lists<Users> currentList, char userName[MAX_LEN], char password[MAX_LEN]);

bool isUserSame(Users* current, char userName[MAX_LEN], char password[MAX_LEN]);

void initializeElementsUserArray();

void displayArray();;



bool verifyCredentials(char username[MAX_LEN], char password[MAX_LEN]);



void saveArray();
bool loadArray();

void printUser(void* user);


