// we are essentially storing first element of each level in level order traversal as part of left view

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;

void printArray(vi &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

struct node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *insertNode(node *root, int val)
{
    if (root == NULL)
        return newNode(val);
    if (root->data < val)
        root->right = insertNode(root->right, val);
    else if (root->data > val)
        root->left = insertNode(root->left, val);
    return root;
}

void preorderTrav(node *root, vi &preorder)
{
    if (root == NULL)
        return;
    preorder.emplace_back(root->data);
    preorderTrav(root->left, preorder);
    preorderTrav(root->right, preorder);
}

void levelOrderTrav(node *root, vi &leftView)
{
    queue<pair<node *, int>> q;
    leftView.emplace_back(root->data);
    q.push({root, 0});
    int prev = 0;
    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        node *top = p.first;
        if (prev != p.second)
        {
            leftView.emplace_back(top->data);
            prev = p.second;
        }
        q.pop();
        if (top->left != NULL)
            q.push({top->left, p.second + 1});
        if (top->right != NULL)
            q.push({top->right, p.second + 1});
    }
}

int main()
{
    int n, val;
    cout << "Enter no of elements : ";
    cin >> n;
    cout << "Enter array elements : \n";
    vi arr;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.emplace_back(val);
    }
    node *root = newNode(arr[0]);
    for (int i = 1; i < n; i++)
        insertNode(root, arr[i]);

    vi leftView;
    levelOrderTrav(root, leftView);
    cout << "Left view of BST:\n";
    printArray(leftView);
    return 0;
}
