/*
USACO 2018 US Open Contest, Silver
Problem 2. Lemonade Line
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

bool compare(int a, int b){
    if (a < b) { return false; }
    return true; 
}

int main(){
	ifstream fin ("lemonade.in");
	ofstream fout ("lemonade.out");
	int N;
	fin >> N;
	int waitTimes[N];
	for (int i=0; i<N; i++){
	    int t; fin >> t; waitTimes[i] = t;
	}
	sort(waitTimes, waitTimes+N, greater<int>());
	for (auto const&c:waitTimes){
	    cout << c << endl;
	}
	int minLem = 0;
	for (int i=0; i < N; i++){
	    if (waitTimes[i] >= i){ minLem ++; }
	}
	fout << minLem;
}
