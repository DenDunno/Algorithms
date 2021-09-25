#include <iostream>
#include "binaryTree.h"

using namespace std;

void fillBinaryTree(BinaryTree& binaryTree);

int main()
{	
	BinaryTree binaryTree;

	fillBinaryTree(binaryTree);

	cout << binaryTree.size() << endl;
	cout << binaryTree.getHeightOfBinaryTree() << endl;
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