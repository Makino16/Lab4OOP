#include "PriorityStack.h"

void PriorityStack::Resize()
{
	if (size == capacity - 1)
	{
		PriorityStackItem** temp = new PriorityStackItem * [capacity];
		for (int i = 0; i < capacity; i++)
		{
			temp[i] = data[i];
		}
		capacity *= 2;
		data = new PriorityStackItem * [capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = temp[i];
		}
		delete[] temp;
	}
}

PriorityStack::PriorityStack()
{
	capacity = 10;
	size = 0;
	data = new PriorityStackItem * [capacity];
}
void PriorityStack::Push(double value, int priority)
{
	Resize();
	data[size++] = new PriorityStackItem(value, priority);
	for (int i = size - 1; i > 0; i--)
	{
		if (data[i] < data[i - 1])
		{
			std::swap(data[i], data[i - 1]);
		}
	}
}

PriorityStackItem PriorityStack::Pop()
{
	PriorityStackItem temp = *data[size - 1];
	size--;
	return temp;
}

PriorityStack& PriorityStack::PopPri(int priority)
{
	PriorityStack* stack = new PriorityStack();
	int count = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (data[i]->GetPriority() == priority)
		{
			stack->Push(data[i]->GetValue(), data[i]->GetPriority());
			count++;
			for (int j = i; i > 0; i--)
			{
				data[j] = data[j - 1];
			}
		}
	}
	size -= count;
	return *stack;
}

bool PriorityStack::ExistItem(double value, int priority)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i]->GetValue() == value && this->data[i]->GetPriority() == priority)
			return true;
	}
	return false;
}

PriorityStack& PriorityStack::StackCross(PriorityStack& stack)
{
	PriorityStack* stackret = new PriorityStack();
	for (int i = 0; i < this->size; i++)
	{
		if (stack.ExistItem(this->data[i]->GetValue(), this->data[i]->GetPriority()))
		{
			stackret->Push(this->data[i]->GetValue(), this->data[i]->GetPriority());
		}
	}
	return *stackret;
}

PriorityStack& PriorityStack::operator=(PriorityStack& other)
{
	if (&other == this) return *this;
	delete[] data;
	int size = other.size;

	for (int i = 0; i < size; i++)
	{
		this->Push(other.data[i]->GetValue(), other.data[i]->GetPriority());
	}

	return *this;
}

PriorityStack::PriorityStack(const PriorityStack& other)
{
	delete[] data;
	capacity = 10;
	data = new PriorityStackItem * [capacity];
	size = 0;
	for (int i = 0; i < other.size; i++)
	{
		this->Push(other.data[i]->GetValue(), other.data[i]->GetPriority());
	}
}

PriorityStack::~PriorityStack()
{
	delete[] this->data;
}

PriorityStack& operator+(PriorityStack& stack1, PriorityStack& stack2)
{
	int i = 0;
	PriorityStack* stack = new PriorityStack();
	while (i < stack1.size)
	{
		stack->Push(stack1.data[i]->GetValue(), stack1.data[i]->GetPriority());
		i++;
	}
	i = 0;
	while (i < stack2.size)
	{
		stack->Push(stack2.data[i]->GetValue(), stack2.data[i]->GetPriority());
		i++;
	}
	return *stack;
}

std::ostream& operator<<(std::ostream& out, const PriorityStack& st)
{
	for (int i = st.size - 1; i >= 0; i--)
		out << st.data[i]->GetValue() << " " << st.data[i]->GetPriority() << std::endl;
	return out;
}
