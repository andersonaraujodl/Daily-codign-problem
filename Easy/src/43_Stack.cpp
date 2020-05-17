/*
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time.

Date: 17/05/2020
Time: 15:20 to 
*/

#include <iostream>

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

	//For debug purpose: Overload oprator [] to return the Nth element of the stack
	T& operator[](int index) const
	{
		if (index > (currentIndex - 1) || index < 0)
		{
			std::cout << "Index out of Range" << std::endl;
		}
		return elements[index];
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
		}

		++currentIndex;
		--freeSpace;
	}

	void  pop()
	{

	}

	void max()
	{

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

int main()
{
	Stack<int> stack;

	stack.push_back(2);
	stack.push_back(-5);
	stack.push_back(10);

	std::cout << "size: " << stack.size() << std::endl;

	for (int i = 0; i < stack.size(); ++i)
		std::cout << stack[i] << std::endl;
}