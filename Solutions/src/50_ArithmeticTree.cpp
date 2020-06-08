/*
50 - EASY

Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).

Date: 27/05/2020
Time: from 23:45 to 00:47
*/

#include <string>
#include "const.h"

struct Node
{
    std::string value;
    struct Node* left, * right;
};

Node* createNode(std::string value)
{
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int solveExpression(Node* head)
{
    if (head == NULL)
        return 0;
    
    if (head->left == NULL && head->right == NULL)
        return std::stoi(head->value);

    int left = solveExpression(head->left);
    int right = solveExpression(head->right);

    if (head->value == "+")
        return left + right;
    else if (head->value == "-")
        return left - right;
    else if (head->value == "*")
        return left * right;
    else if (head->value == "/")
        return left / right;
}

#ifdef _50_Arithmetic_Tree
int main()
{
    Node* head = createNode("*");
    head->left = createNode("+");
    head->right = createNode("+");
    head->right->right = createNode("5");
    head->right->left = createNode("4");
    head->left->right = createNode("2");
    head->left->left = createNode("3");

    std::cout << solveExpression(head);
}
#endif