#include "PriorityStackItem.h"

PriorityStackItem::PriorityStackItem()
{
	value = 0;
	priority = 0;
}

PriorityStackItem::PriorityStackItem(double value, int priority) : 
	value(value), priority(priority)
{
}

double PriorityStackItem::GetValue()
{
	return value;
}

int PriorityStackItem::GetPriority()
{
	return priority;
}

bool operator<(const PriorityStackItem& a, const PriorityStackItem& b)
{
	return a.priority < b.priority;
}
