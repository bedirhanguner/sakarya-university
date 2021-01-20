#include "CircularDoublyLinkedList.hpp"

Iterator CircularDoublyLinkedList::IterateFromPrevIndex(int index) const
{
    if (!(index < 0 || index > Count()))
    {
        int i = 0;
        Iterator itr(head);
        while (!itr.IsEndNode() && index != i++)
        {
            itr.StepNext();
        }
        return itr;
    }
    return NULL;
}

Iterator CircularDoublyLinkedList::IterateFromFirstNode() const
{
    if (!IsEmpty())
    {
        return Iterator(head->next);
    }
    return NULL;
}

CircularDoublyLinkedList::CircularDoublyLinkedList()
{
    head = new Node();
    size = 0;
}

bool CircularDoublyLinkedList::IsEmpty() const
{
    return head->next == NULL;
}

int CircularDoublyLinkedList::Count() const
{
    return size;
}

const int &CircularDoublyLinkedList::First() const
{
    return head->next->data;
}

const int &CircularDoublyLinkedList::Last() const
{
    return head->next->prev->data;
}

void CircularDoublyLinkedList::Add(const int &obj)
{
    Insert(Count(), obj);
}

void CircularDoublyLinkedList::Insert(int index, const int &obj)
{
    Iterator itr;
    itr = IterateFromPrevIndex(index);
    Node *newNext = itr.current->next;
    itr.current->next = new Node(obj, newNext, itr.current);
    if (newNext != NULL)
    {
        newNext->prev = itr.current->next;
        if (index == 0)
        {
            Node *last = newNext->prev;
            head->next->prev = last;
            last->next = head->next;
        }
    }
    if (size == 0)
    {
        head->next->next = head->next;
        head->next->prev = head->next;
    }
    size++;
}

void CircularDoublyLinkedList::Remove(const int &obj)
{
    int index = IndexOf(obj);
    RemoveAt(index);
}

void CircularDoublyLinkedList::RemoveAt(int index)
{
    Iterator itr;
    itr = IterateFromPrevIndex(index);
    if (itr.current->next != NULL)
    {
        Node *oldNode = itr.current->next;
        itr.current->next = itr.current->next->next;
        oldNode->next->prev = oldNode->prev;
        delete oldNode;
        if (index == 0)
        {
            head->next->prev->next = head->next;
        }
        size--;
        if (size == 0)
        {
            itr.current->next = NULL;
        }
    }
}

int CircularDoublyLinkedList::IndexOf(const int &obj) const
{
    int index = 0;
    for (Iterator itr(head->next); index < size; itr.StepNext())
    {
        if (itr.GetCurrentData() == obj)
        {
            return index;
        }
        index++;
    }
    return -1;
}

int CircularDoublyLinkedList::Find(const int &obj)
{
    int index = 0;
    int value = 0;
    for (Iterator itr = IterateFromFirstNode(); index < Count(); itr.StepNext(), index++)
    {
        if (obj == (index + 1))
        {
            value = itr.GetCurrentData();
        }
    }
    return value;
}

void CircularDoublyLinkedList::AddListToArray(CircularDoublyLinkedList &list, Arrays &arrays)
{	
    Iterator itr = list.IterateFromFirstNode();
    int *array;
    array = new int[list.size];

    for (int index = 0; index < list.size; itr.StepNext(), index++)
    {
        array[index] = itr.GetCurrentData();
    }
    int middleValue = ((list.size + 1) / 2) - 1;
    int *newArray;
    newArray = new int[list.size];

    for (int i = middleValue; i >= 0; i--)
    {
        newArray[i] = array[middleValue - i];
    }

    for (int i = middleValue + 1; i < list.size; i++)
    {
        newArray[i] = array[i];
    }

    if (newArray[middleValue] <= arrays.minMiddleValue)
    {
        arrays.minMiddleValue = newArray[middleValue];
        arrays.minArraySize = list.size;
        arrays.CreateMinArray(newArray);
    }

    if(newArray[middleValue] >= arrays.maxMiddleValue)
    {
        arrays.maxMiddleValue = newArray[middleValue];
        arrays.maxArraySize = list.size;
        arrays.CreateMaxArray(newArray);
    }
    delete[] array;
    delete[] newArray;
}

void CircularDoublyLinkedList::AddArrayToList(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        Add(array[i]);
    }
    delete[] array;
}

void CircularDoublyLinkedList::Cross(CircularDoublyLinkedList &minList, CircularDoublyLinkedList &maxList)
{
    //cout << maxList << minList << endl;

    CircularDoublyLinkedList *tempArray = new CircularDoublyLinkedList();

    int i = 1;
    for (Iterator itr = minList.IterateFromPrevIndex(minList.size); i < minList.size + 1; itr.StepBack(), i++)
    {
        tempArray->Add(itr.GetCurrentData());
    }
    minList.Clear();

    i = 1;
    for (Iterator itr = maxList.IterateFromPrevIndex(maxList.size); i < maxList.size + 1; itr.StepBack(), i++)
    {
        minList.Add(itr.GetCurrentData());
    }
    maxList.Clear();

    i = 1;
    for (Iterator itr = tempArray->IterateFromFirstNode(); i < tempArray->size + 1; itr.StepNext(), i++)
    {
        maxList.Add(itr.GetCurrentData());
    }
    delete tempArray;

    //cout << maxList << minList << endl;
    int minListMiddleDigit = (minList.size + 1) / 2;
    int maxListMiddleDigit= (maxList.size + 1) / 2;

    //cout << maxListMiddleValue << " " << minListMiddleValue << endl;

    maxList.Insert(maxListMiddleDigit, minList.Find(minListMiddleDigit));
    minList.Insert(minListMiddleDigit, maxList.Find(maxListMiddleDigit));
	
    maxList.RemoveAt(maxListMiddleDigit - 1);
    minList.RemoveAt(minListMiddleDigit - 1);
	
	int maxListMiddleValue = maxList.Find(maxListMiddleDigit);
	int minListMiddleValue = minList.Find(minListMiddleDigit);
	
	cout<<"En Buyuk Liste Ortanca Dugum Adres: "<< &maxListMiddleValue<<endl;
	cout<<"En Buyuk Liste Degerler: "<<endl;
    cout << maxList<<endl;
	
	cout<<"En Kucuk Liste Ortanca Dugum Adres: "<<&minListMiddleValue <<endl;
	cout<<"En Kucuk Liste Degerler: "<<endl;
	cout << minList;
    // cout << maxListMiddleValue << " " << minListMiddleValue << endl;
}

ostream &operator<<(ostream &screen, CircularDoublyLinkedList &list)
{
    if (list.IsEmpty())
    {
        screen << "List is empty." << endl;
    }

    else
    {
        int index = 0;
        for (Iterator itr = list.IterateFromFirstNode(); index < list.size; itr.StepNext(), index++)
            screen << itr.GetCurrentData() << " ";
        screen << endl;
    }
    return screen;
}

void CircularDoublyLinkedList::Clear()
{
    while (!IsEmpty())
    {
        RemoveAt(0);
    }
}

CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
    Clear();
    delete head;
}