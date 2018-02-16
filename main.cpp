#include <iostream>
#include <bits/stdc++.h>
#include "Graph.h"
#include "Partition.h"
#include "DValue.h"
using namespace std;

void swap(vector<int> &partition1, vector<int> &partition2, int pos1, int pos2)
{
	int temp = partition1[pos1];
	partition1[pos1] = partition2[pos2];
	partition2[pos2] = temp;
}

void KLAlgo(map< pair<int, int>, int> &edgeSet, vector<int> &ans, vector<int> &permanent_lock, vector<int> &D, int K1, int nodes, int inodes)
{	
	int i, j, k;
	int s1 = inodes-(inodes/K1), s2 = inodes/K1;
	vector<int> partition1, partition2;
	vector<int> lock(nodes, false);		
	Partition p(nodes);
	DValue objD(nodes);

	p.partition(partition1, partition2, s1, s2, permanent_lock);
	objD.initializeDValue(D);
	objD.findDValue(D, edgeSet, partition1, partition2);

	int g, ig;
	int pnode1, pnode2;
	vector<int> gval;
	vector<int> pos1, pos2;
	bool gfound;
	int c;
	for( k=0; k < s2/2; ++k)
	{
		gfound=false;
		for(i=0; i<partition1.size(); ++i)
		{
			for(j=0; j<partition2.size(); ++j)
			{
				if(lock[partition1[i]]==false && lock[partition2[j]]==false)
				{
					if(edgeSet.find(make_pair(partition1[i], partition2[j])) != edgeSet.end())
						c = edgeSet[make_pair(partition1[i], partition2[j])];
					else if(edgeSet.find(make_pair(partition2[j], partition1[i])) != edgeSet.end())
						c = edgeSet[make_pair(partition2[j], partition1[i])];
					else
						c=0;
							
					if(gfound == false)
					{
						g = D[partition1[i]] + D[partition2[j]] - 2*(c);
						
						pnode1 = i;
						pnode2 = j;
						gfound = true;
 					}
 					else
 					{
 						ig = D[partition1[i]] + D[partition2[j]] - 2*(c);
 						
 						if(ig>g)
 						{
 							g = ig;
							pnode1 = i;
							pnode2 = j;
						}
					}
				}
			}
		}
		
		lock[ partition1[pnode1] ] = true;
		pos1.push_back(pnode1);
		
		pos2.push_back(pnode2);
		lock[ partition2[pnode2] ] = true;
			
		gval.push_back(g);

		objD.changeDValue(D, edgeSet, partition1[pnode1], partition2[pnode2], partition1, partition2);
	}
	
	int maxg=gval[0], imaxg=gval[0], K=1;
	for( i=1; i < gval.size(); ++i)
	{
		imaxg = imaxg+gval[i];
		if(imaxg>maxg)
		{
			maxg = imaxg;
			K = i;
		}
	}
		
	if(maxg<0 && K==1)
		K = -1;
		
	for(i=0;i<K;++i)
	{
		swap(partition1, partition2, pos1[i], pos2[i]);
	}
	
	if((K1-1) == 1)
	{
		for(i = 0; i < partition1.size(); ++i)
		{
			ans.push_back(partition1[i]);
			permanent_lock[partition1[i]]=1;
		}
		ans.push_back(-1);
	}

	for(i=0;i<partition2.size();++i)
	{
		ans.push_back(partition2[i]);
		permanent_lock[partition2[i]]=1;
	}
	ans.push_back(-1);
}

int main()
{
	int nodes, i, j, k, K1, start_s, stop_s, inodes;
	cout<<"Enter the partitions in which the graph should be divided ";
	cin>>K1;

	map< pair<int, int>, int> edgeSet;
	vector<int> ans;

	Graph graph; 
	nodes = graph.Nodes(); 
	inodes = nodes;
	graph.buildEdgeSet(edgeSet);

	vector<int> permanent_lock(nodes, false);
	vector<int> D(nodes, 0);
	
	start_s = clock();
	if(nodes == K1)
	{
		cout<<"Given graph is already divided into "<<K1<<" partitions"<<endl;
	}
	else
	{
		while(K1 != 1)
		{
			KLAlgo(edgeSet, ans, permanent_lock, D, K1, nodes, inodes);
			inodes = inodes - (inodes/K1);
			--K1;
		}
		
		/*
		cout<<endl<<"The partitions are separated by newline"<<endl;
		for (i = 0; i < ans.size(); i++)
		{ 
	    	if(ans[i]!=-1)
	    		cout<<ans[i]<<" ";
	    	else
	    		cout<<endl;
		}
		*/
	}
	stop_s = clock();
	cout << "time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) <<" seconds" endl;
	
	return 0;
}
