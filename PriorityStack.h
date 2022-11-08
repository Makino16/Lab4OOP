#pragma once
#include "PriorityStackItem.h"
#include <cstdlib>
#include <algorithm>
#include <ostream>

class PriorityStack
{
private:
	PriorityStackItem** data;
	int size;
	int capacity;
	void Resize();
public:
	PriorityStack();
	void Push(double value, int priority);
	PriorityStackItem Pop();
	PriorityStack& PopPri(int priority);
	bool ExistItem(double value, int priority);
	friend PriorityStack& operator+(PriorityStack&, PriorityStack&);
	PriorityStack& StackCross(PriorityStack& stack);
	friend std::ostream& operator<< (std::ostream& out, const PriorityStack& st);
	PriorityStack& operator= (PriorityStack& other);
	PriorityStack(const PriorityStack& other);
	~PriorityStack();
};

