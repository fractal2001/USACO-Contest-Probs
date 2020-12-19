/*
USACO 2018 January Contest, Silver
Problem 1. Lifeguards
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include<tuple>
#include <map>
using namespace std;
 
#define FOR(i,a,b) for (ll i = a; i < b; i++)
typedef long long ll;
 
vector<tuple<ll,ll,ll>> intervals;

int main(){
    ifstream fin ("lifeguards.in");
    ofstream fout ("lifeguards.out");
    
    ll N; fin >> N;
    FOR(i,0,N){
            ll a,b; fin >> a >> b;
            intervals.push_back(make_tuple(a,1,i));
            intervals.push_back(make_tuple(b,-1,i));
        }
    sort(intervals.begin(), intervals.end());
    ll totalLength = 0;
    ll activeGuards = 0;
    ll start = get<0>(intervals.front());
    ll soloGuard = 0;
    set<ll> currentGuards;
    map<ll,ll> soloTimes;
    FOR(i,0,N){
        soloTimes[i] = 0;
    }
    ll timeSoloStart;
    for (auto const&c:intervals){
        if (activeGuards == 0){
            start = get<0>(c);
        }
        if (activeGuards == 1){
            soloTimes[soloGuard] += get<0>(c) - timeSoloStart;
        }
        activeGuards += get<1>(c);
        if (get<1>(c) == 1){
            currentGuards.insert(get<2>(c));
        } else {
            currentGuards.erase(get<2>(c));
        }
        // cout << activeGuards << ": ";
        // for (auto const&k:currentGuards){
        //     cout << k << ", ";
        // }
        // cout << endl; 
        if (activeGuards == 1){
            soloGuard = *currentGuards.begin(); 
            timeSoloStart = get<0>(c);
        }
        if (activeGuards == 0){
            totalLength += get<0>(c) - start;
        }
    }
    ll minLoneTime = 2000000000;
    for (auto const&c:soloTimes){
        minLoneTime = min(minLoneTime, c.second);
    }
    
    fout << totalLength - minLoneTime << endl; 
}
