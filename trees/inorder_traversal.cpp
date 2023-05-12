#include <bits/stdc++.h>

using namespace std;

struct node // node of binary tree
{
    int data;
    node *left, *right;
};

void inOrderRecursive(node *curr, vector<int> &inOrder)
{
    if (curr == NULL)
        return;

    inOrderRecursive(curr->left, inOrder);
    inOrder.push_back(curr->data);
    inOrderRecursive(curr->right, inOrder);
}

vector<int> inOrderIter(node *curr)
{
    vector<int> inOrder;
    stack<node *> s;
    while (true)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if (s.empty()) // curr == NULL and s == empty ... break
                break;
            curr = s.top();
            inOrder.push_back(curr->data);
            s.pop();
            curr = curr->right;
        }
    }
    return inOrder;
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

    vector<int> inOrder;
    inOrderRecursive(root, inOrder);

    cout << "The inOrder Traversal is : ";
    for (int i = 0; i < inOrder.size(); i++)
    {
        cout << inOrder[i] << " ";
    }
    return 0;
}
