#include "BinaryNode.h"

// -------------------- CONSTRUCTORS
template <class ItemType>
BinaryNode<ItemType>::BinaryNode<ItemType>()
{
	item;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode<ItemType>(const ItemType& entry)
{
	item = entry;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode<ItemType>(const ItemType& entry, BinaryNode<ItemType>* left, BinaryNode<ItemType>* right)
{
	item = entry;
	leftChildPtr = left;
	rightChildPtr = right;
}

// -------------------- PUBLIC METHODS
template <class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template <class ItemType>
string BinaryNode<ItemType>::getItem() const
{
	return item;
}

template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
	if (leftChildPtr == nullptr && rightChildPtr == nullptr)
	{
		return true;
	}
	return false;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;
}

template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* left)
{
	leftChildPtr = left;
}

template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* right)
{
	rightChildPtr = right;
}

template <class ItemType>
BinaryNode<ItemType> BinaryNode<ItemType>::operator=(const BinaryNode<ItemType>& other)
{
	item = other.getItem();
	leftChildPtr = other.getLeftChildPtr();
	rightChildPtr = other.getRightChildPtr();
	return *this;
}
