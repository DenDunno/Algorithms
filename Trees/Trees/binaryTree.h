#pragma once
#include "node.h"
#include <vector>

class BinaryTree
{
public:

	BinaryTree();	

	void add(int number);
	bool search(int number);

	int getHeightOfBinaryTree();
	std::vector<int> getAllLeafs();

	int size();

private:

	Node* root_;
	bool isRootInited_;
	int size_;

	void add(Node* node, int number);
	bool search(Node* node, int number);
	int getHeightOfNode(Node* node);
	void getLeafsOfNode(std::vector<int>& leafs , Node* node);
};