#include "Iterator.hpp"

	Iterator::Iterator() 
	{
		
	}

	Node* Iterator::EndNode(Node *Node, int size) 
	{
		int index = 1;
		
		while (true) 
		{
			Node = Node->next;
			index++;
			
			if (index == size)
			{
				return Node;
			}
		}
		return NULL;
	}
