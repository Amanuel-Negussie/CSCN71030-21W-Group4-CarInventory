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
	int NumOfItems;

public:

	Lists();
	void addToList(T* object);		//Add an item to the end of a list
	bool removeFromList(int nthItem);	//Remove an item from anywhere of a list
	T* getItemFromList(int nthItem);
	T* getLastVistedNodeData();
	void setLastVistedToNext();
	void setLastVisitedToHead();
	void setLastVisitedToNULL();
	int getNumOfItems();
	void printingFunction(void(*printingFunction)(void*));
	bool isListEmpty();				//Check if a list is empty
	void deleteList();				//delete a list
	T* peekHead();					//Return data from head
	Node<T>* getHeadOfList();
	Node<T>* getTailOfList();

	//Waiting to be implemented
	void insertToList(T* insertObject, T* targetObject);	//Insert an item to middle of a list
	
	//T* viewCurrentObject(Node<T>* current); //AMANUEL
	// T* Lists<T>::findObject(bool(*compare)(T*,void*,void*); //AMAnUEL
	//T* traverseAndCompare(T* object); //

	//~Lists();
	//File I/O
	void save(string File);
	void load(string file);
};

