#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

struct TreeNode // node of binary tree
{
    int val;
    TreeNode *left, *right;
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == NULL) // empty tree
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        vi level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);

            level.push_back(temp->val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}