#include <bits/stdc++.h>

using namespace std;

struct node // node of binary tree
{
    int data;
    node *left, *right;
};

void preOrderRecursive(node *curr, vector<int> &preOrder)
{
    if (curr == NULL)
        return;

    preOrder.push_back(curr->data);
    preOrderRecursive(curr->left, preOrder);
    preOrderRecursive(curr->right, preOrder);
}

vector<int> preOrderTrav(node *curr)
{
    vector<int> preOrder;
    if (curr == NULL)
        return preOrder;

    stack<node *> s;
    s.push(curr);

    while (!s.empty())
    {
        node *topNode = s.top();
        preOrder.push_back(topNode->data);
        s.pop();
        if (topNode->right != NULL)
            s.push(topNode->right);
        if (topNode->left != NULL)
            s.push(topNode->left);
    }
    return preOrder;
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

    vector<int> preOrder;
    preOrderRecursive(root, preOrder);

    cout << "The preOrder Traversal is : ";
    for (int i = 0; i < preOrder.size(); i++)
    {
        cout << preOrder[i] << " ";
    }
    return 0;
}
