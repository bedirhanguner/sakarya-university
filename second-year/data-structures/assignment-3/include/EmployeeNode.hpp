#ifndef EMPLOYEENODE_HPP
#define EMPLOYEENODE_HPP

#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

class EmployeeNode
{
private:
public:
	EmployeeNode(const int &, EmployeeNode *, EmployeeNode * , const string &, const string &, const int &);
	string company;
	string name;
	int value;

	int data;
	int height;
	int level;
	EmployeeNode *left;
	EmployeeNode *right;

	~EmployeeNode();
};
#endif