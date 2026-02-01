#include "./bst.h"

int main()
{
    Node* head = nullptr;

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

    cout << "Find 40: " << find(&head, 40) << endl;
    cout << "Find 100: " << find(&head, 100) << endl;

    deleteNode(&head, 20);   
    deleteNode(&head, 30);   
    deleteNode(&head, 50); 

    cout << "BST after deletions: ";
    printBST(head);
    cout << endl;

    return 0;
}
