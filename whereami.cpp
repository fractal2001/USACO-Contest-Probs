/*
USACO 2019 December Contest, Bronze
Problem 2. Where Am I?
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

int N;
string S;

bool checkOK(int K){
	set<string> subs;
	for (int i=0; i<= N-K; i++){
		subs.insert(S.substr(i,K));
	}
	if (subs.size() == N-K+1){
		return true;
	}
	return false;
}

int main(){
	ifstream fin ("whereami.in");
	ofstream fout ("whereami.out");
	fin >> N;
	fin >> S;
	for (int K=1; K <= N; K++){
		if (checkOK(K)){
			fout << K;
			break;
		}
	}
}
