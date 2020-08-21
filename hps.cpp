/*
USACO 2017 January Contest, Silver
Problem 2. Hoof, Paper, Scissors
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<int> add(vector<int> A, vector<int> B){
    vector<int> C;
    for (int i=0; i<3; i++){
        C.push_back(A[i]+B[i]);
    }
    return C;
}

int main(){
    ifstream fin ("hps.in");
    ofstream fout ("hps.out");
    int N; fin >> N;
    vector<vector<int>> hps;
    // hoof, paper, sissors
    vector<char> sequence;
    hps.push_back({0,0,0});
    for (int i=0; i<N; i++){
        char K; fin >> K;
        sequence.push_back(K);
        if (K == 'H'){
            hps.push_back(add(hps.back(), {1,0,0}));
        } else if (K == 'P'){
            hps.push_back(add(hps.back(), {0,1,0}));
        } else {
            hps.push_back(add(hps.back(), {0,0,1}));
        }
    }

    int maxwin = 0;
    vector<int> last = hps.back();
    for (int x=0; x<=N; x++){
        vector<int> swap = hps[x];
        int first = std::max(swap[0], max(swap[1], swap[2]));
        int lastGames = std::max(last[0] - swap[0], max(last[1] - swap[1], last[2] - swap[2]));
        maxwin = max(maxwin, first+lastGames);
    }
    fout << maxwin << endl;
}
