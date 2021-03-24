#include "Node.h"
#include <stdlib.h>

template<class T>
Node<T>::Node(T* nodeData) {
	this->nodeData = nodeData;
	//prevNode = NULL;
	nextNode = NULL;
}

/*
template<class T>
Node<T>* Node<T>::getPrevNode() {
	return prevNode;
}
*/

template<class T>
Node<T>* Node<T>::getNextNode() {
	return nextNode;
}