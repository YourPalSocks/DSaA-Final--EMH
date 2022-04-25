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
	BinaryNode<ItemType>* rootPtr;
	BinaryNode<ItemType>* leftChildPtr;
	BinaryNode<ItemType>* rightChildPtr;

public:
	BinaryNode();
	BinaryNode(const ItemType& item);
	BinaryNode(const ItemType& item,
		BinaryNode<ItemType>* left,
		BinaryNode<ItemType>* right);
	void setName(const ItemType& anItem);
	void setBirthday(const ItemType& anItem);
	string getName() const;
	string getBirthday() const;

	bool isLeaf() const;

	BinaryNode<ItemType>* getLeftChildPtr() const;
	BinaryNode<ItemType>* getRightChildPtr() const;

	void setLeftChildPtr(BinaryNode<ItemType>* left);
	void setRightChildPtr(BinaryNode<ItemType>* right);
};
#endif

template class BinaryNode<string>;