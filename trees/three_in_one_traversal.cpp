#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

struct node // node of binary tree
{
    int data;
    node *left, *right;
};

void traversal(vi &pre, vi &in, vi &post, node *root)
{
    stack<pair<node *, int>> st;
    st.push({root, 1});
    if (root == NULL)
        return;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }

        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }
        else
            post.push_back(it.first->data);
    }
}

int main()
{
    return 0;
}