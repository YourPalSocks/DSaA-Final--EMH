/*
* Ethan Heinlein CIS.2207.502
* Final Project

* Create a function called bool isSameTree(Tree *); that will take an argument of a tree.
* It will return a true if the argument is the equivalent tree.
    So for example, if we have two trees,

   A.  insert(‘abc’);
    insert(‘def’);
    insert(‘ghi’);

   B.  insert(‘def’);
    insert(‘abc’);
    insert(‘ghi’);

* These two trees, even though they have different structures, are equivalent, and should return a true.
* If we compare these two trees:

   C. insert(‘abc’);
    insert(‘ghi’);

   D. insert(‘abc’);
    insert(‘def’);
    insert(‘ghi’);

* They will return a false when sent to the function.
*/

#include <iostream>
#include <string>

#include "BinaryNodeTree.h"
#include "BinaryNode.h"
using namespace std;

// Function Declarations
bool isSameTree(BinaryNodeTree<string> treeA, BinaryNodeTree<string> treeB);

int main()
{
    int menuSelection = -1;
    do
    {
        // Print Menu
        cout << "Binary Tree Comparison Program -- CI.2207 Final" << endl;
        cout << "0  == See non-equivalent example" << endl;
        cout << "1  == See equivalent example" << endl;
        cout << "-1 == Quit Program" << endl;
        cout << "Enter your selection: ";
        cin >> menuSelection;

        // Do Menu Actions
        switch (menuSelection)
        {
            default:
                cout << "Menu option not available." << endl;
                break;

            case 0:
                break;

            case 1:
                break;

            case -1:
                cout << "Now quitting..." << endl;
                break;
        }
        system("pause");
        system("cls");
    } while (menuSelection != -1);

    return 0;
}


/** The function specified to make for the final. Compares two trees.
* @param treeA Tree to compare to treeB.
* @param treeB Tree to compare to treeA.
* @return True if structures of tree are same, false otherwise.
*/
bool isSameTree(BinaryNodeTree<string> treeA, BinaryNodeTree<string> treeB)
{
    return false;
}