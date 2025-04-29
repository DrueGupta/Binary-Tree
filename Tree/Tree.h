#pragma once
#include <iostream>
using namespace std;
template <typename TYPE>
struct node
{
	TYPE data;
	node<TYPE>* left;
	node<TYPE>* right;

	node(TYPE value)
	{
		this->data = value;
		this->left = nullptr;
		this->right = nullptr;
	}
	node()
	{
		this->left = nullptr;
		this->right = nullptr;
	}
};

template <typename TYPE>
class Tree
{
private:
	node<TYPE>* root;

	node<TYPE>* successor(node<TYPE>* current)
	{
		current = current->right;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}
public:
	Tree()
	{
		this->root = nullptr;
	}
	Tree(node<TYPE>* root)
	{
		this->root = root;
	}
	node<TYPE>* searchRec(TYPE target, node<TYPE>* current)
	{
		if (current == nullptr)
			return nullptr;
		else if (current->data == target)
			return current;
		else if (target > current->data)
			return searchRec(target, current->right);
		else
			return searchRec(target, current->left);
	}
	node<TYPE>* search(TYPE target)
	{
		return searchRec(target, this->root);
	}
	void insertRec(TYPE value, node<TYPE>* current)
	{
		if (this->root == nullptr)
		{
			this->root = new node<TYPE>(value);
			return;
		}
		if (value < current->data)
		{
			if (current->left == nullptr)
				current->left = new node<TYPE>(value);
			else
				insertRec(value, current->left);
		}
		else
		{
			if (current->right == nullptr)
				current->right = new node<TYPE>(value);
			else
				insertRec(value, current->right);
		}
	}
	void insert(TYPE value)
	{
		insertRec(value, this->root);
	}

	void displayRec(node<TYPE>* current)
	{
		if (current != nullptr)
		{
			displayRec(current->left);
			displayRec(current->right);
			cout << current->data << endl;
		}
	}
	void display()
	{
		displayRec(this->root);
	}

	node<TYPE>* removeRec(TYPE target, node<TYPE>* current)
	{
		if (current == nullptr)
			return current;
		else if (target < current->data)
			current->left = removeRec(target, current->left);
		else if (target > current->data)
			current->right = removeRec(target, current->right);
		else
		{
			if (current->left == nullptr && current->right == nullptr)
				return nullptr;
			else if (current->left == nullptr)
			{
				node<TYPE>* temp = current->right;
				delete current;
				return temp;
			}
			else if (current->right == nullptr)
			{
				node<TYPE>* temp = current->left;
				delete current;
				return temp;
			}
			else
			{
				node<TYPE>* temp = successor(current);
				current->data = temp->data;
				current->right = removeRec(temp->data, current->right);
			}
		}
		return current;
	}
	void remove(TYPE value)
	{
		this->root = removeRec(value, this->root);
	}
	int sizeRec(node<TYPE>* current)
	{
		if (current == nullptr)
			return 0;
		else
			return 1 + sizeRc(current->left) + sizeRec(current->right);
	}
	int size()
	{
		return sizeRec(this->root);
	}
	TYPE minRec(node<TYPE>* current)
	{
		if (current->left == nullptr)
			return current->data;
		else
			return minRec(current->left);
	}
	TYPE min()
	{
		return minRec(this->root);
	}
	TYPE maxRec(node<TYPE>* current)
	{
		if (current->right == nullptr)
			return current->data;
		else
			return maxRec(current->right);
	}
	TYPE man()
	{
		return maxRec(this->root);
	}
};
