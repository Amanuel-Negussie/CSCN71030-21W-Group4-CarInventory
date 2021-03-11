#pragma once
#include <string>
#include <fstream>
using namespace std;

void SAVE(void* addressOfObject, const int sizeOfClass,ofstream& in);
void LOAD(void* addressOfObject, const int sizeOfClass,ifstream& out);

class SAVELOAD {
public:
	virtual void save(ofstream& in) = 0;
	virtual void load(ifstream& out) = 0;
};

class SAVELOAD {
public:
	virtual void save(ofstream& in) = 0;
	virtual void load(ifstream& out) = 0;
};







