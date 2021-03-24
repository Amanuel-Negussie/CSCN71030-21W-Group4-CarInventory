#include "Lists.h"
#include <stdlib.h>

template <class T>
Lists<T>::Lists() {
	head = NULL;
	tail = NULL;
	lastVisited = NULL;
}

template <class T>
void Lists<T>::addToList(T object) {
	Node<T>* newNode = new Node<T>(object);
	if (isListEmpty()) {
		head = tail = newNode;
	}
	else {
		tail->nextNode = newNode;
		tail = newNode;
	}
}

template <class T>
bool Lists<T>::isListEmpty() {
	return (head == tail == NULL);
}