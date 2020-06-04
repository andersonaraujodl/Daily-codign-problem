/*
Given a 2D matrix of characters and a target word, write a function that returns whether the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]
and the target word 'FOAM', you should return true, since it's the leftmost column. Similarly, given the target word 'MASS', you should return true, since it's the last row.

Date: 03/06/2020
Time: 20h20 to 21:10 - 50min :( + 15min of fixes and improvement.
*/

#include "const.h"
#include <string>
#include <cstddef>

bool FindWord(int row, int col, char letterBoard[][7], std::string word)
{
    int wordSize = word.size();
    int correctChars = 1;

    //search by row
    for (int i = 1; i < wordSize; ++i)
    {
        if (word[i] != letterBoard[row][col + i])
            break;

        ++correctChars;
    }

    //search by col
    for (int i = 1; i < wordSize; ++i)
    {
        if (word[i] != letterBoard[row + i][col])
            break;

        ++correctChars;
    }

    if (correctChars == wordSize)
        return true;

    return false;
}

bool FindFirstLetter(int row, int col, char letterBoard[][7], std::string word)
{
    bool hasWord = false;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (word[0] == letterBoard[i][j])
            {
                hasWord = FindWord(i, j, letterBoard, word);

                if (hasWord)
                    return true;
            }
        }
    }

    return false;
}


int main()
{
    char letterBoard[7][7] =
    {
        {'F', 'A', 'C', 'I', 'D', 'L', 'A'},
        {'O', 'B', 'Q', 'P', 'A', 'R', 'E'},
        {'A', 'N', 'O', 'B', 'L', 'D', 'B'},
        {'M', 'A', 'S', 'S', 'R', 'O', 'R'},
        {'P', 'W', 'F', 'U', 'I', 'O', 'Z'},
        {'I', 'A', 'G', 'K', 'Y', 'R', 'B'},
        {'R', 'T', 'E', 'H', 'W', 'Q', 'I'},
    };

    std::string foam = "FOAM";
    std::string love = "LOVE";
    std::string pare = "PARE";
    std::string agky = "AGKY";
    std::string sleep = "SLEEP";
    std::string door = "DOOR";
    std::string mass = "MASS";
    std::string doora = "DOORA";

    if (FindFirstLetter(7, 7, letterBoard, foam))
        std::cout << foam << " was found on the board!" << std::endl;
    else
        std::cout << foam << " was not found on the board!" << std::endl;


    if (FindFirstLetter(7, 7, letterBoard, love))
        std::cout << love << " was found on the board!" << std::endl;
    else
        std::cout << love << " was not found on the board!" << std::endl;

    if (FindFirstLetter(7, 7, letterBoard, pare))
        std::cout << pare << " was found on the board!" << std::endl;
    else
        std::cout << pare << " was not found on the board!" << std::endl;

    if (FindFirstLetter(7, 7, letterBoard, agky))
        std::cout << agky << " was found on the board!" << std::endl;
    else
        std::cout << agky << " was not found on the board!" << std::endl;

    if (FindFirstLetter(7, 7, letterBoard, sleep))
        std::cout << sleep << " was found on the board!" << std::endl;
    else
        std::cout << sleep << " was not found on the board!" << std::endl;

    if (FindFirstLetter(7, 7, letterBoard, door))
        std::cout << door << " was found on the board!" << std::endl;
    else
        std::cout << door << " was not found on the board!" << std::endl;

    if (FindFirstLetter(7, 7, letterBoard, mass))
        std::cout << mass << " was found on the board!" << std::endl;
    else
        std::cout << mass << " was not found on the board!" << std::endl;

    if (FindFirstLetter(7, 7, letterBoard, doora))
        std::cout << doora << " was found on the board!" << std::endl;
    else
        std::cout << doora << " was not found on the board!" << std::endl;

}