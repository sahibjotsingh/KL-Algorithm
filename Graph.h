#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>
using namespace std;
class Graph
{
	public:
		int Nodes();
		void buildEdgeSet(map< pair<int, int>, int> &E);
};

#endif
