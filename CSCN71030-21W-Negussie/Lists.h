#pragma once
#include "Node.h"

template<class T>
class Lists
{
	Node<T>* head;
	Node<T>* tail;
	Node<T>* lastVisited;
public:
	Lists();
	void addToList(T object);
	bool isListEmpty();
};

