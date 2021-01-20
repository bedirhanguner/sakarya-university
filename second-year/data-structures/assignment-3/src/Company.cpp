#include "Company.hpp"

Company::Company()
{
	this->name = name;
	this->employeeCount = employeeCount;
}

void Company::SetName(string &name)
{
	this->name = name;
}

string Company::GetName()
{
	return name;
}

void Company::SetEmployeeCount(int &employeeCount)
{
	this->employeeCount= employeeCount;
}

int Company::GetEmployeeCount()
{
	return employeeCount;
}

Company::~Company() {}