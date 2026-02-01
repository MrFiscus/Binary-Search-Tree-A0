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

Node* newNode(int key);

void insert(Node** headref, int data);
bool find(Node** headref, int data);

void deleteNode(Node** headref, int data);

void printBST(Node* root);

#endif
