/*
USACO 2019 January Contest, Silver
Problem 3. Mountain View
https://usaco.org/index.php?page=viewproblem2&cpid=896
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

struct Mountain {
    long long left, right; 
};

struct cmp {
	bool operator()(const Mountain &x, const Mountain &y) const { 
        if (x.left != y.left) {
            return x.left < y.left; 
        } else {
            return x.right > y.right; 
        }
    }
};



int main(){
	ifstream fin ("mountains.in");
	ofstream fout ("mountains.out");

    vector<Mountain> intervals; 
    long long N; fin >> N;
    for (long long i=0; i <N; i++) {
        long long x, y; fin >> x >> y; 
        intervals.push_back({x-y, x+y});
    }

    sort(intervals.begin(), intervals.end(), cmp()); 

    long long distinctPeaks = 1;
    Mountain peak; 

    if (intervals.size() == 0) { 
        cout << 0; 
    } else {
        peak = intervals[0];

        for (int i=1; i < intervals.size(); i++) {
            if (!(intervals[i].left >= peak.left && peak.right >= intervals[i].right)) {
                peak = intervals[i]; 
                distinctPeaks++; 
            }
        }
    }
    fout << distinctPeaks; 
}
