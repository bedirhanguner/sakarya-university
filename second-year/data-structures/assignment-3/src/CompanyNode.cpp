#include "CompanyNode.hpp"

CompanyNode::CompanyNode(CompanyNode *left, CompanyNode *right, const string &name, const int &value, EmployeeAVLTree *employeeAVLTree)
{
	this->name = name;
	this->value = value;

	employeeAVLTree = new EmployeeAVLTree();

	this->left = left;
	this->right = right;
	this->height = 0;

	this->level = -1;
}

CompanyNode::~CompanyNode() {}
