#pragma once

template <typename T>
class Node {
	T* nodeData;
	//Node* prevNode;
	Node* nextNode;
public:
	Node(T* nodeData);
	//Node* getPrevNode();
	Node* getNextNode();
};