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

vi morris_inorder(node *root)
{
    vi inorder;
    node *curr = root; // to preserve original root
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data); // no left child => u r root
            curr = curr->right;            // push u and go to right
        }
        else
        {
            node *prev = curr->left; // thread named prev, entering left subtree
            while (prev->right != NULL && prev->right != curr)
            { // prev should be rightmost node of left subtree
                prev = prev->right;
            }
            if (prev->right == NULL) // u have reached rightmost node and no thread presently
            {
                prev->right = curr; // connect it to curr
                curr = curr->left;  // move curr to left
            }
            else // prev->right == curr => thread already exists
            {
                prev->right = NULL;            // remove thread
                inorder.push_back(curr->data); // left done , so push root
                curr = curr->right;            // go to right
            }
        }
    }

    return inorder;
}

vi morris_preorder(node *root)
{
    vi preorder;
    node *curr = root; // to preserve original root
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            preorder.push_back(curr->data); // no left child => u r root
            curr = curr->right;             // now go to right
        }
        else
        {
            node *prev = curr->left; // thread named prev, entering left subtree
            while (prev->right != NULL && prev->right != curr)
            { // prev should be rightmost node of left subtree
                prev = prev->right;
            }
            if (prev->right == NULL) // u have reached rightmost node and no thread presently
            {
                prev->right = curr;             // connect it to curr
                preorder.push_back(curr->data); // abhi root pe ho, push it
                curr = curr->left;              // root done now move left
            }
            else // prev->right == curr => thread already exists
            {
                prev->right = NULL; // remove thread
                curr = curr->right; // left done , so go to right
            }
        }
    }

    return preorder;
}

int main()
{
    return 0;
}