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

vector<int> inOrderIter(node *root)
{
    node *curr = root;
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
