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

//Recursive : 
Node *insert(Node *node, int val)
{
    if (node == NULL)
        return newNode(val);

    if (val < node->data)
        node->left = insert(node->left, val);

    else if (val > node->data)
        node->right = insert(node->right, val);

    return node;
}

int main()
{

    return 0;
}