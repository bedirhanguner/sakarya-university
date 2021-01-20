#include "Yigit.hpp"

	bool Yigit::IsFull()
	{
		return length == capacity;
	}
	
	void Yigit:: Reserve(int capacity)
	{
		string* tmp = new string[capacity];
		
		for(int i=0;i<length;i++)
		{
			tmp[i]=items[i];
		}
		
		if(items != NULL)
		{
			delete[] items;
		}
		
		items = tmp;
		this->capacity = capacity;
	}

	Yigit::Yigit()
	{
		items = NULL;
		head = -1;
		length = 0;
		capacity = 0;
	
	}
	
	bool Yigit::IsEmpty() const
	{
		return head == -1;
	}
	
	void Yigit::Push(const string& obj)
	{
		if(IsFull())
		{
			Reserve(max(1,2*capacity));
		}
		
		head++;
		items[head]=obj;
		length++;
	}
	
	void Yigit::Pop()
	{
		if(IsEmpty())
		{
			return;
		}
		
		head--;
		length--;
	}
	
	const string& Yigit::Top() const
	{
		if(IsEmpty())
		{
			return NULL;
		}
		
		return items[head];
	}
	
	void Yigit::Clear()
	{
		head=-1;
		length=0;
	}
	
	Yigit::~Yigit()
	{
		if(items!=NULL)
		{
			delete[] items;
		}
		
		items=NULL;
	}