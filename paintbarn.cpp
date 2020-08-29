/*
USACO 2019 February Contest, Silver
Problem 2. Painting the Barn
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int main(){
    ifstream fin ("paintbarn.in");
    ofstream fout ("paintbarn.out");
    int N, K; fin >> N >> K;
    int barn[1001][1001] = {};
    int prefix[1002][1002] = {};
    for (int i=0; i<N; i++){
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        barn[y1][x1] += 1;
        barn[y2][x2] += 1;
        barn[y2][x1] -= 1;
        barn[y1][x2] -= 1;
    }
    for (int i=1; i<1002; i++){
        for (int j=1; j<1002; j++){
            prefix[i][j] = prefix[i][j-1]+barn[i-1][j-1];
        }
    }
    for (int i=1; i<= 1001; i++){
        for (int j=1; j<= 1001; j++){
            prefix[i][j] += prefix[i-1][j];
        }
    }
    int count = 0;
    for (int i=0; i<= 1001; i++){
        for (int j=0; j<= 1001; j++){
            if (prefix[i][j] == K){
                count ++;
            }
        }
    }
    fout << count;
}

