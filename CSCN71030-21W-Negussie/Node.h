#pragma once

template <typename T>
class Node {
private:
	T* nodeData;
	Node* nextNode;
public:
	Node(T* nodeData);
	Node* getNextNode();
	void setNextNode(Node* node);
	T* getNodeData();
	void deleteNode();
	~Node();
};


