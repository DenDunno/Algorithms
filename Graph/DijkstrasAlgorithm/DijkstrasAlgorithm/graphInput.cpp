#include "graph.h"
#include <iostream>

void Graph::readGraphByMatrix()
{
	readVerticesAndEdges();
	graphMatrix_.resize(vertices_, std::vector<int>(vertices_));

	for (size_t i = 0; i < vertices_; ++i)
	{
		for (size_t j = 0; j < vertices_; ++j)
		{
			std::cin >> graphMatrix_[i][j];
		}
	}
}

void Graph::readGraphByListOfEdges()
{
	readVerticesAndEdges();
	edgesList_.resize(edges_);

	for (size_t i = 0; i < edges_; ++i)
	{
		std::cin >> edgesList_[i].first >> edgesList_[i].second;
	}
}

void Graph::readVerticesAndEdges()
{
	std::cin >> vertices_;
	std::cin >> edges_;
}