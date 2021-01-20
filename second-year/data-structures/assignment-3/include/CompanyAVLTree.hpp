#ifndef COMPANYAVLTREE_HPP
#define COMPANYAVLTREE_HPP

#include "CompanyNode.hpp"
#include "Company.hpp"
#include "Employee.hpp"
#include "EmployeeAVLTree.hpp"

#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

class CompanyAVLTree
{
private:
	CompanyNode *root;

	CompanyNode *SearchAndAdd(CompanyNode *currentNode, Company *company,Employee *employee);
	CompanyNode *SwapWithLeftNode(CompanyNode *);
	CompanyNode *SwapWithRightNode(CompanyNode *);
	void PostOrder(CompanyNode *);
	void IsLevelChanged(CompanyNode *alt_Dugum, int seviye, int level);
	int Height(CompanyNode *);
	bool DeleteNode(CompanyNode *&);
	bool SearchFromRoot(CompanyNode *currentNode, int searchingNumber, string searchingCompany);

public:
	CompanyAVLTree();
	bool IsEmpty();
	void Add(Company *company, Employee *employee);

	void PostOrder();
	void IsLevelChanged();
	void Clear();
	int Height();
	bool Search(int searchingNumber, string searchingCompany);

	~CompanyAVLTree();
};
#endif