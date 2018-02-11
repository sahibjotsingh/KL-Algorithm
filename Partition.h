#ifndef PARTITION_H
#define PARTITION_H
#include <bits/stdc++.h>
using namespace std;

class Partition
{
	int nodes;
	public:
		Partition(int nodes);
		void partition(vector<int> &partition1, vector<int> &partition2, int s1, int s2, vector<int> &permanent_lock);
};

#endif
