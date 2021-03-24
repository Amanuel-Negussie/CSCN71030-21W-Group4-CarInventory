#pragma once
#include <stdlib.h>

template<class T>
class Node {
	T* NodeData;
	Node* prevNode;
	Node* nextNode;
public:
	Node(T* data);
	Node* getPrevNode();
	Node* getNextNode();
};

