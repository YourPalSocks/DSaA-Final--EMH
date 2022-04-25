#include "BinaryNode.h"

// -------------------- CONSTRUCTORS
Person::Person()
{
	name = "";
	birthday = "";
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

Person::Person(const string& mName, const string& mBirthday)
{
	name = mName;
	birthday = mBirthday;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

Person::Person(const string& mName, const string& mBirthday, Person* left, Person* right)
{
	name = mName;
	birthday = mBirthday;
	leftChildPtr = left;
	rightChildPtr = right;
}

// -------------------- PUBLIC METHODS

void Person::setName(const string& anItem)
{
	name = anItem;
}

void Person::setBirthday(const string& anItem)
{
	birthday = anItem;
}

string Person::getName() const
{
	return name;
}

string Person::getBirthday() const
{
	return birthday;
}


bool Person::isLeaf() const
{
	if (leftChildPtr == nullptr && rightChildPtr == nullptr)
	{
		return true;
	}
	return false;
}

Person* Person::getLeftChildPtr() const
{
	return leftChildPtr;
}

Person* Person::getRightChildPtr() const
{
	return rightChildPtr;
}

void Person::setLeftChildPtr(Person* left)
{
	leftChildPtr = left;
}

void Person::setRightChildPtr(Person* right)
{
	rightChildPtr = right;
}
