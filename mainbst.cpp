#include "./bst.h"

int main()
{
    Node* head = NULL;

    // insert(&head, 4);
    // insert(&head, 2);
    // insert(&head, 6);
    // insert(&head, 1);
    // insert(&head, 3);
    // insert(&head, 5);
    // insert(&head, 7);

    Node* worst = NULL;
    insert(&worst, 1);
    insert(&worst, 2);
    insert(&worst, 3);
    insert(&worst, 4);
    insert(&worst, 5);

    cout << "Height of adversarial BST: " << height(worst) << endl;
    cout << "Is worst-case BST? " << (isWorstCase(worst) ? "Yes" : "No") << endl;


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
