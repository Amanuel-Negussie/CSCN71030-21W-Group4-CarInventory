#include "Lists.h"
#include "SaveLoad.h"
#include <stdlib.h>
#include <string>
#include "Customer.h"
#include "Inventory.h"
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
bool Lists<T>::removeFromList(int nthItem) {
	if (nthItem <= 0 || nthItem > NumOfItems) {
		return false;
	}

	Node<T>* temp = head;
	if (nthItem == 1) {
		head = temp->getNextNode();
		temp->deleteNode();
	}
	else {
		for (int i = 1; i < nthItem - 1; i++) {
			temp = temp->getNextNode();

			if (temp == NULL) {
				return false;
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
	return true;
}

template<class T>
T* Lists<T>::getItemFromList(int nthItem) {
	if (nthItem <= 0 || nthItem > NumOfItems) {
		return NULL;
	}

	Node<T>* temp = head;

	for (int i = 1; i < nthItem; i++) {
		temp = temp->getNextNode();		
	}
	return temp->getNodeData();
}

template <class T>
T* Lists<T>::getLastVistedNodeData(){
	return lastVisited->getNodeData();
}

template <class T>
void Lists<T>::setLastVistedToNext(){
	lastVisited = lastVisited->getNextNode();
}

template <class T>
void Lists<T>::setLastVisitedToHead(){
	lastVisited = head;
}

template <class T>
void Lists<T>::setLastVisitedToNULL(){
	lastVisited = NULL;
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
Node<T>* Lists<T>::getTailOfList() {
	return tail;
}



//template <class T>
//T* Lists<T>::findObject(bool(*compare)(T*,void*,void*) ){
//	T* current;
//	Node<T>* currentNode = this->head;
//	while (currentNode)
//	{
//		current = currentNode->getNodeData();
//		if (compare(current))
//			return current;
//		currentNode = currentNode->getNextNode();
//	}
//	return NULL;
//}


template <class T>
void Lists<T>::printingFunction(void(*printingFunction)(void*)){
	int num = getNumOfItems() + 1;
	
	Node<T>* current = this->getHeadOfList();
	for (int i = 1; i < num; i++) {
		cout <<  i << ". ";
		printingFunction(current->getNodeData());
		current = current->getNextNode();
	}
	
}


//template <class T>
//Lists<T>::~Lists() {
//	if (head != tail)
//	{
//		delete head;
//	}
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

//template<class T>
// T* Lists<T>::traverseAndCompare(T* object)
//{
//	 Node<T>* current;
//	while (current)
//	{
//		if (memcmp(viewCurrentObject(current), object, sizeof(T)) == 0)
//			return T*;
//		current = current->getNextNode();
//	}
//	return NULL;
//}


//template<class T>
//T* Lists<T>::viewCurrentObject(Node<T>* current)
//{
//	return current->getNodeData;
//}






