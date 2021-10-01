#include "depthFirstSearch.h"
#include<iostream>
#include <algorithm>

void DepthFirstSearch::init(int edgesCount)
{
	graphIsConnected_ = true;
	visitedVertices_.resize(edgesCount , false);
}

void DepthFirstSearch::search(int vertexFrom , const std::vector<std::pair<int, int>>& edges)
{
	if (visitedVertices_[vertexFrom - 1] == true)
		return;
	
	enterNode(vertexFrom);
	addNodesToVisit(vertexFrom, edges);
	visitNodes(edges);
}

bool DepthFirstSearch::checkIfGraphConnected(const std::vector<std::pair<int, int>>& edges)
{
	search(1, edges);

	return graphIsConnected_;
}

void DepthFirstSearch::enterNode(int vertexFrom)
{
	visitedVertices_[vertexFrom - 1] = true;
}

void DepthFirstSearch::addNodesToVisit(int vertexFrom , const std::vector<std::pair<int, int>>& edges)
{
	for (int i = 0; i < edges.size(); ++i)
	{
		if (edges[i].first == vertexFrom || edges[i].second == vertexFrom)
		{
			int vertexToBeVisited = (edges[i].first == vertexFrom) ? edges[i].second : edges[i].first;

			if (visitedVertices_[vertexToBeVisited - 1] == false)
			{
				vertexStack_.push(vertexToBeVisited);
			}
		}
	}
}

void DepthFirstSearch::visitNodes(const std::vector<std::pair<int, int>>& edges)
{
	while (vertexStack_.empty() == false)
	{
		int vertexToBeVisited = vertexStack_.top();
		vertexStack_.pop();

		search(vertexToBeVisited, edges);
	}

	auto nonVisitedNode = std::find_if(visitedVertices_.begin(), visitedVertices_.end(), [](auto& const node)
	{
		return node == false;
	});

	if (nonVisitedNode != visitedVertices_.end())
	{
		graphIsConnected_ = false;
		search(nonVisitedNode - visitedVertices_.begin() + 1, edges);
	}
}
