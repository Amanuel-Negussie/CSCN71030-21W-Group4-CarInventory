#pragma once
#include <stdlib.h>
#include "SaveLoad.h"


class Node {
private: 
	void* Object;
	class Node* next; 

public:
	Node(void* Object)
	{
		this->Object = Object;
		this->next = NULL;
	}
	void setNodeNextNode(Node* next)
	{
		this->next = next;
	}
	
	Node* getNodeNextNode(void)
	{
		return this->next;
	}

	void setNodeObject(void* Object)
	{
		this->Object = Object;
	}
};

class List{
private: 
	Node* head;

public: 
	List() //default initialize -Empty List
	{
		head = NULL;
	}
	
	void AddNode(Node* newNode)
	{
		newNode->setNodeNextNode(NULL);
		if (!head) //if list is empty 
		{
			head = newNode;
		}
		else
		{
			Node* currentNode = head;
			while (!currentNode->getNodeNextNode()) //if currentNode is NULL
			{
				currentNode = currentNode->getNodeNextNode();   //set current Node to next Node
			}
			currentNode->setNodeNextNode(newNode); //currentNode 
		}
	}


};
