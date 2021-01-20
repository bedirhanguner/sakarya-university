#ifndef COMPANYNODE_HPP
#define COMPANYNODE_HPP

#include <cmath>
#include <iostream>
#include <string.h>
#include "EmployeeAVLTree.hpp"

using namespace std;

class CompanyNode
{
private:
public:
	CompanyNode(CompanyNode *, CompanyNode *, const string &name, const int &value, EmployeeAVLTree *employeeAVLTree);
	string name;
	int value;
	EmployeeAVLTree *employeeAVLTree;

	int height;
	int level;
	CompanyNode *left;
	CompanyNode *right;

	~CompanyNode();
};
#endif