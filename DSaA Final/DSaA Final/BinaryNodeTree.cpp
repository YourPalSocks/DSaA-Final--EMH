#include "BinaryNodeTree.h"

// -------------------- CONSTRUCTORS
template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNode<ItemType>* root)
{
	rootPtr->setItem(root->getItem());
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNode<ItemType>* root, 
	BinaryNode<ItemType>* leftPtr,
	BinaryNode<ItemType>* rightPtr)
{
	rootPtr->setItem(root->getItem());
	rootPtr->setLeftChildPtr(leftPtr);
	rootPtr->setRightChildPtr(rightPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
}

template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}

// -------------------- PROTECTED METHODS
template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
	BinaryNode<ItemType>* newTreePtr = nullptr;
	if (treePtr != nullptr)
	{
		newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}
	return newTreePtr;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + 
		getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
			getHeightHelper(subTreePtr->getRightChildPtr()));
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balanceAdd(BinaryNode<ItemType>* subTreePtr, 
	BinaryNode<ItemType>* newNodePtr)
{
	if (subTreePtr == nullptr)
	{
		return newNodePtr;
	}
	else
	{
		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balanceAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balanceAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}
		return subTreePtr;
	}
}

// Removes the target value from the tree by calling moveValuesUpTree
// to overwrite value with value from child.
template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
	const string& name, bool& success)
{
	if (subTreePtr == nullptr)
	{
		success = false;
		return subTreePtr;
	}
	BinaryNode<ItemType>* toRemove = findNodeByName(subTreePtr, name, success); // Find the node to remove
	if (success) // Check if successful
	{
		moveValuesUpTree(toRemove);
	}
	return subTreePtr;

}

// Copies values up the tree to overwrite value in current node until
// a leaf is reached; the leaf is then removed, since its value is
// stored in the parent.
template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr) // Make sure it isn't null
	{
		if (!subTreePtr->isLeaf())
		{
			if (subTreePtr->getLeftChildPtr() != nullptr)
			{
				subTreePtr->setItem(subTreePtr->getLeftChildPtr()->getItem());
				if (subTreePtr->getLeftChildPtr()->isLeaf())
				{
					subTreePtr->setLeftChildPtr(nullptr);
					delete subTreePtr->getLeftChildPtr();
				}
				else
				{
					moveValuesUpTree(subTreePtr->getLeftChildPtr());
				}
			}
			else if (subTreePtr->getRightChildPtr() != nullptr)
			{
				subTreePtr->setItem(subTreePtr->getRightChildPtr()->getItem());
				if (subTreePtr->getRightChildPtr()->isLeaf())
				{
					subTreePtr->setRightChildPtr(nullptr);
					delete subTreePtr->getRightChildPtr();
				}
				else
				{
					moveValuesUpTree(subTreePtr->getRightChildPtr());
				}
			}
		}
	}
	return subTreePtr;
}

// Recursively searches for target value in the tree by using a
// preorder traversal.
template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNodeByName(BinaryNode<ItemType>* treePtr, 
	const string& target, bool& success) const
{
	BinaryNode<ItemType>* foundPtr;
	if (treePtr == nullptr) // Make sure it's not empty
	{
		success = false;
		return treePtr;
	}

	if (treePtr->getItem()._Equal(target)) // Check root first
	{
		success = true;
		return treePtr;
	}
	else // Look through children in preorder
	{
		foundPtr = findNodeByName(treePtr->getLeftChildPtr(), target, success); // Left
		if (!success)
		{
			foundPtr = findNodeByName(treePtr->getRightChildPtr(), target, success);
		}
	}
	return foundPtr;
}

// -------------------- PROTECTED TRAVERSAL METHODS
template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), 
	BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType item = treePtr->getItem();
		visit(item); // Root First
		preorder(visit, treePtr->getLeftChildPtr()); // Left tree
		preorder(visit, treePtr->getRightChildPtr()); // Right tree
	}
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(BinaryNode<ItemType>* treePtr, ItemType* arr)
{
	if (treePtr != nullptr)
	{
		ItemType item = treePtr->getItem();
		arr[arrayTracker] = item;
		arrayTracker++;
		preorder(treePtr->getLeftChildPtr(), arr); // Left tree
		preorder(treePtr->getRightChildPtr(), arr); // Right tree
	}
}

// -------------------- PUBLIC METHODS
template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
	if (rootPtr == nullptr)
		return true;
	else
		return false;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
	return getHeightHelper(rootPtr);
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
	// Create new node with data
	BinaryNode<ItemType>* newNode = new BinaryNode<ItemType>();
	newNode->setItem(newData);
	// Send to be added
	rootPtr = balanceAdd(rootPtr, newNode);
	return true;
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::remove(const string& name) throw (NotFoundException)
{
	bool result = false;
	if (!contains(name)) // Make sure the data exists in tree
	{
		throw NotFoundException("Not Found Exception");
		return false;
	}
	rootPtr = removeValue(rootPtr, name, result);
	return result;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
	if (rootPtr != nullptr)
	{
		destroyTree(rootPtr->getLeftChildPtr());
		destroyTree(rootPtr->getRightChildPtr());
		rootPtr = nullptr;
	}
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const string& name) const throw (NotFoundException)
{
	bool found = false;
	BinaryNode<ItemType>* node = findNodeByName(rootPtr, name, found);
	if (found)
	{
		return node->getItem();
	}
	else
	{
		throw NotFoundException("Not found in tree");
	}
}

template <class ItemType>
bool BinaryNodeTree<ItemType>::contains(const string& anEntry) const
{
	bool found = false;
	findNodeByName(rootPtr, anEntry, found);
	return found;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw (PrecondViolationExcep)
{
	if (rootPtr != nullptr)
		return rootPtr->getItem();
	else
		throw PrecondViolationExcep("Tree is empty");
}

template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
	rootPtr->setItem(newData);
}

// -------------------- PUBLIC TRAVERSAL METHODS
template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	preorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	//inorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	//postorder(visit, rootPtr);
}

/** The function specified to make for the final. Compares two trees.
* @param treeA Tree to compare to treeB.
* @param treeB Tree to compare to treeA.
* @return True if structures of tree are same, false otherwise.
*/
template <class ItemType>
bool BinaryNodeTree<ItemType>::isSameTree(BinaryNodeTree<string> other)
{
	// First check: heights and node amount
	if (getHeight() != other.getHeight() || getNumberOfNodes() != other.getNumberOfNodes())
	{
		return false;
	}
	// Second check: every element has a match in the other array
	int size = getNumberOfNodes();
	ItemType* arr_TreeA = createNodeArray();
	ItemType* arr_TreeB = other.createNodeArray();
	// Check
	for (int i = 0; i < size; i++)
	{
		bool matchFound = false;
		for (int j = 0; j < size; j++) // Already established that the two trees have the same # of nodes
		{
			if (arr_TreeA[i] == arr_TreeB[j])
			{
				matchFound = true;
				break;
			}
		}
		// Automatically leave if a match couldn't be found for an entry
		if (!matchFound)
		{
			return false;
		}
	}
	// Left loop, every entry has a match
	return true;
}

template <class ItemType>
ItemType* BinaryNodeTree<ItemType>::createNodeArray()
{
	int size = getNumberOfNodes();
	ItemType* nodes = new ItemType[size];
	preorder(rootPtr, nodes);
	return nodes;
}

// -------------------- OPERATOR METHODS
template <class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree& rightHandSide)
{
	if (!isEmpty())
	{
		clear();
	}
	rootPtr = copyTree(rightHandSide.rootPtr);
	return *this;
}