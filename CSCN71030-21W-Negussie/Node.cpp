#include "Node.h"
#include <stdlib.h>

template<class T>
Node<T>::Node(T* nodeData) {
	this->nodeData = nodeData;
	nextNode = NULL;
}


template<typename T>
Node<T>* Node<T>::getNextNode() {
	return nextNode;
}

template<typename T>
void Node<T>::setNextNode(Node* node) {
	nextNode = node;
}

template<typename T>
T* Node<T>::getNodeData() {
	return nodeData;
}

template<typename T>
void Node<T>::deleteNode() {
	delete this;
}

template<typename T>
Node<T>::~Node() {
	this->nextNode = NULL;
	delete this->nodeData;
}
