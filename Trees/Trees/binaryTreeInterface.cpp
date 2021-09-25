#include "binaryTree.h"

BinaryTree::BinaryTree()
{
	root_ = new Node;
	size_ = 0;
	isRootInited_ = false;
}

bool BinaryTree::search(int number)
{
	if (root_->Data == number)
	{
		return true;
	}

	return search(root_, number);
}

int BinaryTree::getHeightOfBinaryTree()
{
	return getHeightOfNode(root_);
}

int BinaryTree::size()
{
	return size_;
}

void BinaryTree::add(int number)
{
	if (search(number) == true)
		return;

	if (isRootInited_ == false)
	{
		isRootInited_ = true;
		root_->Data = number;
	}

	else
	{
		add(root_, number);
	}
	
	++size_;
}