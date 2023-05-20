#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Iterative :
Node *searchIter(Node *root, int val)
{
    Node *x = root;
    while (x != NULL && x->data != val)
    {
        if (x->data < val)
            x = x->right;
        else
            x = x->left;
    }
    return x;
}

// Recursive:
Node *searchRecur(Node *root, int val)
{
    Node *x = root;
    if (x == NULL || x->data == val)
        return x;
    if (x->data > val)
        return searchRecur(x->left, val);
    else
        return searchRecur(x->right, val);
}

int main()
{

    return 0;
}