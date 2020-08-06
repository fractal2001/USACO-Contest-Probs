/*
USACO 2015 December Contest, Silver
Problem 3. Breed Counting
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> sub3(vector<int> A, vector<int> B){
    vector<int> C;
    for (int i=0; i<3; i++){
        C.push_back(A[i]-B[i]);
    }
    return C;
}

int main(){
    ifstream fin ("bcount.in");
    ofstream fout ("bcount.out");
    int N, Q; fin >> N >> Q;
    int cows[N];
    vector< vector<int> > prefix;
    for (int i=0; i<N; i++){
        int id; fin >> id; cows[i] = id;
    }
    prefix.push_back({0,0,0});
    for (int i=0; i< N; i++){
        if (cows[i] == 1){
            vector<int> back = prefix.back();
            back[0] += 1;
            prefix.push_back(back);
        }
        else if (cows[i] == 2){
            vector<int> back = prefix.back();
            back[1] += 1;
            prefix.push_back(back);
        }
        else {
            vector<int> back = prefix.back();
            back[2] += 1;
            prefix.push_back(back);
        }
    }
    for (int i=0; i<Q; i++){
        int a,b; fin >> a >> b;
        vector<int> query = sub3(prefix[b], prefix[a-1]);
        fout << query[0] << " " << query[1] << " " << query[2] << endl;
    }
    //fout << endl;
}
