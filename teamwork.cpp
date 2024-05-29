// https://usaco.org/index.php?page=viewproblem2&cpid=863

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
    ifstream fin("teamwork.in");
    ofstream fout("teamwork.out");

    int N; fin >> N;
    int K; fin >> K; 

    int arr[N+1]; 
    for (int i=0; i<N;i++){
        int x; fin >> x;
        arr[i+1] = x; 
    }

    int dp_array[N+1]; 
    dp_array[0] = 0; 
    for (int i=1; i<=N;i++){ 
        int maxSoFar = arr[i]; 
        int best = INT_MIN; 
        for (int j=1; j<=K; j++) {
            if (i - j >= 0) {
                maxSoFar = max(maxSoFar, arr[i-j+1]); 
                best = max(best, dp_array[i-j] + maxSoFar * j); 
            }
        }
        dp_array[i] = best; 
    }
    // for (auto const&c:dp_array) {
    //     cout << c << endl; 
    // }
    fout << dp_array[N]; 
}
