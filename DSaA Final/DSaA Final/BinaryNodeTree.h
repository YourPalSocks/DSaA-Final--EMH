/*
* Binary Node Tree seen on pg 460
*/

#pragma once
#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

template <class ItemType>
class BinaryNodeTree : BinaryTreeInterface<ItemType>
{
private:
	BinaryNode<ItemType>* rootPtr;
	int arrayTracker = 0;

protected:
	int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
	void destroyTree(BinaryNode<ItemType>* subTreePtr);

	BinaryNode<ItemType>* balanceAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
	BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const string& name, bool& success);
	BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
	BinaryNode<ItemType>* findNodeByName(BinaryNode<ItemType>* treePtr, const string& target, bool& success) const;
	BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;

	void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	void preorder(BinaryNode<ItemType>* treePtr, ItemType* arr);

public:
	BinaryNodeTree();
	BinaryNodeTree(const BinaryNode<ItemType>* root);
	BinaryNodeTree(const BinaryNode<ItemType>* root, BinaryNode<ItemType>* leftPtr, 
		BinaryNode<ItemType>* rightPtr);
	BinaryNodeTree(const BinaryNodeTree& tree);
	virtual ~BinaryNodeTree();

	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const throw (PrecondViolationExcep);
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData);
	bool remove(const string& name) throw (NotFoundException);
	void clear();
	ItemType getEntry(const string& anEntry) const throw (NotFoundException);
	bool contains(const string& anEntry) const;

	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;

	bool isSameTree(BinaryNodeTree<string> other);
	ItemType* createNodeArray();

	BinaryNodeTree<ItemType>& operator=(const BinaryNodeTree<ItemType>& rightHandSide);
};
#endif
template class BinaryNodeTree<string>;