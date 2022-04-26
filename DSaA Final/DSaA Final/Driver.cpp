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
bool isSameTree(BinaryNodeTree<string> treeA, BinaryNodeTree<string> treeB);

BinaryNode<string> createNewNode();
string createSearchQuery();
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
            case 0:
            {
                BinaryNode<string> newNode = createNewNode();
                s = treeA.add(newNode);
                if (s)
                    cout << "Item added." << endl;
                else
                    cout << "Item could not be added." << endl;
                break;
            }

            case 1:
            {
                string qu = createSearchQuery();
                s = treeA.remove(qu);
                if (s)
                    cout << "Item removed." << endl;
                else
                    cout << "Item could not be removed." << endl;
                break;
            }

            case 2:
                treeA.preorderTraverse(printTree);
                break;

            // TREE B COMMS
            case 3:
            {
                BinaryNode<string> newNode = createNewNode();
                s = treeB.add(newNode);
                if (s)
                    cout << "Item added." << endl;
                else
                    cout << "Item could not be added." << endl;
                break;
            }

            case 4:
            {
                string qu = createSearchQuery();
                s = treeB.remove(qu);
                if (s)
                    cout << "Item removed." << endl;
                else
                    cout << "Item could not be removed." << endl;
                break;
            }

            case 5:
                treeB.preorderTraverse(printTree);
                break;

            // OTHER COMMS
            case 6:
                if (isSameTree(treeA, treeB))
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


/** The function specified to make for the final. Compares two trees.
* @param treeA Tree to compare to treeB.
* @param treeB Tree to compare to treeA.
* @return True if structures of tree are same, false otherwise.
*/
bool isSameTree(BinaryNodeTree<string> treeA, BinaryNodeTree<string> treeB)
{
    // First check: heights and node amount
    if (treeA.getHeight() != treeB.getHeight() || treeA.getNumberOfNodes() != treeB.getNumberOfNodes())
    {
        return false;
    }
    // Second check: <>
    return false;
}

BinaryNode<string> createNewNode()
{
    string item = "";
    cout << "Enter item to add: ";
    cin.ignore();
    getline(cin, item);
    BinaryNode<string> newNode(item);
    return newNode;
}

string createSearchQuery()
{
    string toRem = "";
    cout << "Enter item to remove: ";
    cin.ignore();
    getline(cin, toRem);
    return toRem;
}

void printTree(string& item)
{
    cout << item << endl;
}