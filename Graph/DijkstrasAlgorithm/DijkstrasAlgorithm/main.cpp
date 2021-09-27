#include <iostream>
#include "graph.h"

int main()
{
	int vertices;
	int vertexFrom;
	int vertexTo;

	std::cin >> vertices;
	std::cin >> vertexFrom;
	std::cin >> vertexTo;

	Graph graph(vertices);

	std::cin >> graph;

	std::cout << graph.getMinDistance(vertexFrom, vertexTo) << std::endl;
}