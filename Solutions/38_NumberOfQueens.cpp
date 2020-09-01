/*
#38 - Hard

You have an N by N board. Write a function that, given N, returns the number of
possible arrangements of the board where N queens can be placed on the board without
threatening each other, i.e. no two queens share the same row, column, or diagonal.
*/

#include <vector>;

int NumberOfQueens(int& n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    if (n < 4)
    {
        return n - 1;
    }

	std::vector<std::vector<int>> board;
    
    board.resize(n);

    for (int i = 0; i < n; ++i)
    {
        board[i].resize(n);
    }

    int totalQueens = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            //What am I doind to my life?
        }
    }

	return 0;
}

#ifdef _38_NumberOfQueens
int main()
{
    int test1 = 2;
	NumberOfQueens(test1);
}
#endif