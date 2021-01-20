#ifndef EMPLOYEEAVLTREE_HPP
#define EMPLOYEEAVLTREE_HPP

#include "EmployeeNode.hpp"
#include "Employee.hpp"

#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

class EmployeeAVLTree
{
private:
	EmployeeNode *root;

	EmployeeNode *SearchAndAdd(EmployeeNode *, string employeeCompanyName, string employeeName, int employeeYearsOfWork);
	EmployeeNode *SwapWithLeftNode(EmployeeNode *);
	EmployeeNode *SwapWithRightNode(EmployeeNode *);
	void PostOrder(EmployeeNode *);
	void IsLevelChanged(EmployeeNode *alt_Dugum, int seviye, int level);
	int Height(EmployeeNode *);
	bool DeleteNode(EmployeeNode *&);

public:
	EmployeeAVLTree();
	bool IsEmpty();
	//void Add(Employee *);
	void Add(string employeeCompanyName, string employeeName, int employeeYearsOfWork);

	void PostOrder();
	void IsLevelChanged();
	void Clear();
	int Height();

	~EmployeeAVLTree();
};
#endif