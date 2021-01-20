#include "Iterator.hpp"

Iterator::Iterator()
{
    current = NULL;
}

Iterator::Iterator(Node *node)
{
    current = node;
}

bool Iterator::IsEndNode()
{
    return current == NULL;
}

void Iterator::StepNext()
{
    if (!IsEndNode())
    {
        current = current->next;
    }
}

void Iterator::StepBack()
{
    if (!IsEndNode())
    {
        current = current->prev;
    }
}

const int &Iterator::GetCurrentData() const
{
    return current->data;
}
