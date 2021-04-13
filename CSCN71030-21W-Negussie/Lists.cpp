#include "Lists.h"
#include "SaveLoad.h"
#include <stdlib.h>
#include <string>
#include "Customer.h"

using namespace std;


template <class T>
Lists<T>::Lists() {
	head = NULL;
	tail = NULL;
	lastVisited = NULL;
}

template<class T>
void Lists<T>::addToList(T* object)
{
	Node<T>* newNode = new Node<T>(object);
	if (this->isListEmpty()) {
		head = tail = newNode;
	}
	else {
		tail->setNextNode(newNode);
		tail = newNode;
	}
}

template <class T>
bool Lists<T>::isListEmpty() {
	return (head == NULL && tail == NULL);
}

template <class T>
void Lists<T>::deleteList() {
	delete this;
}


template <class T>
T* Lists<T>::peekHead() {
	return head->getNodeData();
}

//template <class T>
//Lists<T>::~Lists() {
//	delete head;
//	delete tail;
//	delete lastVisited;
//}






template<class T>
void Lists<T>::save(string file)
{
	Node<T>* current = head;
	ofstream fp(file);
	while (current)
	{
		SAVE(current->getNodeData(), sizeof(T), fp);
		current = current->getNextNode();
	}
	fp.close();
}

template<class T>
void Lists<T>::load(string file)
{
	ifstream fp(file);
	while (!fp.eof())
	{
		T* tempObj = new T;
		LOAD(tempObj, sizeof(T), fp);
		if (fp.eof()) {
			delete tempObj;
			break;
		}
		this->addToList(tempObj);
	}
	fp.close();
}
