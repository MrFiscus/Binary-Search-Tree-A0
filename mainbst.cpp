#include "./bst.h"
#include "customErrorClass.h"

int main()
{
try
{
 Node* head = NULL;

 insert(&head, 1);
 insert(&head, 2);
 insert(&head, 3);
 insert(&head, 4);
 insert(&head, 5);
 insert(&head, 6);
 insert(&head, 7);
 insert(&head, 8);
 insert(&head, 9);
 insert(&head, 10);
 insert(&head, 11);
 insert(&head, 12);
 insert(&head, 13);
 insert(&head, 14);
 insert(&head, 15);
 insert(&head, 16);
 insert(&head, 17);
 insert(&head, 18);

 bool result;

 result = find(&head, 4);

 cout << "Find 4: ";
 if (result == true)
 {
  cout << "Found";
 }
 else
 {
  cout << "Not Found";
 }
 cout << endl;

 result = find(&head, 21);

 cout << "Find 21: ";
 if (result == true)
 {
  cout << "Found";
 }
 else
 {
  cout << "Not Found";
 }
 cout << endl;


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

 int h = height(head);
 cout << "Height of tree: " << h << endl;

 bool balanced = isBalanced(head);
 cout << "Balanced: ";
 if (balanced == true)
 {
  cout << "Yes";
 }
 else
 {
 cout << "No";
 }
 cout << endl;

 bool worst = isWorstCase(head);
 cout << "Worstcase: ";
 if (worst == true)
 {
  cout << "Yes";
 }
 else
 {
  cout << "No";
 }
 cout << endl;
 }

 catch (MyException &e)
    {
        cerr << e.what() << endl;
    }

 return 0;
}
