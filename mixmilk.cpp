/*
USACO 2018 December Contest, Bronze
Problem 1. Mixing Milk
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
	ifstream fin ("mixmilk.in");
	ofstream fout ("mixmilk.out");
	int cap[3];
	int stat[3];
	for (int i=0; i<3; i++){
		int a,b; fin >> a >> b;
		cap[i] = a; stat[i] = b;
	}
	for (int i = 0; i<33; i++){
		for (int j=0; j<3; j++){
			int n = (j+1)%3;
			if (stat[j]+stat[n] <= cap[n]){
				stat[n] += stat[j];
				stat[j] = 0;
			} else {
				stat[j] += (stat[n]-cap[n]);
				stat[n] = cap[n];
			}
		}
	}
	if (stat[0]+stat[1] <= cap[1]){
		stat[1] += stat[0];
		stat[0] = 0;
	} else {
		stat[0] += (stat[1]-cap[1]);
		stat[1] = cap[1];
	}
	for (auto const&c:stat){
		fout << c << endl;
	}
}
