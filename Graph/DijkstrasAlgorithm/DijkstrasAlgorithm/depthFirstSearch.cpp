#include "depthFirstSearch.h"
#include<iostream>

void DepthFirstSearch::search(int vertexFrom , std::vector<std::pair<int, int>> edges)
{	
	visitedVertices_[vertexFrom] = true;
	vertexStack_.push(vertexFrom);
	std::cout << vertexFrom << " ";

	auto newVertex = std::find_if(edges.begin(), edges.end(), [&](std::pair<int , int> const& edge)
	{
		auto checkNode = [&](int vertexTo)
		{
			return vertexTo == vertexFrom && visitedVertices_[vertexFrom];
		};

		return edge.first == vertexFrom || edge.second == vertexFrom && 
	});
}
