/*
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time.

Date: 17/05/2020
Time: 15:20 to 16h35 + 20min of optimization
*/

#include <iostream>
#include <stdexcept>
#include "const.h"

template <typename T>
class Stack
{
	T* elements = nullptr;
	int currentIndex = 0;
	int freeSpace = 0;
	const int allocSize = 10000 / sizeof(T);

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
		return currentIndex;
	}
	
	void print() const
	{
		std::cout << std::endl << "Stack:" << std::endl;

		for (int i = 0; i < currentIndex; ++i)
			std::cout << elements[i] << std::endl;
	}

	void push_back(const T& value)
	{
		if (freeSpace)
		{
			elements[currentIndex] = value;
		}
		else
		{
			freeSpace = allocSize;
			T* temp = new T[currentIndex + allocSize];

			for (int i = 0; i < currentIndex; ++i)
			{
				temp[i] = std::move(elements[i]);
			}

			temp[currentIndex] = value;

			if (elements)
			{
				delete[] elements;
			}

			elements = temp;
			//delete temp;
		}

		++currentIndex;
		--freeSpace;
	}

	T&  pop()
	{
		T popedValue = elements[0];

		for (int i = 0; i < currentIndex; ++i)
			elements[i] = std::move(elements[i + 1]);

		--currentIndex;
		
		return popedValue;
	}

	T& max()
	{
		try
		{
			if (currentIndex == 0)
				throw - 1;

				T maxValue;
				maxValue = elements[0];

				for (int i = 1; i < currentIndex; ++i)
				{
					if (elements[i] > maxValue)
						maxValue = elements[i];
				}

				std::cout << std::endl << "Max Value:" << maxValue << std::endl; //brought here otherwise it would print garbage when exception is thrown

				return maxValue;
		}
		catch (const int err)
		{
			std::cout << "Empty Stack!" << std::endl;
		}
	}

	void clear()
	{
		if (elements)
		{
			delete[] elements;
		}
		currentIndex = 0;
	}
};

#ifdef _43_Stack
int main()
{
	Stack<int> stack;
	
	stack.max();

	stack.push_back(6);
	stack.push_back(4);
	stack.push_back(3);
	stack.push_back(5);
	stack.push_back(2);
	stack.push_back(1);

	stack.max();
	std::cout << "Size: " << stack.size() << std::endl;

	stack.print();

	stack.max();
	std::cout << "Poped Value: " << stack.pop() << std::endl;
	stack.max();
	std::cout << "Size: " << stack.size() << std::endl;

	stack.push_back(1);
	stack.print();
}
#endif