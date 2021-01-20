#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string.h>

using namespace std;

class Employee
{
private:
public:
	string companyName;
	string nameSurname;
	int yearsOfWork;

	Employee();

	void setCompanyName(string &);
	string getCompanyName();

	void setNameSurname(string &);
	string getNameSurname();
	
	void setYearsOfWork(int &);
	int getYearsOfWork();

	~Employee();
};
#endif