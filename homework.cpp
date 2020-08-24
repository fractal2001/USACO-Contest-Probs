/*
USACO 2017 December Contest, Silver
Problem 1. My Cow Ate My Homework
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main(){
    ifstream fin ("homework.in");
    ofstream fout ("homework.out");
    int N; fin >> N;
    int array[N];
    for (int i=0; i<N; i++){
        int x; fin >> x; array[i] = x;
    }
    int minPrefix[N-2];
    minPrefix[N-3] = min(array[N-1], array[N-2]);
    for (int i = N-4; i>-1; i--){
        minPrefix[i] = min(minPrefix[i+1], array[i+1]);
    }
    for (auto const&c:minPrefix){
        cout << c << endl;
    }
    int suffixSum[N-2];
    suffixSum[N-3] = array[N-1]+array[N-2];
    for (int i=N-4; i>-1; i--){
        suffixSum[i] = suffixSum[i+1] + array[i+1];
    }
    map<double,vector<int>> collection;
    for (int i=N-3; i>-1; i--){
        double numerator = suffixSum[i]-minPrefix[i];
        double denom = N-2-i;
        double x = numerator/denom;
        collection[x].push_back(i+1);
    }
    vector<int> indexes = collection.rbegin()->second;
    //sort(indexes.begin(), indexes.end());
    for (int i = indexes.size()-1; i>-1; i--){
        fout << indexes[i] << endl;
    }
}
