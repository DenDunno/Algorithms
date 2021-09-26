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

void BinaryTree::getLeafsOfNode(std::vector<int>& leafs , Node* node)
{
	auto isChildNodeEmpty = [&](Node* childNode)
	{
		if (childNode != nullptr)
		{
			getLeafsOfNode(leafs, childNode);
			return false;
		}

		return true;
	};

	if (isChildNodeEmpty(node->Left) & isChildNodeEmpty(node->Right))
	{
		leafs.push_back(node->Data);
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