#include <Arrays.hpp>

Arrays::Arrays()
{
    this->maxMiddleValue = 0;
    this->minMiddleValue = 100000;
}

void Arrays::CreateMaxArray(int tempArray[])
{
    maxArray = new int[maxArraySize];
    for (int i = 0; i < maxArraySize; i++)
    {
        maxArray[i] = tempArray[i];
    }
    delete[] tempArray;
}

void Arrays::CreateMinArray(int tempArray[])
{
    minArray = new int[minArraySize];
    for (int i = 0; i < minArraySize; i++)
    {
        minArray[i] = tempArray[i];
    }
    delete[] tempArray;
}

Arrays::~Arrays()
{
    delete[] minArray;
    delete[] maxArray;
}