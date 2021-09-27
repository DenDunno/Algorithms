#include "graph.h"
#include <iostream>
using namespace std;

vector<Edge> getTree(Graph& graph)
{
	vector<Edge> answer;
	return answer;
}

int main()
{
	Graph graph;

	cin >> graph;

	for (auto const& edge : getTree(graph))
	{
		cout << edge.VertexFrom << " " << edge.VertexTo << endl;
	}
}