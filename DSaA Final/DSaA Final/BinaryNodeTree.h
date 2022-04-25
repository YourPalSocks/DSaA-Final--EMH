/*
* Binary Node Tree seen on pg 460
*/

#pragma once
#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

template <class ItemType>
class BinaryNodeTree
{
private:
	BinaryNode<ItemType>* rootPtr;

protected:
	int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
	void destroyTree(BinaryNode<ItemType>* subTreePtr);

	BinaryNode* balanceAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
	BinaryNode* removeValue(BinaryNode<ItemType>* subTreePtr, const string& name, bool& success);
	BinaryNode* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
	BinaryNode* findNodeByName(BinaryNode<ItemType>* treePtr, const string& target, bool& success) const;
	BinaryNode* copyTree(const BinaryNode<ItemType>* treePtr) const;

	void preorder(void visit(BinaryNode<ItemType>&), BinaryNode<ItemType>* treePtr) const;
	void inorder(void visit(BinaryNode<ItemType>&), BinaryNode<ItemType>* treePtr) const;
	void postorder(void visit(BinaryNode<ItemType>&), BinaryNode<ItemType>* treePtr) const;

public:
	BinaryNodeTree();
	BinaryNodeTree(const BinaryNode<ItemType>* root);
	BinaryNodeTree(const BinaryNode<ItemType>* root, const BinaryNode<ItemType>* leftPtr, 
		const BinaryNode<ItemType>* rightPtr);
	BinaryNodeTree(const BinaryNodeTree& tree);
	virtual ~BinaryNodeTree();

	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	BinaryNode<ItemType> getRootData() throw (PrecondViolationExcep);
	void setRootData(const Person& newPerson);
	bool add(Person& newData);
	bool remove(const string& name) throw (NotFoundException);
	void clear();
	BinaryNode<ItemType> getEntry(const string& anEntry) const throw (NotFoundException);
	bool contains(const string& anEntry) const;

	void preorderTraverse(void visit(Person&)) const;
	void inorderTraverse(void visit(Person&)) const;
	void postorderTraverse(void visit(Person&)) const;

	BinaryNodeTree<ItemType>& operator=(const BinaryNodeTree<ItemType>& rightHandSide);
};
#endif
template class BinaryNodeTree<string>;