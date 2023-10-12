#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

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

node *createBST(int start, int end, vi &sorted_arr)
{ // create balanced BST from SORTED array
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    node *treeNode = newNode(sorted_arr[mid]);
    treeNode->left = createBST(start, mid - 1, sorted_arr);
    treeNode->right = createBST(mid + 1, end, sorted_arr);
    return treeNode;
}

int main()
{

    return 0;
}