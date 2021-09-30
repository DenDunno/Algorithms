#include "graph.h"
#include <iostream>
#include <algorithm>

int Graph::getBalance(int vertexFrom, int vertexTo)
{
	return graphMatrix_[vertexFrom][vertexTo];
}

int Graph::dijkstrasAlgorithm(int vertexFrom, int vertexTo) 
{
    return dijkstrasAlgorithm_.getMinDistance(vertexFrom, vertexTo , graphMatrix_);
}

void Graph::depthFirstSearch(int vertexFrom)
{
	depthFirstSearch_.search(vertexFrom , edgesList_);
}