#include "Node.h"

template <class T>
Node<T>::Node(T* data) {
	this->NodeData = data;
}

template <class T>
Node<T>* Node<T>::getPrevNode() {
	return prevNode;
}

template <class T>
Node<T>* Node<T>::getNextNode() {
	return nextNode;
}