#include "graph.h"
#include <iostream>

std::istream& operator>>(std::istream& is, Graph& graph)
{
	std::cin >> graph.numOfVertices_;
	std::cin >> graph.numOfEdges_;

	for (int i = 0; i < graph.numOfEdges_; ++i)
	{
		Edge edge;
		std::cin >> edge.VertexFrom;
		std::cin >> edge.VertexTo;

		graph.edges_.push_back(edge);
	}

	return is;
}
