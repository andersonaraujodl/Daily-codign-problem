#include <iostream>

using namespace std;

struct Node
{
    int content;
    struct Node *left, *right;
};

Node* createNode(int input)
{
    Node* temp = new Node;
    temp->content = input;
    temp->left = temp->right = NULL;
    return (temp);
}

bool univalCounter(struct Node* root, int &totalNodes)
{
    if (root == NULL)
           return true;

    bool left = univalCounter(root->left, totalNodes);
    bool right = univalCounter(root->right, totalNodes);

    if (left == false || right == false)
       return false;

    if (root->left && root->content != root->left->content)
        return false;

    if (root->right && root->content != root->right->content)
        return false;

    totalNodes++;
    return true;
}

int rootCount(Node *root)
{
    int univalNode = 0;

    univalCounter(root, univalNode);

    return univalNode;
}

int main()
{
    Node* root = createNode(0);
          root->left = createNode(1);
          root->right = createNode(0);
          root->right->right = createNode(0);
          root->right->left = createNode(1);
          root->right->left->right = createNode(1);
          root->right->left->left = createNode(1);

    cout << "A arvore binaria possui: " << rootCount(root)<< endl;
    return 0;
}
