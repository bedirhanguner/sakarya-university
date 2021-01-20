#ifndef NODE_HPP
#define NODE_HPP

class Node
{
	
	private:
		int deger;
		Node* soldaki;
		Node* sagdaki;
		
	public:
		Node(int);
		
		int getDeger();
		void setDeger(int);
		
		Node* getSoldaki();
		void setSoldaki(Node*);
		
		Node* getSagdaki();
		void setSagdaki(Node*);
		
		~Node();
};

#endif