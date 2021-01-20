#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <Node.hpp>

class Iterator
{
public:
	Node *current;
	Iterator();
	Iterator(Node *node);
	bool IsEndNode();
	void StepNext();
	void StepBack();
	const int &GetCurrentData() const;
};
#endif