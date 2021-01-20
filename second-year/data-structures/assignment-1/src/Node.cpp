#include "Node.hpp"
#include<iostream>

	Node::Node(int deger)
	{
		this->deger = deger;
		this->soldaki= NULL;
		this->sagdaki= NULL;	
	}

	int Node::getDeger()
	{
		return deger;
	}

	void Node::setDeger(int deger)
	{
		this->deger = deger;
	}

	Node* Node::getSoldaki()
	{
		return soldaki;
	}
	void Node::setSoldaki(Node* soldaki)
	{
		this->soldaki = soldaki;
	}

	Node* Node::getSagdaki()
	{
		return sagdaki;
	}
	void Node::setSagdaki(Node* sagdaki)
	{
		this->sagdaki = sagdaki;
	}

	Node::~Node()
	{
		delete this->soldaki;
		delete this->sagdaki;
	}