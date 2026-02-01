#include "bst.h"

/* Forward declarations (local helpers) */
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
        parent = travptr;

        // Ignore duplicates
        if (data == travptr->data)
            return;

        travptr = (data > travptr->data)
                    ? travptr->right
                    : travptr->left;
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
        return false;

    Node* travptr = *headref;

    while (travptr != NULL)
    {
        if (travptr->data == data)
            return true;

        travptr = (data > travptr->data)
                    ? travptr->right
                    : travptr->left;
    }
    return false;
}

/* Find minimum node */
static Node* findMin(Node* root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

/* Recursive delete helper */
static Node* deleteRec(Node* root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteRec(root->left, data);
    else if (data > root->data)
        root->right = deleteRec(root->right, data);
    else
    {
        // Case 1: no child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2: one child
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: two children
        else
        {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
    }
    return root;
}

/* Delete wrapper */
void deleteNode(Node** headref, int data)
{
    *headref = deleteRec(*headref, data);
}

/* Print BST (inorder) */
void printBST(Node* root)
{
    if (root == NULL)
        return;

    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}
