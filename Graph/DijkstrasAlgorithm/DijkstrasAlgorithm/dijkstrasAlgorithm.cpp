#include "dijkstrasAlgorithm.h"

int DijkstrasAlgorithm::getMinDistance(int vertexFrom, int vertexTo , const std::vector<std::vector<int>>& graphMatrix)
{
	init(vertexFrom, vertexTo , graphMatrix.size());

	for (int vertexIndex = getTargetVertex(); vertexIndex != -1; vertexIndex = getTargetVertex())
	{
		trySetNewMinPath(vertexIndex , graphMatrix);

		visitedVertices_[vertexIndex] = true;
	}

	return (minDistanceToEveryVertex_[vertexTo] == INT_MAX) ? -1 : minDistanceToEveryVertex_[vertexTo];
}

void DijkstrasAlgorithm::init(int& vertexFrom , int& vertexTo , int vertices)
{
	minDistanceToEveryVertex_ = std::vector<int>(vertices, INT_MAX);
	visitedVertices_ = std::vector<bool>(vertices, false);
	vertices_ = vertices;

	vertexFrom--;
	vertexTo--;

	minDistanceToEveryVertex_[vertexFrom] = 0;
}

int DijkstrasAlgorithm::getTargetVertex()
{
	int targetVertexIndex = -1;

	for (int i = 0, min = INT_MAX; i < vertices_; i++)
	{
		if ((visitedVertices_[i] == false) && (minDistanceToEveryVertex_[i] < min))
		{
			min = minDistanceToEveryVertex_[i];
			targetVertexIndex = i;
		}
	}

	return targetVertexIndex;
}

void DijkstrasAlgorithm::trySetNewMinPath(int vertexFrom , const std::vector<std::vector<int>>& graphMatrix)
{
	for (int i = 0, distanceToNewVertex; i < vertices_; i++)
	{
		if (graphMatrix[vertexFrom][i] > 0)
		{
			distanceToNewVertex = minDistanceToEveryVertex_[vertexFrom] + graphMatrix[vertexFrom][i];

			if (distanceToNewVertex < minDistanceToEveryVertex_[i])
			{
				minDistanceToEveryVertex_[i] = distanceToNewVertex;
			}
		}
	}
}
