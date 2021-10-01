#include <iostream>
#include <vector>
#include<stack>
#include<algorithm>
using namespace std;

void checkIfGraphConnected(int vertexFrom);
void addNodesToVisit(int vertexFrom);
void visitNodes();

vector<bool> visitedVertices;
vector<std::pair<int, int>> edgesList;
stack<int> vertexStack;

int vertices;
int edges;
bool graphIsConnected = true;

int main()
{
	cin >> vertices;
	cin >> edges;

	edgesList.resize(edges);
	visitedVertices.resize(vertices);

	for (size_t i = 0; i < edges; ++i)
	{
		std::cin >> edgesList[i].first >> edgesList[i].second;
	}

	checkIfGraphConnected(1);

	cout << (graphIsConnected ? "YES" : "NO") << endl;
}


void checkIfGraphConnected(int vertexFrom)
{
	if (visitedVertices[vertexFrom - 1] == true)
		return;

	visitedVertices[vertexFrom - 1] = true;

	addNodesToVisit(vertexFrom);
	visitNodes();
}

void addNodesToVisit(int vertexFrom)
{
	for (int i = 0; i < edges; ++i)
	{
		if (edgesList[i].first == vertexFrom || edgesList[i].second == vertexFrom)
		{
			int vertexToBeVisited = (edgesList[i].first == vertexFrom) ? edgesList[i].second : edgesList[i].first;

			if (visitedVertices[vertexToBeVisited - 1] == false)
			{
				vertexStack.push(vertexToBeVisited);
			}
		}
	}
}

void visitNodes()
{
	while (vertexStack.empty() == false)
	{
		int vertexToBeVisited = vertexStack.top();
		vertexStack.pop();

		checkIfGraphConnected(vertexToBeVisited);
	}

	auto nonVisitedNode = find_if(visitedVertices.begin(), visitedVertices.end(), [](auto const node)
	{
		return node == false;
	});

	if (nonVisitedNode != visitedVertices.end())
	{
		graphIsConnected = false;
		checkIfGraphConnected(nonVisitedNode - visitedVertices.begin() + 1);
	}
}