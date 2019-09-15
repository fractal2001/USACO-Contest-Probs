/*
USACO 2018 December Contest, Bronze
Problem 3. Back and Forth
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
	ifstream fin ("backforth.in");
	ofstream fout ("backforth.out");
	vector<int> fBarn;
	vector<int> sBarn;
	for (int i=0; i<10; i++){
		int c; fin >> c; fBarn.push_back(c);
	}
	for (int i=0; i<10; i++){
		int c; fin >> c; sBarn.push_back(c);
	}
	set<int> poss = {1000}; //both not swapped
	//if one were swapped
	for (int i=0; i<10; i++){
	    for (int j=0; j<10; j++){
	        poss.insert(1000+sBarn[j]-fBarn[i]);
	    }
	}
	//if there were 2 swaps;
	for (int i=0; i<10; i++){
	    for (int j=0; j<10; j++){
	        int a = fBarn[i];
	        int b = sBarn[j];
	        fBarn[i] = b;
	        sBarn[j] = a;
	        int cur = 1000-a+b;
	        for (int x=0; x<10; x++){
	            for (int y=0; y<10; y++){
	                poss.insert(cur+sBarn[y]-fBarn[x]);
	            }
	        }
	        fBarn[i] = a;
	        sBarn[j] = b;
	    }
	}
	fout << poss.size() << endl;
}
