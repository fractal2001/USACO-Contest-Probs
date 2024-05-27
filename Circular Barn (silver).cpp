//https://usaco.org/index.php?page=viewproblem2&cpid=618

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <numeric>
using namespace std;



int main(){
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");

    int N; fin >> N;
    int arr[N]; 
    for (int i=0; i<N; i++) {
        int k; fin >> k; arr[i] = k; 
    }

    int bestSum = INT_MAX; 
    for (int shift = 0; shift < N; shift ++) {
        int sum = 0; 
        int firstCowIsAt = shift; 
        for (int i=0; i < N; i++) {
            int numCows = arr[i]; 
            for (int cow =0; cow < numCows; cow++) {
                sum += (firstCowIsAt >= i) ? (firstCowIsAt - i)*(firstCowIsAt - i) : (N + firstCowIsAt - i)*(N + firstCowIsAt - i); 
                firstCowIsAt = (firstCowIsAt + 1) % N; 
            }
        }
        bestSum = min(bestSum, sum);
    }
    fout << bestSum; 
}
