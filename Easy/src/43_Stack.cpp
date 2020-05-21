/*
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time.

Date: 17/05/2020
Time: 15:20 to 16h35 + 35min of optimization
*/

#include <stdexcept>
#include "const.h"

template <typename T>
class Stack
{
	T* elements = nullptr;
	int stackSize = 0;
	int freeSpace = 0;
	const int allocSize = 100 / sizeof(T); //for test purpose, this values must vary according to its application

public:
	Stack()
	{

	}

	~Stack()
	{
		clear();
	}


	int size()
	{
		return stackSize;
	}
	
	//for debug purpose only
	void print() const
	{
		std::cout << std::endl << "Stack:" << std::endl;

		for (int i = 0; i < stackSize; ++i)
		{
			std::cout << elements[i] << std::endl;
		}
	}

	void push(const T& value)
	{
		if (freeSpace)
		{
			elements[stackSize] = value;
		}
		else
		{
			freeSpace = allocSize;
			T* temp = new T[stackSize + allocSize];

			for (int i = 0; i < stackSize; ++i)
			{
				temp[i] = std::move(elements[i]);
			}

			temp[stackSize] = value;

			if (elements)
			{
				delete[] elements;
			}

			elements = temp;
		}

		++stackSize;
		--freeSpace;
	}

	T&  pop()
	{
		try
		{
			if (stackSize == 0)
			{
				throw - 1;
			}

			T popedValue = elements[--stackSize];

			if (stackSize % allocSize == 0)
			{
				freeSpace = 0;

				T* temp = new T[stackSize];

				for (int i = 0; i < stackSize; ++i)
				{
					temp[i] = std::move(elements[i]);
				}
			}
			else
			{
				++freeSpace;
			}

			return popedValue;
		}
		catch (const int err)
		{
			std::cout << "Can't Pop: Empty Stack!" << std::endl;
		}
	}

	T& max()
	{
		try
		{
			if (stackSize == 0)
			{
				throw - 1;
			}

			T maxValue;
			maxValue = elements[0];

			for (int i = 1; i < stackSize; ++i)
			{
				if (elements[i] > maxValue)
				{
					maxValue = elements[i];
				}
			}

			std::cout << std::endl << "Max Value:" << maxValue << std::endl; //put this here to avoid print garbage when exception is thrown

			return maxValue;
		}
		catch (const int err)
		{
			std::cout << "Can't find Max value: Empty Stack!" << std::endl;
		}
	}

	void clear()
	{
		if (elements)
		{
			delete[] elements;
		}
		stackSize = 0;
	}
};

#ifdef _43_Stack
int main()
{
	Stack<int> stack;

	stack.pop();
	stack.max();

	stack.push(6);
	stack.push(4);
	stack.push(3);
	stack.push(5);
	stack.push(2);
	stack.push(1);

	stack.max();
	std::cout << "Size: " << stack.size() << std::endl;

	stack.print();

	stack.max();
	std::cout << "Poped Value: " << stack.pop() << std::endl;

	stack.print();

	stack.max();
	std::cout << "Size: " << stack.size() << std::endl;

	stack.push(1);
	stack.print();
}
#endif