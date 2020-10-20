/*
USACO 2017 February Contest, Silver
Problem 2. Why Did the Cow Cross the Road II
/*

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int main(){
    ifstream fin ("maxcross.in");
    ofstream fout ("maxcross.out");
    int N, K, B;
    fin >> N >> K >> B;
    int lights[N];
    int prefix[N+1];
    for (int i=0; i<N; i++){
        prefix[i] = 0;
        lights[i] = 0;
    }
    prefix[N] = 0;
    //prefix[0] = 0;
    for (int i=0; i<B; i++){
        int id; fin >> id;
        lights[id-1] = 1;
        //prefix[i+1] = prefix[i]+lights[id-1]
    }
    for (int i=0; i<N; i++){
        prefix[i+1] = prefix[i]+lights[i];
    }
    int minLightFix = prefix[K]-prefix[0];
    for (int i=0; i <= N-K; i++){
        minLightFix = min(prefix[i+K] - prefix[i], minLightFix);
    }
    fout << minLightFix;
}
