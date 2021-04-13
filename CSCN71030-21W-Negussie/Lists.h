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
	void addToList(T* object);		//Add an item to the end of a list
	void removeFromList(int nthItem);	//Remove an item from anywhere of a list
	bool isListEmpty();				//Check if a list is empty
	void deleteList();				//delete a list
	T* peekHead();					//Return data from head
	Node<T>* getHeadOfList();

	//Waiting to be implemented
	void insertToList(T* insertObject, T* targetObject);	//Insert an item to middle of a list

	~Lists();
	//File I/O
	void save(string File);
	void load(string file);
};






