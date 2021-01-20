#ifndef CIRCULARDOUBLYLINKEDLIST_HPP
#define CIRCULARDOUBLYLINKEDLIST_HPP

#include <Iterator.hpp>
#include <string.h>
#include <Arrays.hpp>

using namespace std;

class CircularDoublyLinkedList
{
private:
	Node *head;
	int size;
	Iterator IterateFromPrevIndex(int index) const;
	Iterator IterateFromFirstNode() const;

public:
	CircularDoublyLinkedList();
	bool IsEmpty() const;
	int Count() const;
	const int &First() const;
	const int &Last() const;
	void Add(const int &obj);
	void Insert(int index, const int &obj);
	void Remove(const int &obj);
	void RemoveAt(int index);
	int IndexOf(const int &obj) const;
	int Find(const int &obj);
	friend ostream &operator<<(ostream &screen, CircularDoublyLinkedList &list);
	void AddListToArray(CircularDoublyLinkedList &list, Arrays &arrays);
	void AddArrayToList(int array[], int size);
	void Cross(CircularDoublyLinkedList &minList, CircularDoublyLinkedList &maxList);
	void PrintAllFromIndexReversed(int index);
	void PrintAllReversed();
	void Clear();
	~CircularDoublyLinkedList();
};
#endif