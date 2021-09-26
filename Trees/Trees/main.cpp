#include <iostream>
#include "binaryTree.h"

using namespace std;

void fillBinaryTree(BinaryTree& binaryTree);

int main()
{	
	BinaryTree binaryTree;

	fillBinaryTree(binaryTree);

	for (int const& leaf : binaryTree.getAllLeafs())
	{
		cout << leaf << " ";
	}
}

void fillBinaryTree(BinaryTree& binaryTree)
{
	while (true)
	{
		int number;
		cin >> number;

		if (number == 0)
		{
			break;
		}

		binaryTree.add(number);
	}
}