#include <File.hpp>
#include <Arrays.hpp>
#include <CircularDoublyLinkedList.hpp>

File::File()
{
}

void File::Read(string &filePath) const
{
	ifstream file(filePath);
	Arrays *arrays = new Arrays();
	string row = "";
	int listValue = 0;
	
	while (getline(file, row))
	{
		CircularDoublyLinkedList *list = new CircularDoublyLinkedList();
		stringstream seperate(row);
		while (seperate >> listValue)
		{
			list->Add(listValue);
			
		}
		list->AddListToArray(*list,*arrays);
			
		delete list;
	}

	CircularDoublyLinkedList *minList = new CircularDoublyLinkedList();
	minList->AddArrayToList(arrays->minArray,arrays->minArraySize);
	
	CircularDoublyLinkedList *maxList = new CircularDoublyLinkedList();
	maxList->AddArrayToList(arrays->maxArray,arrays->maxArraySize);
	
	maxList->Cross(*minList,*maxList);

	delete maxList;
	delete minList;
	delete arrays;
}

File::~File()
{
	
}