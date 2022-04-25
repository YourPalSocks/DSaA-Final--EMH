#include "BinaryNodeTree.h"

// -------------------- CONSTRUCTORS
BinaryNodeTree::BinaryNodeTree() : rootPtr(nullptr)
{}

BinaryNodeTree::BinaryNodeTree(const string& rootName, const string& rootBirth)
{
	rootPtr = new Person(rootName, rootBirth, nullptr, nullptr);
}

BinaryNodeTree::BinaryNodeTree(const string& rootName, const string& rootBirth,
	const Person* leftPtr,
	const Person* rightPtr)
{
	rootPtr = new Person(rootName, rootBirth, copyTree(leftPtr), copyTree(rightPtr));
}

BinaryNodeTree::BinaryNodeTree(const BinaryNodeTree& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
}

BinaryNodeTree::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}

// -------------------- PROTECTED METHODS
Person* BinaryNodeTree::copyTree(const Person* treePtr) const
{
	Person* newTreePtr = nullptr;
	if (treePtr != nullptr)
	{
		newTreePtr = new Person(treePtr->getName(), treePtr->getBirthday(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}
	return newTreePtr;
}

void BinaryNodeTree::destroyTree(Person* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}
}

int BinaryNodeTree::getNumberOfNodesHelper(Person* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + 
		getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

int BinaryNodeTree::getHeightHelper(Person* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
			getHeightHelper(subTreePtr->getRightChildPtr()));
}

Person* BinaryNodeTree::balanceAdd(Person* subTreePtr, Person* newNodePtr)
{
	if (subTreePtr == nullptr)
	{
		return newNodePtr;
	}
	else
	{
		Person* leftPtr = subTreePtr->getLeftChildPtr();
		Person* rightPtr = subTreePtr->getRightChildPtr();

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
Person* BinaryNodeTree::removeValue(Person* subTreePtr,
	const string& name, bool& success)
{
	if (subTreePtr == nullptr)
	{
		success = false;
		return subTreePtr;
	}
	Person* toRemove = findNodeByName(subTreePtr, name, success); // Find the node to remove
	if (success) // Check if successful
	{
		moveValuesUpTree(toRemove);
	}
	return subTreePtr;

}

// Copies values up the tree to overwrite value in current node until
// a leaf is reached; the leaf is then removed, since its value is
// stored in the parent.
Person* BinaryNodeTree::moveValuesUpTree(Person* subTreePtr)
{
	if (subTreePtr != nullptr) // Make sure it isn't null
	{
		if (!subTreePtr->isLeaf())
		{
			if (subTreePtr->getLeftChildPtr() != nullptr)
			{
				subTreePtr->setName(subTreePtr->getLeftChildPtr()->getName());
				subTreePtr->setBirthday(subTreePtr->getLeftChildPtr()->getBirthday());
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
				subTreePtr->setName(subTreePtr->getRightChildPtr()->getName());
				subTreePtr->setBirthday(subTreePtr->getRightChildPtr()->getBirthday());
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
Person* BinaryNodeTree::findNodeByName(Person* treePtr, const string& target, bool& success) const
{
	Person* foundPtr;
	if (treePtr == nullptr) // Make sure it's not empty
	{
		success = false;
		return treePtr;
	}

	if (treePtr->getName()._Equal(target)) // Check root first
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
void BinaryNodeTree::preorder(void visit(Person&), Person* treePtr) const
{
	if (treePtr != nullptr)
	{
		visit(*treePtr); // Root First
		preorder(visit, treePtr->getLeftChildPtr()); // Left tree
		preorder(visit, treePtr->getRightChildPtr()); // Right tree
	}
}

void BinaryNodeTree::inorder(void visit(Person&), Person* treePtr) const
{
	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		Person theItem = *treePtr;
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}
}

void BinaryNodeTree::postorder(void visit(Person&), Person* treePtr) const
{
	postorder(visit, treePtr->getLeftChildPtr()); // Left Tree
	postorder(visit, treePtr->getRightChildPtr()); // Right Tree
	visit((Person &) treePtr); // Root
}

// -------------------- PUBLIC METHODS
bool BinaryNodeTree::isEmpty() const
{
	if (rootPtr == nullptr)
		return true;
	else
		return false;
}

int BinaryNodeTree::getHeight() const
{
	return getHeightHelper(rootPtr);
}

bool BinaryNodeTree::add(Person& newData)
{
	rootPtr = balanceAdd(rootPtr, &newData);
	return true;
}

bool BinaryNodeTree::remove(const string& name) throw (NotFoundException)
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

void BinaryNodeTree::clear()
{
	if (rootPtr != nullptr)
	{
		destroyTree(rootPtr->getLeftChildPtr());
		destroyTree(rootPtr->getRightChildPtr());
		rootPtr = nullptr;
	}
}

Person BinaryNodeTree::getEntry(const string& name) const throw (NotFoundException)
{
	bool found = false;
	Person* node = findNodeByName(rootPtr, name, found);
	if (found)
	{
		return *node;
	}
	else
	{
		throw NotFoundException("Not found in tree");
	}
}

bool BinaryNodeTree::contains(const string& anEntry) const
{
	bool found = false;
	findNodeByName(rootPtr, anEntry, found);
	return found;
}

int BinaryNodeTree::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);
}

Person BinaryNodeTree::getRootData() throw (PrecondViolationExcep)
{
	if (rootPtr != nullptr)
		return *rootPtr;
	else
		throw PrecondViolationExcep("Tree is empty");
}

void BinaryNodeTree::setRootData(const Person& newPerson)
{
	rootPtr->setName(newPerson.getName());
	rootPtr->setBirthday(newPerson.getBirthday());
}

// -------------------- PUBLIC TRAVERSAL METHODS
void BinaryNodeTree::preorderTraverse(void visit(Person&)) const
{
	preorder(visit, rootPtr);
}

void BinaryNodeTree::inorderTraverse(void visit(Person&)) const
{
	inorder(visit, rootPtr);
}

void BinaryNodeTree::postorderTraverse(void visit(Person&)) const
{
	postorder(visit, rootPtr);
}

// -------------------- OPERATOR METHODS
BinaryNodeTree& BinaryNodeTree::operator=(const BinaryNodeTree& rightHandSide)
{
	if (!isEmpty())
	{
		clear();
	}
	rootPtr = copyTree(rightHandSide.rootPtr);
	return *this;
}