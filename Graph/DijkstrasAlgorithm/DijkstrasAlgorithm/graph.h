#pragma once
#include <istream>
#include <vector>
#include "dijkstrasAlgorithm.h"

class Graph
{
public:

	Graph(int vertices);

	int getMinDistance(int vertexFrom, int vertexTo);

private:

	int vertices_;
	std::vector<std::vector<int>> graphMatrix_;

	DijkstrasAlgorithm dijkstrasAlgorithm_;

	friend std::istream& operator>>(std::istream& is, Graph& graph);
};