#include <iostream>
#include <vector>
#include<climits>
#include "graph.h"
using namespace std;

int main()
{
	Graph graph;

	graph.readGraphByListOfEdges();

	graph.depthFirstSearch(3);
}