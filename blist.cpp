/*
USACO 2018 December Contest, Bronze
Problem 2. The Bucket List
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

int main(){
	ifstream fin ("blist.in");
	ofstream fout ("blist.out");
	int N; fin >> N;
	vector<tuple<int,int,int>> line;
	for (int i=0; i<N; i++){
		int s,t,b; fin >> s >> t >> b;
		line.push_back(make_tuple(s,t,b));

	}
	int maxBuck = 0;
	for (int t=1; t<=1000; t++){
		int numBuckets = 0;
		for (auto const&c:line){
			if (get<0>(c) <= t && t<=get<1>(c)){
				numBuckets += get<2>(c);
			}
		}
		maxBuck = max(maxBuck,numBuckets);
	}
	fout << maxBuck;
}
