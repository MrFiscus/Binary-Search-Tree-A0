#include "bst.h"

static Node* findMin(Node* root);
static Node* deleteRec(Node* root, int data);

/* Create new node */
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

/* Insert into BST */
void insert(Node** headref, int data)
{
    if (*headref == nullptr)
    {
        *headref = newNode(data);
        return;
    }

    Node* travptr = *headref;
    Node* parent = nullptr;

    while (travptr != nullptr)
    {
        parent = travptr;

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
    if (*headref == nullptr)
        return false;

    Node* travptr = *headref;

    while (travptr != nullptr)
    {
        if (travptr->data == data)
            return true;

        travptr = (data > travptr->data)
                    ? travptr->right
                    : travptr->left;
    }
    return false;
}


static Node* findMin(Node* root)
{
    while (root != nullptr && root->left != nullptr)
        root = root->left;
    return root;
}


static Node* deleteRec(Node* root, int data)
{
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteRec(root->left, data);
    else if (data > root->data)
        root->right = deleteRec(root->right, data);
    else
    {
        // no child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // one child
        else if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // two children
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

/* Print BST */
void printBST(Node* root)
{
    if (root == nullptr)
        return;

    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}
