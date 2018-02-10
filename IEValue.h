#ifndef IEVALUE_H
#define IEVALUE_H
#include <bits/stdc++.h>
using namespace std;
class IEValue
{
	int nodes;
	public:
		IEValue(int nodes);
		void findIEValue(vector<int> &I, vector<int> &E, map< pair<int, int>, int> &edgeList, vector<int> &l1, vector<int> &l2);
		int container(int node, vector<int> &l1, vector<int> &l2);
		void changeIEValue(vector<int> &D, map< pair<int, int>, int> &edgeSet, int a, int b, vector<int> &l1, vector<int> &l2);
	protected:
};

#endif
