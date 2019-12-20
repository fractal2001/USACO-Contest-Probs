/*
USACO 2019 December Contest, Bronze
Problem 3. Livestock Lineup
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

vector<vector<string>> constraints;

bool checkPerm(vector<string> v){
	for (auto const&c:constraints){
		int firstCow = distance(v.begin(), find(v.begin(), v.end(), c[0]));
		int secCow = distance(v.begin(), find(v.begin(), v.end(), c[1]));
		if (firstCow + 1 != secCow && secCow + 1 != firstCow){
			return false;
		}
	}
	return true;
}

int main(){
	ifstream fin ("lineup.in");
	ofstream fout ("lineup.out");
	int N; fin >> N;
	for (int i=0; i<N; i++){
		vector<string> cons;
		for (int i=0; i<6; i++){
			string S; fin >> S;
			if (i!=1 && i!=2 && i!=3 && i!=4) cons.push_back(S);
		}
		constraints.push_back(cons);
	}
	vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
	do {
    if (checkPerm(cows)){
			for (int i=0; i<8; i++){
				fout << cows[i] << endl;
			}
			break;
		}
  } while ( std::next_permutation(cows.begin(),cows.end()) );
}
