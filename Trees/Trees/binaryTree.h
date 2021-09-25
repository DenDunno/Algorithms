#pragma once
#include "node.h"

class BinaryTree
{
public:

	BinaryTree();	

	void add(int number);
	bool search(int number);
	int getHeightOfBinaryTree();
	int size();

private:

	bool isRootInited_;
	int size_;
	Node* root_;

	void add(Node* node, int number);
	int getHeightOfNode(Node* node);
	bool search(Node* node , int number);
};