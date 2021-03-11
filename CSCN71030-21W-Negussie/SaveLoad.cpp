#include "SaveLoad.h"



void SAVE(void* addressOfObject, const int sizeOfClass, ofstream& out)
{
	out.write(reinterpret_cast<char*>(addressOfObject), sizeOfClass); //write 
}

void LOAD(void* addressOfObject, const int sizeOfClass, ifstream& in) {
	in.read(reinterpret_cast<char*>(addressOfObject), sizeOfClass);
}