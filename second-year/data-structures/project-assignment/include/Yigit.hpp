#ifndef YIGIT_HPP
#define YIGIT_HPP

#include <iostream>
using namespace std;

class Yigit
{
	private:
		string* items;
		int head;
		int length;
		int capacity;
		bool IsFull();
		void Reserve(int);
		
	public:
		Yigit();
		bool IsEmpty() const;
		void Push(const string&);
		void Pop();
		const string& Top()const;
		void Clear();
		~Yigit();
};
#endif