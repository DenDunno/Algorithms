#pragma once

struct Edge
{
	int VertexFrom;
	int VertexTo;

	Edge(int vertexFrom = -1 , int vertexTo = -1)
	{
		VertexFrom = vertexFrom;
		VertexTo = vertexTo;
	}
};