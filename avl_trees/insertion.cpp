#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int key;
	node *left;
	node *right;
	int height;
};

node *newNode(int key)
{
	node *newNode = new node;
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

int height(node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

node *rightRotate(node *y)
{
	node *x = y->left;
	node *T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

node *leftRotate(node *x)
{
	node *y = x->right;
	node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

// Get Balance factor of node N
int getBalance(node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// returns the new root
node *insert(node *node, int key)
{
	if (node == NULL)
		return (newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void preOrder(node *root)
{
	if (root != NULL)
	{
		cout << root->key << " " << root->height << "\n";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	/* The constructed AVL Tree would be
				30
			/ \
			20 40
			/ \ \
		10 25 50
	*/
	cout << "Preorder traversal of the constructed AVL tree is \n";
	preOrder(root);
	return 0;
}
