#include "./bst.h"

int main()
{
    Node* head = NULL;

    insert(&head, 50);
    insert(&head, 30);
    insert(&head, 70);
    insert(&head, 20);
    insert(&head, 40);
    insert(&head, 60);
    insert(&head, 80);

    cout << "BST (inorder): ";
    printBST(head);
    cout << endl;

    cout << "BST (preorder): ";
    printPreorder(head);
    cout << endl;

    cout << "BST (postorder): ";
    printPostorder(head);
    cout << endl;

    cout << "Height of tree: " << height(head) << endl;
    cout << "Is balanced? " << (isBalanced(head) ? "Yes" : "No") << endl;

    return 0;
}
