#include "IEValue.h"
#include <bits/stdc++.h>

IEValue::IEValue(int nodes)
{
	this->nodes=nodes;
}

void IEValue::findIEValue(vector<int> &I, vector<int> &E, map< pair<int, int>, int> &edgeList, vector<int> &partition1, vector<int> &partition2)
{
  	pair<int, int> p;
  	int node1, node2;
  	int lnode1, lnode2;
  	int w;
  	for(map< pair<int, int>, int>::iterator it=edgeList.begin();it!=edgeList.end();it++)
  	{
  		p = it->first;
  		w = it->second;
  		node1 = p.first;
  		node2 = p.second;
	 	lnode1 = container(node1, partition1, partition2);
		lnode2 = container(node2, partition1, partition2);
		if(lnode1 == lnode2)
		{
			I[node1]=I[node1]+w;
			I[node2]=I[node2]+w;
		}
  		else
  		{
  			E[node1]=E[node1]+w;
  			E[node2]=E[node2]+w;
		}
	}
}

int IEValue::container(int node, vector<int> &partition1, vector<int> &partition2)
{
	if (find(partition1.begin(), partition1.end(), node) != partition1.end() )
		return 1;
	else
		return 2;
}

void IEValue::changeIEValue(vector<int> &D, map< pair<int, int>, int> &edgeSet, int a, int b, vector<int> &partition1, vector<int> &partition2)
{
	int i, c1, c2, x, y;
	for(i=0;i<partition1.size();++i)
	{
		x=partition1[i];
		if(x!=a && x!=b)
		{
			if(edgeSet.find(make_pair(x, a))!=edgeSet.end())
				c1=edgeSet[make_pair(x, a)];
			else if(edgeSet.find(make_pair(a, x))!=edgeSet.end())
				c1=edgeSet[make_pair(a, x)];
			else
				c1=0;
			
			if(edgeSet.find(make_pair(x, b))!=edgeSet.end())
				c2=edgeSet[make_pair(x, b)];
			else if(edgeSet.find(make_pair(b, x))!=edgeSet.end())
				c2=edgeSet[make_pair(b, x)];
			else
				c2=0;
			
			D[x]=D[x]+2*c1 - 2*c2;				
		}
	}
	for(i=0;i<partition2.size();++i)
	{
		y=partition2[i];
		if(y!=a && y!=b)
		{
			if(edgeSet.find(make_pair(y, a))!=edgeSet.end())
				c1=edgeSet[make_pair(y, a)];
			else if(edgeSet.find(make_pair(a, y))!=edgeSet.end())
				c1=edgeSet[make_pair(a, y)];
			else
				c1=0;
			
			if(edgeSet.find(make_pair(y, b))!=edgeSet.end())
				c2=edgeSet[make_pair(y, b)];
			else if(edgeSet.find(make_pair(b, y))!=edgeSet.end())
				c2=edgeSet[make_pair(b, y)];
			else
				c2=0;
			
			D[y]=D[y]+2*c2 - 2*c1;				
		}
	}
}
