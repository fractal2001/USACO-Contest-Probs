/*
USACO 2016 January Contest, Silver
Problem 2. Subsequences Summing to Sevens
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ifstream fin ("div7.in");
    ofstream fout ("div7.out");
    int N; fin >> N;
    vector<int> sums7;
    vector<int> cows;
    sums7.push_back(0);
    for (int i=0; i<N; i++){
        int num; fin >> num; cows.push_back(num);
        sums7.push_back((sums7.back()+num)%7);
    }
    string sums;
    for (auto const &c:sums7){
        sums += to_string(c);
    }
    //cout << sums;
    int maximum = 0;
    for (int i=0; i<7; i++){
        auto last = sums.find_last_of(to_string(i));
        auto first = sums.find_first_of(to_string(i));
        if (last == string::npos || first == string::npos){
            continue;
        } else {
            if (last-first > maximum){
                maximum = last-first;
            } 
        }
    }
    fout << maximum;
}
