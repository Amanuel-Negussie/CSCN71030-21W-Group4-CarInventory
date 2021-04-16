#pragma once
#include <iostream>
#include <fstream>
#include "SaveLoad.h"
#include <string>
#include "Lists.h"
#define _CRT_SECURE_NO_WARNINGS
#define FIRST_NAME_LEN 30
#define LAST_NAME_LEN 30
using namespace std;

class Customer :public SAVELOAD
{
private:
	char firstName[FIRST_NAME_LEN];
	char lastName[LAST_NAME_LEN];
	int age;

public:
	Customer();
	Customer(char firstName[FIRST_NAME_LEN], char lastName[LAST_NAME_LEN], int age);
	Customer(const Customer& copyObject);
	~Customer();
	//copy

	void copy( Customer& copyObject);

	//getters and setters 
	char* getFirstName(void);
	char* getLastName(void);
	int getAge(void);

	void setFirstName(char firstName[FIRST_NAME_LEN]);
	void setLastName(char lastName[LAST_NAME_LEN]);
	void setAge(int age);
	//print
	void printCustomer(void);
	/*void printCustomerList(Lists<Customer> list);*/

	//save and load
	void save(ofstream& out) override;
	void load(ifstream& in) override;

	//save and load 
};


void printCustomerList(Lists<Customer>* list);
void printCustomer(void* customer);

