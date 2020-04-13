/*
You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.

Date: 13/04/2020
Time: 19h09 to 20h00
*/
#include <iostream>
#include <list>

class Log
{
	int size;
	int currentSize;
	std::list<int> orderIDs;

public:
	Log(int n)
	{
		size = n;
		currentSize = 0;
	}

	~Log()
	{
		Clear();
	}

	void RecordOrder(int orderId)
	{
		if (++currentSize > size)
		{
			orderIDs.pop_front();
			return;
		}

		orderIDs.push_back(orderId);
	}

	int GetLast(int i)
	{
		if (i <= 0 || i > (int)orderIDs.size())
			return -1;

		std::list<int>::iterator it = orderIDs.begin();

		std::advance(it, size - i);

		return *it;
	}

private:
	void Clear()
	{
		orderIDs.clear();
	}
};

int main()
{
	Log newLog(3);
	newLog.RecordOrder(123);
	newLog.RecordOrder(456);
	newLog.RecordOrder(789);

	std::cout << newLog.GetLast(2) << std::endl << newLog.GetLast(1) << std::endl << newLog.GetLast(3) << std::endl;
	
	return 0;
}