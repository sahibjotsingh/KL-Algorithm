#include "DValue.h"
#include <bits/stdc++.h>

DValue::DValue(int nodes)
{
	this->nodes = nodes;
}

void DValue::initializeDValue(vector<int> &D)
{
	int i;
	for(i=0;i<nodes;++i)
	{
		D[i]=0;
	}
}

void DValue::findDValue(vector<int> &D, map< pair<int, int>, int> &edgeSet, vector<int> &partition1, vector<int> &partition2)
{
  	pair<int, int> p;
  	int node1, node2;
  	int container_node1, container_node2;
  	int edgeWeight;
  	
  	for(map< pair<int, int>, int>::iterator it=edgeSet.begin();it!=edgeSet.end();it++)
  	{
  		p = it->first;
  		edgeWeight = it->second;

  		node1 = p.first;
  		container_node1 = container(node1, partition1, partition2);

  		node2 = p.second;
		container_node2 = container(node2, partition1, partition2);

		if(container_node1 == container_node2)
		{
			D[node1] = D[node1] - edgeWeight;
			D[node2] = D[node2] - edgeWeight;
		}
  		else
  		{
  			D[node1] = D[node1] + edgeWeight;
  			D[node2] = D[node2] + edgeWeight;
		}
	}
}

int DValue::container(int node, vector<int> &partition1, vector<int> &partition2)
{
	if (find(partition1.begin(), partition1.end(), node) != partition1.end() )
		return 1;
	else
		return 2;
}

void DValue::changeDValue(vector<int> &D, map< pair<int, int>, int> &edgeSet, int a, int b, vector<int> &partition1, vector<int> &partition2)
{
	int i, c1, c2, x, y;
	for(i=0;i<partition1.size();++i)
	{
		x=partition1[i];

		if(x != a && x != b)
		{
			if(edgeSet.find(make_pair(x, a)) != edgeSet.end())
				c1 = edgeSet[make_pair(x, a)];
			else if(edgeSet.find(make_pair(a, x)) != edgeSet.end())
				c1 = edgeSet[make_pair(a, x)];
			else
				c1 = 0;
			
			if(edgeSet.find(make_pair(x, b)) != edgeSet.end())
				c2 = edgeSet[make_pair(x, b)];
			else if(edgeSet.find(make_pair(b, x)) != edgeSet.end())
				c2 = edgeSet[make_pair(b, x)];
			else
				c2 = 0;
			
			D[x] = D[x] + 2*c1 - 2*c2;				
		}
	}
	
	for(i=0; i < partition2.size(); ++i)
	{
		y = partition2[i];
		
		if(y != a && y != b)
		{
			if(edgeSet.find(make_pair(y, a)) != edgeSet.end())
				c1 = edgeSet[make_pair(y, a)];
			else if(edgeSet.find(make_pair(a, y)) != edgeSet.end())
				c1 = edgeSet[make_pair(a, y)];
			else
				c1 = 0;
			
			if(edgeSet.find(make_pair(y, b)) != edgeSet.end())
				c2 = edgeSet[make_pair(y, b)];
			else if(edgeSet.find(make_pair(b, y)) != edgeSet.end())
				c2 = edgeSet[make_pair(b, y)];
			else
				c2 = 0;
			
			D[y] = D[y] + 2*c2 - 2*c1;				
		}
	}
}
