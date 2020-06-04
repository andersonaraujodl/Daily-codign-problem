/*
Given a 2D matrix of characters and a target word, write a function that returns whether the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]
and the target word 'FOAM', you should return true, since it's the leftmost column. Similarly, given the target word 'MASS', you should return true, since it's the last row.

Date: 03/06/2020
Time: 20h20 to 21:10 
*/

#include "const.h"
#include <string>
#include <cstddef>

bool FindWord(int row, int col, char letterBoard[][4], std::string word)
{
    int wordSize = word.size();
    int correctChars = 1;

    //search by row
    for (int i = 1; i < wordSize; ++i)
    {
        if (word[i] == letterBoard[row][col + i])
            ++correctChars;
    }

    //search by col
    for (int i = 1; i < wordSize; ++i)
    {
        if (word[i] == letterBoard[row + i][col])
            ++correctChars;
    }

    if (correctChars == wordSize)
        return true;

    return false;
}

void FindFirstLetter(int row, int col, char letterBoard[][4], std::string word)
{
    bool hasWord = false;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (word[0] == letterBoard[i][j])
            {
                hasWord = FindWord(i, j, letterBoard, word);
            }
        }
    }

    if (hasWord)
        std::cout << word << " was found on the board! " << std::endl;
    else
        std::cout << word << " was not found on the board! " << std::endl;
}

int main()
{
    char letterBoard[4][4] =
    {
        {'F', 'A', 'C', 'I'},
        {'O', 'B', 'Q', 'P'},
        {'A', 'N', 'O', 'B'},
        {'M', 'A', 'S', 'S'}
    };
    
    FindFirstLetter(4, 4, letterBoard, "TEST");
}