#pragma once
#include "Node.h"
#include "SaveLoad.h"
#include <string>
using namespace std;

template<class T>
class Lists
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* lastVisited;
public:

	Lists();
	void addToList(T* object);
	void save(string File);
	void load(string file);
	bool isListEmpty();
	T* peekHead();
};






