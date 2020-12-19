/*
USACO 2019 January Contest, Silver
Problem 3. Mountain View
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
typedef double dd;

vector<pair<int,int>> mountains;

bool checkContain(pair<int,int> A, pair<int,int> B){
    //check if A contains B
    if (A.second >= B.second && abs(A.second - B.second) >= abs(A.first - B.first) ){
        return true;
    } 
    return false;
}
 
int main(){
    ifstream fin ("mountains.in");
    ofstream fout ("mountains.out");
    int N; fin >> N;
    FOR(i,0,N){
        int x,y; fin >> x >> y;
        mountains.push_back(make_pair(x,y));
    }
    
    sort(mountains.begin(), mountains.end());
    set<pair<int,int>> visibleMountains;
    visibleMountains.insert(mountains.front());
    //mountains.erase(mountains.begin());
    for (auto const&mountain:mountains){
        bool skipFlag = false;
        for (auto const&mount:visibleMountains){
            // check if a visible mountain contains mountain
            if (checkContain(mount, mountain)){
                skipFlag = true;
                //cout << "SKIPPED" << endl; 
                //cout << mountain.first << " " << mountain.second << endl;
                break;
            } 
        }
        //cout << skipFlag << endl; 
        if (skipFlag == false){
            //cout << mountain.first << mountain.second << endl;
            set<pair<int,int>> newVisibleMountains = visibleMountains;
            for (auto const&mount:visibleMountains){
                // check if mountain contains visible mountain
                if (checkContain(mountain, mount)){
                    newVisibleMountains.erase(mount);
                } 
            }
            newVisibleMountains.insert(mountain);
            visibleMountains = newVisibleMountains;
        } 
    }
    // for (auto const&c:visibleMountains){
    //     cout << c.first << " " << c.second << endl; 
    // }
    fout << visibleMountains.size();
    
}
