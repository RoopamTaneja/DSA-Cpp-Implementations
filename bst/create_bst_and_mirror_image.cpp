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

node *insertMirror(node *root, int val)
{
    if (root == NULL)
        return newNode(val);
    if (root->data > val)
        root->right = insertNode(root->right, val);
    else if (root->data < val)
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

    node *mirror = newNode(arr[0]);
    for (int i = 1; i < n; i++)
        insertMirror(mirror, arr[i]);

    vi preorder;
    preorder.clear();
    preorderTrav(root, preorder);
    cout << "Preorder traversal of tree: \n";
    printArray(preorder);
    preorder.clear();
    preorderTrav(mirror, preorder);
    cout << "Preorder traversal of mirror image: \n";
    printArray(preorder);
    return 0;
}
