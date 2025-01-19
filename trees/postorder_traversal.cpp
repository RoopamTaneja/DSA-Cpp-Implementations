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

vector<int> postOrderTwoStack(node *curr)
{
    vector<int> postOrder;
    if (curr == NULL)
        return postOrder;

    stack<node *> s1;
    stack<node *> s2;
    s1.push(curr);
    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left != NULL)
            s1.push(curr->left);
        if (curr->right != NULL)
            s1.push(curr->right);
    }
    while (!s2.empty())
    {
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }
    return postOrder;
}

vector<int> postOrderOneStack(node *cur)
{
    vector<int> postOrder;
    if (cur == NULL)
        return postOrder;

    stack<node *> st;
    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
                cur = temp;
        }
    }
    return postOrder;
}
