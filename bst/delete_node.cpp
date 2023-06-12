#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *deleteNode(Node *root, int key)
{
    Node *curr = root;
    if (curr)
        if (key < curr->data)
            curr->left = deleteNode(curr->left, key); // We recursively call the function until we find the target node
        else if (key > curr->data)
            curr->right = deleteNode(curr->right, key);
        else
        {
            if (!curr->left && !curr->right)
                return NULL; // No child condition
            if (!curr->left || !curr->right)
                return curr->left ? curr->left : curr->right;
            // One child condition -> replace the node with it's child

            // Two child condition:
            // we essentially need to replace the node to_be_del with its inorder pred or succ
            // so u can either find leftmost of right subtree or right most of left subtree
            Node *temp = curr->right;
            while (temp->left != NULL)
                temp = temp->left;
            curr->data = temp->data;
            curr->right = deleteNode(curr->right, temp->data);
        }
    return curr;
}

int main()
{

    return 0;
}