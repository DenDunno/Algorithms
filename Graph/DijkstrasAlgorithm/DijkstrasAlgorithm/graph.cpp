#include "graph.h"
#include <iostream>
#include <algorithm>

Graph::Graph(int vertices) 
{
	vertices_ = vertices;
	graphMatrix_ = std::vector<std::vector<int>>(vertices, std::vector<int>(vertices));
}

int Graph::getMinDistance(int vertexFrom, int vertexTo) 
{
    return dijkstrasAlgorithm_.getMinDistance(vertexFrom, vertexTo , graphMatrix_);
}

int Graph::getBalance(int vertexFrom, int vertexTo)
{
	return graphMatrix_[vertexFrom][vertexTo];
}

std::istream& operator>>(std::istream& is, Graph& graph)
{
	for (size_t i = 0; i < graph.vertices_; ++i)
	{
		for (size_t j = 0; j < graph.vertices_; ++j)
		{
			std::cin >> graph.graphMatrix_[i][j];
		}
	}

	return is;
}
