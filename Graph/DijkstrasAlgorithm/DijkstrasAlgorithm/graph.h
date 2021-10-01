#pragma once
#include "dijkstrasAlgorithm.h"
#include "depthFirstSearch.h"

class Graph
{
public:

	void readGraphByMatrix();
	void readGraphByListOfEdges();

	int getBalance(int vertexFrom, int vertexTo);

	int dijkstrasAlgorithm(int vertexFrom, int vertexTo);
	void depthFirstSearch(int vertexFrom);

	bool checkIfGraphConnected();

private:

	int vertices_;
	int edges_;
	std::vector<std::vector<int>> graphMatrix_;
	std::vector<std::pair<int, int>> edgesList_;

	DepthFirstSearch depthFirstSearch_;
	DijkstrasAlgorithm dijkstrasAlgorithm_;

	void readVerticesAndEdges();
};