// https://usaco.org/index.php?page=viewproblem2&cpid=574

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
    ifstream fin("feast.in");
    ofstream fout("feast.out");

    int T, A, B;
    fin >> T >> A >> B;

    bool arr[T+1];
    arr[0] = true;

    for (int i=1; i < T+1; i++) {
        int lemon = i - A;
        int orange = i - B;
        
        if (lemon >= 0 && orange >= 0) {
            arr[i] = arr[lemon] || arr[orange];
        } else if (lemon < 0 && orange >= 0) {
            arr[i] = arr[orange];
        } else if (lemon >= 0 && orange < 0) {
            arr[i] = arr[lemon];
        } else {
            arr[i] = false ;
        }
    }
    // if possible, slash by two since they can drink water and that's possible 
    for (int i=1; i < T+1; i++) {
        // if they drink water
        int j = i >> 1; 
        if (arr[i]) arr[j] = true; 
    }

    // recompute the DP stuff and see if any impossible becomes possible 
    for (int i=1; i < T+1; i++) {
        int lemon = i - A;
        int orange = i - B;
        if (arr[i] == false) {
            if (lemon >= 0 && orange >= 0) {
                arr[i] = arr[lemon] || arr[orange];
            } else if (lemon < 0 && orange >= 0) {
                arr[i] = arr[orange];
            } else if (lemon >= 0 && orange < 0) {
                arr[i] = arr[lemon];
            } else {
                arr[i] = false ;
            }
        }
        
    }
    int bestPossible; 
    for (int i=T; i>= 0; i--) {
        if (arr[i]) {
            bestPossible = i;
            break; 
        }
    }

    fout << bestPossible; 
}
