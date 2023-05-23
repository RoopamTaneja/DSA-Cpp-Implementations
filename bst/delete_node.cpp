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

Node *searchNode(Node *root, int val)
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

Node *deleteNode(Node *root, int key)
{
    if (root)
        if (key < root->data)
            root->left = deleteNode(root->left, key); // We recursively call the function until we find the target node
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left && !root->right)
                return NULL; // No child condition
            if (!root->left || !root->right)
                return root->left ? root->left : root->right; // One child contion -> replace the node with it's child
                                                              // Two child condition
            Node *temp = root->left;                          // (or) Node *temp = root->right;
            while (temp->right != NULL)
                temp = temp->right;                          //  while(temp->left != NULL) temp = temp->left;
            root->data = temp->data;                         //  root->data = temp->data;
            root->left = deleteNode(root->left, temp->data); //  root->right = deleteNode(root->right, temp);
        }
    return root;
}

int main()
{

    return 0;
}