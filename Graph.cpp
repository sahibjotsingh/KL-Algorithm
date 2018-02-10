#include "Graph.h"
#include <bits/stdc++.h>

void Graph::buildEdgeSet(map< pair<int, int>, int> &E)
{
	int i, edges, flag=0;
	
  	ifstream is1("from.txt");
  	istream_iterator<int> start1(is1), end1;
  	vector<int> initialNode(start1, end1);
  	
	ifstream is2("to.txt");
  	istream_iterator<int> start2(is2), end2;
  	vector<int> finalNode(start2, end2);

  	ifstream is3("weight.txt");
  	istream_iterator<int> start3(is3), end3;
  	vector<int> weight(start3, end3);
  	
  	edges=initialNode.size();
  	for(i=0;i<edges;++i)
  	{
  		E[make_pair(initialNode[i], finalNode[i])]=weight[i];
	}
}

int Graph::Nodes()
{
	int nodes;
	ifstream is4("vertices.txt");
	is4>>nodes;
	return nodes;
}
