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
	NumOfItems = 0;
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
	NumOfItems++;
}

template<class T>
void Lists<T>::removeFromList(int nthItem) {
	if (nthItem <= 0 || nthItem > NumOfItems) {
		return;
	}

	Node<T>* temp = head;
	if (nthItem == 1) {
		head = temp->getNextNode();
		temp->deleteNode();
	}
	else {
		for (int i = 1; i < nthItem-1; i++) {
			temp = temp->getNextNode();

			if (temp == NULL) {
				return;
			}
		}
		Node<T>* target = temp->getNextNode();
		temp->setNextNode(target->getNextNode());
		target->deleteNode();
	}

	if (head == NULL) {
		tail = NULL;
	}
	else if (NumOfItems == nthItem) {
		tail = temp;
	}

	NumOfItems--;
}

template <class T>
int Lists<T>::getNumOfItems() {
	return NumOfItems;
}

template <class T>
bool Lists<T>::isListEmpty() {
	return (head == NULL && tail == NULL);
}

template <class T>
void Lists<T>::deleteList() {
	delete this;
}

/*
template <class T>
void Lists<T>::save(void* func(T*),string file) {
	Node<T>* current = head;
	ofstream hi(file);
	while (current != NULL) {
		theObject.save(hi);

		current = current->getNextNode();
	}

	hi.close();
}
*/

template <class T>
T* Lists<T>::peekHead() {
	return head->getNodeData();
}

template <class T>
Node<T>* Lists<T>::getHeadOfList() {
	return head;
}

template <class T>
Lists<T>::~Lists() {
	if (head != tail)
	{
		delete head;
	}
	delete tail;
	delete lastVisited;
}






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



