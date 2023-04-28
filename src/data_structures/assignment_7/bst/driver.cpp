// Programmer:      Nicholas Martinez
// Project number:  7
// Project Desc:    Binary search tree implementation
// Course:          COSC 2436 PF III Data Structures
// Date:            4/28/23

/*----- BSTtester.cpp -----------------------------------------------------
                Program for testing BST class template
 ------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and isEmpty()

   BST<int> intBST;            // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n\n";

   // Testing inorder()

   cout << "Inorder Traversal of BST: \n";
   intBST.inorder(cout);
   cout << endl;

   // Testing insert()

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

   // Testing getHeight()

   cout << "\nNow testing the getHeight() operation."
        << "\nTree has height " << intBST.getHeight() << endl;

   // Testing getNumberOfNodes()

   cout << "\nNow testing the getNumberOfNodes() operation."
        << "\nTree has " << intBST.getNumberOfNodes() << " nodes." << endl;

   // Testing getNumberOfLeaves()

   cout << "\nNow testing getNumberOfLeaves()."
        << "\nTree has " << intBST.getNumberOfLeaves() << " leaves.";

   // Testing contains()

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
   cout << "\n\nBST height: " << intBST.getHeight() << endl;
   cout << "BST nodes: " << intBST.getNumberOfNodes() << endl;
   cout << "BST leaves: " << intBST.getNumberOfLeaves() << endl;
   cout << endl;
}