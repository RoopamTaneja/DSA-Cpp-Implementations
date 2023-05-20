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
}

// Approach 1:

int findSucc(Node *root, int input)
{
    if (root == NULL)
        return -1;
    Node *x = root;
    int succ = -1;
    while (x != NULL)
    {
        if (x->data < input)
            x = x->right;
        else if (x->data > input)
        {
            succ = x->data; // it is a possible successor
            x = x->left;
        }
    }
    return succ;
}

int findPred(Node *root, int input)
{
    if (root == NULL)
        return -1;
    Node *x = root;
    int pred = -1;
    while (x != NULL)
    {
        if (x->data < input)
        {
            pred = x->data; // it is a possible predecessor
            x = x->right;
        }
        else if (x->data > input)
        {
            x = x->left;
        }
    }
    return pred;
}

// Approach 2:

int main()
{

    return 0;
}