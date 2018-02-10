#ifndef KL_H
#define KL_H
#include <bits/stdc++.h>
using namespace std;

class KL
{
	public:
		void KLAlgo(map< pair<int, int>, int> &edgeSet, vector<vector<int> > &partitions, vector<bool> &permanent_lock, vector<int> &D, int K1, int nodes);
		void swap(vector<int> &partition1, vector<int> &partition2, int pos1, int pos2);
};

#endif
