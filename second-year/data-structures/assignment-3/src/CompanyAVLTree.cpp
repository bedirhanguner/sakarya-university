#include "CompanyAVLTree.hpp"

void CompanyAVLTree::Add(Company *company, Employee *employee)
{

	root = SearchAndAdd(root, company, employee);
	
	IsLevelChanged();
}

CompanyNode *CompanyAVLTree::SearchAndAdd(CompanyNode *currentNode, Company *company, Employee *employee)
{
	
	int newValue = company->GetEmployeeCount();

	// if (Search(company->GetEmployeeCount(), company->GetName()) == true)
	// {
	// 	int oneMore = company->GetEmployeeCount() + 1;
	// 	company->SetEmployeeCount(oneMore);
	// }

	// else
	// {
	EmployeeAVLTree *employeeAVLTree = new EmployeeAVLTree();
	if (employee->getCompanyName() == company->GetName())
	{
		employeeAVLTree->Add(employee->getCompanyName(), employee->getNameSurname(), employee->getYearsOfWork());
		
	}
	if (currentNode == NULL)
	{
		currentNode = new CompanyNode(NULL, NULL, company->GetName(), newValue, employeeAVLTree);
	}

	else if (newValue <= currentNode->value)
	{
		currentNode->left = SearchAndAdd(currentNode->left, company, employee);

		if (Height(currentNode->left) - Height(currentNode->right) == 2)
		{
			if (newValue < currentNode->left->value)
			{
				currentNode = SwapWithLeftNode(currentNode);
			}

			else
			{
				currentNode->left = SwapWithRightNode(currentNode->left);
				currentNode = SwapWithLeftNode(currentNode);
			}
		}
	}

	else if (newValue > currentNode->value)
	{
		currentNode->right = SearchAndAdd(currentNode->right, company, employee);

		if (Height(currentNode->right) - Height(currentNode->left) == 2)
		{
			if (newValue > currentNode->right->value)
			{
				currentNode = SwapWithRightNode(currentNode);
			}

			else if (newValue < currentNode->right->value)
			{
				currentNode->right = SwapWithLeftNode(currentNode->right);
				currentNode = SwapWithRightNode(currentNode);
			}
		}
	}
	//}
	currentNode->height = Height(currentNode);

	return currentNode;
}

void CompanyAVLTree::PostOrder()
{
	PostOrder(root);
}

void CompanyAVLTree::PostOrder(CompanyNode *currentNode)
{
	if (currentNode != NULL)
	{
		currentNode->employeeAVLTree->PostOrder();
		PostOrder(currentNode->left);
		PostOrder(currentNode->right);
		cout << currentNode->name << ", " << currentNode->value;
		cout << endl;
	}
}
bool CompanyAVLTree::SearchFromRoot(CompanyNode *currentNode, int searchingNumber, string searchingCompany)
{
	if (currentNode == NULL)
	{
		return false;
	}
	else if (searchingCompany != currentNode->name && searchingNumber <= currentNode->value)
	{
		return SearchFromRoot(currentNode->left, searchingNumber, searchingCompany);
	}

	else if (searchingCompany != currentNode->name && searchingNumber > currentNode->value)
	{
		return SearchFromRoot(currentNode->right, searchingNumber, searchingCompany);
	}

	if (searchingCompany == currentNode->name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CompanyAVLTree::Search(int searchingNumber, string searchingCompany)
{
	return SearchFromRoot(root, searchingNumber, searchingCompany);
}

CompanyNode *CompanyAVLTree::SwapWithLeftNode(CompanyNode *currentNode)
{
	CompanyNode *tmp = currentNode->left;
	currentNode->left = tmp->right;
	tmp->right = currentNode;

	currentNode->height = Height(currentNode);
	tmp->height = max(Height(tmp->left), currentNode->height) + 1;

	return tmp;
}

CompanyNode *CompanyAVLTree::SwapWithRightNode(CompanyNode *currentNode)
{
	CompanyNode *tmp = currentNode->right;
	currentNode->right = tmp->left;
	tmp->left = currentNode;

	currentNode->height = Height(currentNode);
	tmp->height = max(Height(tmp->right), currentNode->height) + 1;

	return tmp;
}

void CompanyAVLTree::IsLevelChanged(CompanyNode *node, int level, int newLevel)
{
	if (node == NULL)
	{
		return;
	}

	if (level == 0)
	{
		int oldLevel = node->level;

		node->level = newLevel;
	}

	else
	{
		IsLevelChanged(node->left, level - 1, newLevel);
		IsLevelChanged(node->right, level - 1, newLevel);
	}
}

int CompanyAVLTree::Height(CompanyNode *currentNode)
{
	if (currentNode == NULL)
	{
		return -1;
	}

	if ((Height(currentNode->left) > Height(currentNode->right)))
	{
		return 1 + Height(currentNode->left);
	}

	else
	{
		return 1 + Height(currentNode->right);
	}
}

bool CompanyAVLTree::DeleteNode(CompanyNode *&currentNode)
{
	CompanyNode *deletedNode = currentNode;

	if (currentNode->right == NULL)
	{
		currentNode = currentNode->left;
	}

	else if (currentNode->left == NULL)
	{
		currentNode = currentNode->right;
	}

	else
	{
		deletedNode = currentNode->left;
		CompanyNode *parentNode = currentNode;

		while (deletedNode->right != NULL)
		{
			parentNode = deletedNode;
			deletedNode = deletedNode->right;
		}
		currentNode->value = deletedNode->value;

		if (parentNode == currentNode)
		{
			currentNode->left = deletedNode->left;
		}

		else
		{
			parentNode->right = deletedNode->left;
		}
	}

	delete deletedNode;
	return true;
}

CompanyAVLTree::CompanyAVLTree()
{
	root = NULL;
}

bool CompanyAVLTree::IsEmpty()
{
	return root == NULL;
}

void CompanyAVLTree::IsLevelChanged()
{
	int h = Height();

	for (int yeniSeviye = 0; yeniSeviye <= h; yeniSeviye++)
	{
		IsLevelChanged(root, yeniSeviye, yeniSeviye);
	}
}

void CompanyAVLTree::Clear()
{
	while (!IsEmpty())
		DeleteNode(root);
}

int CompanyAVLTree::Height()
{
	return Height(root);
}

CompanyAVLTree::~CompanyAVLTree()
{
	Clear();
}