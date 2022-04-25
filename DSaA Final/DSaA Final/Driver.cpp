/*
* Ethan Heinlein CIS.2207.502
* Final

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

int main()
{
    cout << "Hello World" << endl;
    system("pause");
    return 0;
}