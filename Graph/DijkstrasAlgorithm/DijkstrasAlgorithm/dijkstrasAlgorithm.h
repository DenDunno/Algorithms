#pragma once
#include <vector>

class DijkstrasAlgorithm
{
public:

	int getMinDistance(int vertexFrom, int vertexTo, const std::vector<std::vector<int>>& graphMatrix);

private:

	int vertices_;
	std::vector<int> minDistanceToEveryVertex_;
	std::vector<bool> visitedVertices_;

	void init(int& vertexFrom , int& vertexTo , int size);
	int getTargetVertex();
	void trySetNewMinPath(int vertexFrom , const std::vector<std::vector<int>>& graphMatrix);
};