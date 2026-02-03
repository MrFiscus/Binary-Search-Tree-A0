#include "bst.h"
#include "customErrorClass.h"

static Node* findMin(Node* root);
static Node* deleteRec(Node* root, int data);

/* Create new node */
Node* newNode(int key)
{
 Node* node = new Node;
 node->data = key;
 node->left = NULL;
 node->right = NULL;
 return node;
}

/* Insert into BST */
void insert(Node** headref, int data)
{
 if (*headref == NULL)
 {
*headref = newNode(data);
    return;
 }

 Node* travptr = *headref;
 Node* parent = NULL;

 while (travptr != NULL)
 {
 if (travptr->data == data)
  {
        throw MyException("Duplicate value");
    }

 parent = travptr;

 if (data > travptr->data)
 {
 travptr = travptr->right;
 }
 else
 {
 travptr = travptr->left;
 }

 }

 if (data > parent->data)
parent->right = newNode(data);
 else
parent->left = newNode(data);
}

/* Search */
bool find(Node** headref, int data)
{
if (*headref == NULL)
 {
 cout << "Tree is empty\n";
 return false;
 }

Node* travptr = *headref;

while (travptr != NULL)
{
 if (travptr->data == data)
 {
    return true;
 }

 if (data > travptr->data)
 {
travptr = travptr->right;
 }
 else
 {
travptr = travptr->left;
 }
}

    return false;

}

static Node* findMin(Node* root)
{
 while (root != NULL)
 {
 if (root->left == NULL)
 {
break;
 }

 root = root->left;
 }

    return root;

}

/* Delete */

static Node* deleteRec(Node* root, int data)
{
 if (root == NULL)
 {
    throw MyException("Value not found");
 }

 if (data < root->data)
 {
 root->left = deleteRec(root->left, data);
 }
 else
 {
 if (data > root->data)
 {
root->right = deleteRec(root->right, data);
 }
 else
 {
if (root->left == NULL && root->right == NULL)
{
 delete root;
    return NULL;
}

if (root->left == NULL)
{
 Node* temp = root->right;
 delete root;
    return temp;
}

if (root->right == NULL)
{
 Node* temp = root->left;
 delete root;
    return temp;
}

Node* temp = findMin(root->right);
root->data = temp->data;
root->right = deleteRec(root->right, temp->data);
}
}

    return root;

}

void deleteNode(Node** headref, int data)
{
     if (*headref == NULL)
    {
        throw MyException("Tree is empty. Cannot delete.");
    }

 *headref = deleteRec(*headref, data);
}

/* Print BST */
void printBST(Node* root)
{
 if (root == NULL)
    return;

 printBST(root->left);
 cout << root->data << " ";
 printBST(root->right);
}

/* Preorder traversal */
void printPreorder(Node* root)
{
 if (root == NULL)
    return;

 cout << root->data << " ";
 printPreorder(root->left);
 printPreorder(root->right);
}

void printPostorder(Node* root)
{
 if (root == NULL)
    return;

 printPostorder(root->left);
 printPostorder(root->right);
 cout << root->data << " ";
}

/* Height*/
int height(Node* root)
{
 if (root == NULL)
 {
    return -1;
 }

int leftHeight = height(root->left);
int rightHeight = height(root->right);

int maxHeight;

 if (leftHeight > rightHeight)
 {
 maxHeight = leftHeight;
 }
 else
 {
 maxHeight = rightHeight;
 }

    return 1 + maxHeight;

}

/* checking tree is balanced */
bool isBalanced(Node* root)
{
if (root == NULL)
{
    return true;
}

int leftHeight = height(root->left);
int rightHeight = height(root->right);

int difference;

if (leftHeight > rightHeight)
{
 difference = leftHeight - rightHeight;
}
else
{
 difference = rightHeight - leftHeight;
}

if (difference > 1)
{
    return false;
}

if (isBalanced(root->left) == false)
{
 return false;
}

if (isBalanced(root->right) == false)
{
    return false;
}

    return true;

}

/* total nodes */
int countNodes(Node* root)
{
 if (root == NULL)
    return 0;

 return 1 + countNodes(root->left) + countNodes(root->right);
}

/* worst-case BST */
bool isWorstCase(Node* root)
{
if (root == NULL)
{
    return false;
}

int totalNodes = countNodes(root);
int h = height(root);

if (h == totalNodes - 1)
{
    return true;
}
else
{
    return false;
}

}
