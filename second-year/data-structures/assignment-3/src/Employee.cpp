#include "Employee.hpp"

Employee::Employee()
{
	this->companyName = companyName;
	this->nameSurname = nameSurname;
	this->yearsOfWork = yearsOfWork;
}

void Employee::setCompanyName(string &companyName)
{
	this->companyName = companyName;
}

string Employee::getCompanyName()
{
	return companyName;
}

void Employee::setNameSurname(string &nameSurname)
{
	this->nameSurname = nameSurname;
}

string Employee::getNameSurname()
{
	return nameSurname;
}

void Employee::setYearsOfWork(int &yearsOfWork)
{
	this->yearsOfWork = yearsOfWork;
}

int Employee::getYearsOfWork()
{
	return yearsOfWork;
}

Employee::~Employee() {}