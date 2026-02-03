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
 cout << "Is balanced? ";
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
 cout << "Is worstcase? ";
 if (worst == true)
 {
  cout << "Yes";
 }
 else
 {
  cout << "No";
 }
 cout << endl;


 
 return 0;
}
