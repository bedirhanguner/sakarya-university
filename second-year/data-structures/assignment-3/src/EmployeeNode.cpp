#include "EmployeeNode.hpp"

EmployeeNode::EmployeeNode(const int &data, EmployeeNode *left, EmployeeNode *right,const string &company, const string &name,  const int &value)
{
	this->company=company;
	this->name = name;
	this->value = value;

	this->data = data;
	this->left = left;
	this->right = right;
	this->height = 0;

	this->level = -1;
}

EmployeeNode::~EmployeeNode() {}
