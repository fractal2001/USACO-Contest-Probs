/*
USACO 2019 December Contest, Bronze
Problem 1. Cow Gymnastics
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

bool isSame(vector<bool> X){
	bool f = X[0];
	for (int i=1; i<X.size(); i++){
		if (X[i] != f){
			return false;
		}
	}
	return true;
}

int main(){
	ifstream fin ("gymnastics.in");
	ofstream fout ("gymnastics.out");
	int K, N; fin >> K >> N;
	vector<vector<int>> ranks;
	for (int i=0; i<K; i++){
		vector<int> iRank;
		for (int i=0; i<N; i++){
			int cow; fin >> cow; iRank.push_back(cow);
		}
		ranks.push_back(iRank);
	}
	int cnt = 0;
	for (int i=1; i<=N; i++){
		for (int j = i+1; j <= N; j++){
			vector<bool> consistent;
			for (auto const&v:ranks){
				int iInd = distance(v.begin(), find(v.begin(), v.end(), i));
				int jInd = distance(v.begin(), find(v.begin(), v.end(), j));
				consistent.push_back(iInd > jInd);
			}
			if (isSame(consistent)){
				cnt ++;
			}
		}
	}
	fout << cnt;
}
