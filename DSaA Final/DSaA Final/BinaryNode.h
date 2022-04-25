/*
* Binary Node class found on pg 458
*/
#pragma once
#ifndef _BINARY_NODE
#define _BINARY_NODE

#include <string>
using namespace std;

template <class ItemType>
class BinaryNode
{
private:
	ItemType item;
	BinaryNode<ItemType>* leftChildPtr;
	BinaryNode<ItemType>* rightChildPtr;

public:
	BinaryNode();
	BinaryNode(const ItemType& entry);
	BinaryNode(const ItemType& entry,
		BinaryNode<ItemType>* left,
		BinaryNode<ItemType>* right);
	void setItem(const ItemType& anItem);
	string getItem() const;

	bool isLeaf() const;

	BinaryNode<ItemType>* getLeftChildPtr() const;
	BinaryNode<ItemType>* getRightChildPtr() const;

	void setLeftChildPtr(BinaryNode<ItemType>* left);
	void setRightChildPtr(BinaryNode<ItemType>* right);

	BinaryNode<ItemType> operator= (const BinaryNode<ItemType>& other);
};
#endif

template class BinaryNode<string>;