#include "KL.h"
#include <bits/stdc++.h>
using namespace std;

void KL::swap(vector<int> &partition1, vector<int> &partition2, int pos1, int pos2)
{
	int temp = partition1[pos1];
	partition1[pos1] = partition2[pos2];
	partition2[pos2] = temp;
}

void KL::KLAlgo(map< pair<int, int>, int> &edgeSet, vector<vector<int> > &partitions, vector<bool> &permanent_lock, vector<int> &D, int K1, int nodes)
{
	if(K1==1)
		return;
	Partition p(nodes);
	DValue objD(nodes);
	
	int i, j, k;
	int s1=nodes-(nodes/K1), s2=nodes/K1;
	vector<int> partition1, partition2;
	vector<bool> lock(nodes, false);
	p.partition(partition1, partition2, s1, s2, permanent_lock);
	objD.initializeDValue(D);
	objD.findDValue(D, edgeSet, partition1, partition2);
	
	/***********
	for(i=0;i<partition1.size();++i)
	{
		cout<<partition1[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<partition2.size();++i)
	{
		cout<<partition2[i]<<" ";
	}
	cout<<endl<<"********************"<<endl;
	**************/
	
	int g, ig;
	int pnode1, pnode2;
	vector<int> gcontainer, gval;
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
			
			lock[partition1[pnode1]] = true;
			pos1.push_back(pnode1);
			
			pos2.push_back(pnode2);
			lock[partition2[pnode2]] = true;
			
			//swap(partition1, partition2, pnode1, pnode2);
			gval.push_back(g);
			
			objD.changeDValue(D, edgeSet, partition1[pnode1], partition2[pnode2], partition1, partition2);
		}
		
		int maxg=gval[0], imaxg=gval[0], K=0;
		//bool gotmaxg=false;
		for(i=1;i<gval.size();++i)
		{
			imaxg=imaxg+gval[i];
			if(imaxg>maxg)
			{
				maxg=imaxg;
				K=i;
			}
		}
		//cout<<endl<<endl<<K<<endl;
		
		if(maxg<0 && K==0)
			K=-1;
		
		for(i=0;i<K;++i)
		{
			swap(partition1, partition2, pos1[i], pos2[i]);
		}
		if((K1-1) == 1)
		{
			for(i=0;i<partition1.size();++i)
			{
				cout<<partition1[i]<<" ";
				ans.push_back(partition1[i]);
			}
			ans.push_back(-1);
			cout<<endl<<"********************"<<endl;
		}
		for(i=0;i<partition2.size();++i)
		{
			cout<<partition2[i]<<" ";
			ans.push_back(partition2[i]);
		}
		ans.push_back(-1);
		cout<<endl<<"********************"<<endl;
		KL(edgeSet, partitions, permanent_lock, D, K1-1, s1);
}
