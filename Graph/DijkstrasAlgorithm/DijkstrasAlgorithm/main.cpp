#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int evaluateMinPath(vector<int>& balances, vector<pair<int, int>>& edges);
void readGraph(vector<int>& balances, vector<pair<int, int>>& edges);

int main()
{
	vector<int> balances;
	vector<pair<int , int>> edges;

	readGraph(balances, edges);

	cout << evaluateMinPath(balances, edges) << endl;
}

void readGraph(vector<int>& balances, vector<pair<int, int>>& edges)
{
	int balancesSize;
	int edgesSize;

	cin >> balancesSize;
	balances.resize(balancesSize);

	for (int i = 0; i < balancesSize; ++i)
	{
		cin >> balances[i];
	}

	cin >> edgesSize;
	edges.resize(edgesSize);

	for (int i = 0; i < edgesSize; ++i)
	{
		cin >> edges[i].first;
		cin >> edges[i].second;
	}
}

int evaluateMinPath(vector<int>& balances, vector<pair<int, int>>& edges)
{	
	vector<int> minDistanceToEveryVertex(balances.size() , INT_MAX);
	vector<bool> visitedVertices(balances.size() , false);

	minDistanceToEveryVertex[0] = 0;
	int targetIndex = -1;

	do
	{
		targetIndex = -1;

		for (int i = 0, min = INT_MAX; i < minDistanceToEveryVertex.size(); ++i)
		{
			if (min > minDistanceToEveryVertex[i] && visitedVertices[i] == false)
			{
				min = minDistanceToEveryVertex[i];
				targetIndex = i;
			}
		}

		for (int i = 0; i < edges.size(); ++i)
		{
			if (edges[i].first == targetIndex + 1 || edges[i].second == targetIndex + 1)
			{
				int newVertexIndex = (edges[i].first == targetIndex + 1 ? edges[i].second : edges[i].first) - 1;

				if (visitedVertices[newVertexIndex] == true)
					continue;

				int distanceToNewVertex = minDistanceToEveryVertex[targetIndex] + balances[targetIndex];

				if (distanceToNewVertex < minDistanceToEveryVertex[newVertexIndex])
				{
					minDistanceToEveryVertex[newVertexIndex] = distanceToNewVertex;
				}
			}
		}

		if (targetIndex != -1)
		{
			visitedVertices[targetIndex] = true;
		}
			
	} while (targetIndex != -1);

	int answer = *(minDistanceToEveryVertex.end() - 1);

	if (answer == INT_MAX)
	{
		answer = -1;
	}
		
	return answer;
}