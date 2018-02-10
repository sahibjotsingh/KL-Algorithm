#ifndef DVALUE_H
#define DVALUE_H
#include <bits/stdc++.h>
using namespace std;

class DValue
{
	int nodes;
	public:
		DValue(int nodes);
		void findDValue(vector<int> &D, map< pair<int, int>, int> &edgeSet, vector<int> &partition1, vector<int> &partition2);
		int container(int node, vector<int> &partition1, vector<int> &partition2);
		void initializeDValue(vector<int> &D);
		void changeDValue(vector<int> &D, map< pair<int, int>, int> &edgeSet, int a, int b, vector<int> &partition1, vector<int> &partition2);
};

#endif
