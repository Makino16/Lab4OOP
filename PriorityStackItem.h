#pragma once
class PriorityStackItem
{
	double value;
	int priority;
public:
	PriorityStackItem();
	PriorityStackItem(double value, int priority);
	friend bool operator<(const PriorityStackItem& a, const PriorityStackItem& b);
	double GetValue();
	int GetPriority();

};

