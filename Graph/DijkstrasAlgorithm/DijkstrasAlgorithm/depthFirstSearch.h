#pragma once
#include<vector>
#include<stack>

class DepthFirstSearch
{
public:

	void search(int vertexFrom, std::vector<std::pair<int, int>> edges);

private:

	std::vector<int> visitedVertices_;
	std::stack<int> vertexStack_;
};