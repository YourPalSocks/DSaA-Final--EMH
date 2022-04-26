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
#include "NotFoundException.h"
using namespace std;

// Function Declarations
string createData();
void printTree(string& item);

int main()
{
    int menuSelection = -1;
    BinaryNodeTree<string> treeA;
    BinaryNodeTree<string> treeB;
    do
    {
        // Print Menu
        cout << "Binary Tree Comparison Program -- CI.2207 Final" << endl;
        cout << "** NOTE: All print functions use preorder traversal." << endl;
        cout << "===== Tree A Commands =====" << endl;
        cout << "0 - Add to tree" << endl;
        cout << "1 - Remove from tree" << endl;
        cout << "2 - Print tree" << endl;
        cout << endl;

        cout << "===== Tree B Commands =====" << endl;
        cout << "3 - Add to tree" << endl;
        cout << "4 - Remove from tree" << endl;
        cout << "5 - Print tree" << endl;
        cout << endl;

        cout << "===== Other Commands =====" << endl;
        cout << "6 - Compare trees" << endl;
        cout << "7 - Clear trees" << endl;
        cout << "-1 - Quit Program" << endl << endl;
        cout << "Enter your choice: " << endl;
        cin >> menuSelection;

        // Do menu actions
        bool s = false;
        switch (menuSelection)
        {
            default:
                cout << "No such option found. Please retry." << endl;
                break;

            // TREE A COMMS
            case 0: // Add
            {
                s = treeA.add(createData());
                if (s)
                    cout << "Item added." << endl;
                else
                    cout << "Item could not be added." << endl;
                break;
            }

            case 1: // Remove
            {
                string qu = createData();
                try
                {
                    s = treeA.remove(qu);
                    if (s)
                        cout << "Item removed." << endl;
                    else
                        cout << "Item could not be removed." << endl;
                }
                catch (NotFoundException e)
                {
                    cout << "ERROR: Item does not exist in tree." << endl;
                }
                break;
            }

            case 2: // Print
                treeA.preorderTraverse(printTree);
                break;

            // TREE B COMMS
            case 3: // Add
            {
                s = treeB.add(createData());
                if (s)
                    cout << "Item added." << endl;
                else
                    cout << "Item could not be added." << endl;
                break;
            }

            case 4: // Remove
            {
                string qu = createData();
                try
                {
                    s = treeB.remove(qu);
                    if (s)
                        cout << "Item removed." << endl;
                    else
                        cout << "Item could not be removed." << endl;
                }
                catch (NotFoundException e)
                {
                    cout << "ERROR: Item does not exist in tree." << endl;
                }
                break;
            }

            case 5: // Print
                treeB.preorderTraverse(printTree);
                break;

            // OTHER COMMS
            case 6:
                if (treeA.isSameTree(treeB))
                {
                    cout << "The two trees are equivalent" << endl;
                }
                else
                {
                    cout << "The two trees are NOT equivalent" << endl;
                }
                break;

            case 7:
                treeA.clear();
                treeB.clear();
                cout << "Trees cleared" << endl;
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

string createData()
{
    string toRem = "";
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, toRem);
    return toRem;
}

void printTree(string& item)
{
    cout << item << endl;
}