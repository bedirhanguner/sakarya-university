#include "EmployeeAVLTree.hpp"

void EmployeeAVLTree::Add(string employeeCompanyName, string employeeName, int employeeYearsOfWork)
{
    root = SearchAndAdd(root, employeeCompanyName, employeeName, employeeYearsOfWork);
    IsLevelChanged();
}

EmployeeNode *EmployeeAVLTree::SearchAndAdd(EmployeeNode *currentNode, string employeeCompanyName, string employeeName, int employeeYearsOfWork)
{
    int newValue = 2020-employeeYearsOfWork;

    if (currentNode == NULL)
    {
        currentNode = new EmployeeNode(newValue, NULL, NULL, employeeCompanyName, employeeName, employeeYearsOfWork);
    }

    else if (newValue <= currentNode->data)
    {
        currentNode->left = SearchAndAdd(currentNode->left, employeeCompanyName, employeeName, employeeYearsOfWork);

        if (Height(currentNode->left) - Height(currentNode->right) == 2)
        {
            if (newValue < currentNode->left->data)
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

    else if (newValue > currentNode->data)
    {
        currentNode->right = SearchAndAdd(currentNode->right, employeeCompanyName, employeeName, employeeYearsOfWork);

        if (Height(currentNode->right) - Height(currentNode->left) == 2)
        {
            if (newValue > currentNode->right->data)
            {
                currentNode = SwapWithRightNode(currentNode);
            }

            else if (newValue < currentNode->right->data)
            {
                currentNode->right = SwapWithLeftNode(currentNode->right);
                currentNode = SwapWithRightNode(currentNode);
            }
        }
    }

    currentNode->height = Height(currentNode);

    return currentNode;
}

void EmployeeAVLTree::PostOrder()
{
    PostOrder(root);
}

void EmployeeAVLTree::PostOrder(EmployeeNode *currentNode)
{
    if (currentNode != NULL)
    {
        PostOrder(currentNode->left);
        PostOrder(currentNode->right);
        cout << currentNode->name << ", " << currentNode->value;
        cout << endl;
    }
}

EmployeeNode *EmployeeAVLTree::SwapWithLeftNode(EmployeeNode *currentNode)
{
    EmployeeNode *tmp = currentNode->left;
    currentNode->left = tmp->right;
    tmp->right = currentNode;

    currentNode->height = Height(currentNode);
    tmp->height = max(Height(tmp->left), currentNode->height) + 1;

    return tmp;
}

EmployeeNode *EmployeeAVLTree::SwapWithRightNode(EmployeeNode *currentNode)
{
    EmployeeNode *tmp = currentNode->right;
    currentNode->right = tmp->left;
    tmp->left = currentNode;

    currentNode->height = Height(currentNode);
    tmp->height = max(Height(tmp->right), currentNode->height) + 1;

    return tmp;
}

void EmployeeAVLTree::IsLevelChanged(EmployeeNode *node, int level, int newLevel)
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

int EmployeeAVLTree::Height(EmployeeNode *currentNode)
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

bool EmployeeAVLTree::DeleteNode(EmployeeNode *&currentNode)
{
    EmployeeNode *deletedNode = currentNode;

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
        EmployeeNode *parentNode = currentNode;

        while (deletedNode->right != NULL)
        {
            parentNode = deletedNode;
            deletedNode = deletedNode->right;
        }
        currentNode->data = deletedNode->data;

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

EmployeeAVLTree::EmployeeAVLTree()
{
    root = NULL;
}

bool EmployeeAVLTree::IsEmpty()
{
    return root == NULL;
}

void EmployeeAVLTree::IsLevelChanged()
{
    int h = Height();

    for (int yeniSeviye = 0; yeniSeviye <= h; yeniSeviye++)
    {
        IsLevelChanged(root, yeniSeviye, yeniSeviye);
    }
}

void EmployeeAVLTree::Clear()
{
    while (!IsEmpty())
        DeleteNode(root);
}

int EmployeeAVLTree::Height()
{
    return Height(root);
}

EmployeeAVLTree::~EmployeeAVLTree()
{
    Clear();
}