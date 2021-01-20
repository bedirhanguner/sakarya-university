#ifndef NODE_HPP
#define NODE_HPP

#include<iostream>
#include <string>

using namespace std;

class Node
{
public: 

	int data;
	Node *next;
	Node *prev;

	Node(const int& data = 0, Node *next = NULL, Node *prev = NULL);
};

#endif
