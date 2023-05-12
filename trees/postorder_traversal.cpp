#include <bits/stdc++.h>

using namespace std;

struct node // node of binary tree
{
    int data;
    node *left, *right;
};

void postOrderRecursive(node *curr, vector<int> &postOrder)
{
    if (curr == NULL)
        return;

    postOrderRecursive(curr->left, postOrder);
    postOrderRecursive(curr->right, postOrder);
    postOrder.push_back(curr->data);
}

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

int main()
{

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> postOrder;
    postOrderRecursive(root, postOrder);

    cout << "The postOrder Traversal is : ";
    for (int i = 0; i < postOrder.size(); i++)
    {
        cout << postOrder[i] << " ";
    }
    return 0;
}
