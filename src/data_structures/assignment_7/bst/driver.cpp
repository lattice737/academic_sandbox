/*----- BSTtester.cpp -----------------------------------------------------
                Program for testing BST class template
 ------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and empty()
   BST<int> intBST;            // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n\n";

   // Testing inorder
   cout << "Inorder Traversal of BST: \n";
   intBST.inorder(cout);
   cout << endl;

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
        cout << "\nItem to insert (-999 to stop): ";
        cin >> number;
        if (number == -999) break;
        intBST.add(number);
   }
   cout << '\n';
   intBST.graph(cout);
   cout << endl;

   cout << "BST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n";
   cout << "Inorder Traversal of BST: \n";
   intBST.inorder(cout);
   cout << endl;

   // Testing search()
   cout << "\n\nNow testing the contains() operation."
           "\nTry both items in the BST and some not in it:\n";
   for (;;)
   {
        cout << "Item to find (-999 to stop): ";
        cin >> number;
        if (number == -999) break;
        cout << (intBST.contains(number) ? "Found\n" : "Not found\n") << endl;
   }

   // Testing remove()
   cout << "\nNow testing the remove() operation."
           "\nTry both items in the BST and some not in it:\n";
   for (;;)
   {
        cout << "\nItem to remove (-999 to stop): ";
        cin >> number;
        if (number == -999) break;
        intBST.remove(number);
        cout << endl;
        intBST.graph(cout);
        cout << endl;
   }
   cout << "\nInorder Traversal of BST: \n";
   intBST.inorder(cout);
   cout << endl;

   // TODO
   // 1) getHeight() test
   // 2) getNumberOfNodes() test
   // 3) getNumberOfLeaves() test
   
}