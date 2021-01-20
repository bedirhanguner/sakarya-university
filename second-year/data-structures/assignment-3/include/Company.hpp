#ifndef COMPANY_HPP
#define COMPANY_HPP

#include <iostream>
#include <string.h>

using namespace std;

class Company
{
private:
public:
	string name;
	int employeeCount;

	Company();

	void SetName(string & name);
	string GetName();

	void SetEmployeeCount(int& employeeCount);
	int GetEmployeeCount();

	~Company();
};
#endif