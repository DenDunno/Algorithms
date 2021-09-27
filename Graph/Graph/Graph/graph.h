#pragma once
#include "edge.h"
#include <vector>
#include <istream>

class Graph
{
private:

	int numOfVertices_;
	int numOfEdges_;
	std::vector<Edge> edges_;

public:

	int NumOfVertices() { return numOfVertices_; }
	int NumOfEdges() { return numOfEdges_; }
	std::vector<Edge>& Edges_() { return edges_; }

	friend std::istream& operator>>(std::istream& is, Graph& graph);
};