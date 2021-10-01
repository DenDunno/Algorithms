#pragma once
#include<vector>
#include<stack>

class DepthFirstSearch
{
public:

	void init(int edgesCount);
	void search(int vertexFrom, const std::vector<std::pair<int, int>>& edges);
	bool checkIfGraphConnected(const std::vector<std::pair<int, int>>& edges);

private:

	std::vector<int> visitedVertices_;
	std::stack<int> vertexStack_;

	bool graphIsConnected_;

	void enterNode(int vertexFrom);
	void addNodesToVisit(int vertexFrom , const std::vector<std::pair<int, int>>& edges);
	void visitNodes(const std::vector<std::pair<int, int>>& edges);
};