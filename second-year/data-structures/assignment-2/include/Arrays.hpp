#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <iostream>
#include <string>

using namespace std;

class Arrays
{
public:
	int maxMiddleValue;
	int minMiddleValue;
	int *maxArray;
	int *minArray;
	int maxArraySize;
	int minArraySize;

	void CreateMaxArray(int tempArray[]);
	void CreateMinArray(int tempArray[]);
	
	Arrays();
	~Arrays();
};

#endif
