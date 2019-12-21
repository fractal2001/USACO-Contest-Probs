/*
USACO 2018 December Contest, Silver
Problem 3. Mooyo Mooyo
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<vector<int>> state;

int popHay(int r, int c){
	int color = state[r][c];
	int x[4] = {0,0,1,-1};
	int y[4] = {1,-1,0,0};
	vector<int> pos  = {r,c};
	queue<vector<int>> Q; Q.push(pos);
	set<vector<int>> visited; visited.insert(pos);
	while (!Q.empty()){
		vector<int> cur = Q.front(); Q.pop();
		for (int i=0; i<4; i++){
			vector<int> neighbor = {cur[0]+x[i], cur[1]+y[i]};
			if (neighbor[0] >= 0 && neighbor[1] >= 0 && neighbor[0] < N && neighbor[1] < 10){
				if (visited.find(neighbor) == visited.end() && state[neighbor[0]][neighbor[1]] == color){
					Q.push(neighbor);
					visited.insert(neighbor);
				}
			}
		}
	}
	if (visited.size() >= K){
		for (auto const&c:visited){
			state[c[0]][c[1]] = 0;
		}
		return 1;
	} else return 0;
}

vector<vector<int>> collapse(){
	vector<vector<int>> nonZ;
	for (int j=0; j<10; j++){
		vector<int> newCol;
		for (int i=N-1; i>=0; i--){
			int val = state[i][j];
			if (val != 0) newCol.push_back(val);
		}
		for (int i = 0; i<newCol.size(); i++){
			state[N-i-1][j] = newCol[i];
			nonZ.push_back({N-i-1,j});
		}
		for (int i = 0; i< N-newCol.size(); i++){
			state[i][j] = 0;
		}
	}
	return nonZ;
}

int main(){
	ifstream fin ("mooyomooyo.in");
	ofstream fout ("mooyomooyo.out");
	fin >> N >> K;
	for (int i=0; i<N; i++){
		vector<int> row;
		for (int j=0; j<10; j++){
			char c; fin >> c; row.push_back(c-'0');
		}
		state.push_back(row);
	}
	//popHay(5,5);
	vector<vector<int>> nonZero = collapse();
	while (true){
		int progress = 0;
		for (auto const&c:nonZero){
			progress += popHay(c[0],c[1]);
		}
		if (progress > 0) nonZero = collapse();
		else break;
	}
	for (int i=0; i<N; i++){
		for (int j=0; j<10; j++){
			fout << state[i][j];
		}
		fout << endl;
	}
}
