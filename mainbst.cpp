#include "./bst.h"

int main()
{
    Node* head = NULL;

    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 6);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 10);

    cout << "Find 3: " << (find(&head, 4) ? "Found" : "Not Found") << endl;
    cout << "Find 10: " << (find(&head, 21) ? "Found" : "Not Found") << endl;

    deleteNode(&head, 10);

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
    cout << "Is worstcase? " << (isWorstCase(head) ? "Yes" : "No") << endl;

    
    return 0;
}
