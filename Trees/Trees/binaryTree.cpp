#include "binaryTree.h"
#include<algorithm>

bool BinaryTree::search(Node* node , int number)
{
	Node*& acceptedNode = (number < node->Data) ? node->Left : node->Right;

	if (acceptedNode == nullptr)
	{
		return false;
	}

	else if (acceptedNode->Data == number)
	{
		return true;
	}
		
	else
	{
		return search(acceptedNode, number);
	}
}

int BinaryTree::getHeightOfNode(Node* node)
{
	if (node == nullptr || isRootInited_ == false)
	{
		return 0;
	}

	return 1 + std::max(getHeightOfNode(node->Left), getHeightOfNode(node->Right));
}

void BinaryTree::add(Node* node, int number)
{
	Node*& acceptedNode = (number < node->Data) ? node->Left : node->Right;

	if (acceptedNode != nullptr)
	{
		add(acceptedNode, number);
	}

	else
	{
		acceptedNode = new Node(number);
	}
}