#pragma once
#include <iostream>
#include <fstream>
#include "SaveLoad.h"
#include "Utility.h"
#include "Customer.h"
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#define FIRST_NAME_LEN 30
#define LAST_NAME_LEN 30
using namespace std;

class Customer :public SAVELOAD, Utility 
{
private:
	char firstName[FIRST_NAME_LEN];
	char lastName[LAST_NAME_LEN];
	int age;

public:
	Customer();
	Customer(char* firstName, char* lastName, int age); //
	//print
	void print(void) override;
	void save(ofstream& out) override;
	void load(ifstream& in) override;
	//save and load 
};







