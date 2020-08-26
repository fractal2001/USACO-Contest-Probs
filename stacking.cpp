/*
USACO 2012 January Contest, Bronze Division
Problem 2. Haybale Stacking
https://www.spoj.com/problems/HAYBALE/
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main(){
    int N; cin >> N;
    int arr[N+1] = {};
    int K; cin >> K;
    for (int i=0; i<K; i++){
        int A, B; cin >> A >> B;
        arr[A-1] += 1;
        arr[B] += -1;
    }
    int prefix[N];
    prefix[0] = arr[0];
    for (int i=1; i<N; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    //for (int i=0; i<N; i++){
    //    cout << prefix[i] << " ";
    //}
    sort(prefix, prefix+N);
    cout << prefix[(N-1)/2] << endl;
}
