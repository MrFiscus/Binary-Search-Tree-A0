#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Task 1
Node* newNode(int key);
void insert(Node** headref, int data);
bool find(Node** headref, int data);
void deleteNode(Node** headref, int data);
void printBST(Node* root);

// Task 2
void printPreorder(Node* root);
void printPostorder(Node* root);
int height(Node* root);
bool isBalanced(Node* root);

#endif
