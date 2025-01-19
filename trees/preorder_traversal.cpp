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

vector<int> preOrderIter(node *curr)
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
