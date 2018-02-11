#include "Partition.h"
#include <bits/stdc++.h>
using namespace std;

Partition::Partition(int nodes)
{
	this->nodes=nodes;
}

void Partition::partition(vector<int> &partition1, vector<int> &partition2, int s1, int s2, vector<int> &permanent_lock)
{
	int i;
	
  	for( i=0; i<nodes; ++i)
	{
		if(permanent_lock[i]==false)
		{
  			if((rand() + i) % 2 == 1) 
  			{
  				if((int )partition1.size() == s1)
		  			partition2.push_back(i);	
				else if((int )partition2.size() == s2)
	  				partition1.push_back(i);
	  			else
	  				partition1.push_back(i);
			}
			else
			{
				if((int )partition1.size() == s1)
		  			partition2.push_back(i);	
		  		else if((int )partition2.size() == s2)
		  			partition1.push_back(i);
		  		else
		  			partition2.push_back(i);
			}
		}
	}
}
