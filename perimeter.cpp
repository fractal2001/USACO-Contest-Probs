/*
USACO 2019 January Contest, Silver
Problem 2. Icy Perimeter
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++) 

int n;
char gridPERI[1001][1001];
char gridAREA[1001][1001];

int periVal[1001][1001];

// vector<int> floodfill(int r, int c, int area, int peri){
//     grid[r][c] = '.';
//     vector<int> ii = {-1,1,0,0};
//     vector<int> jj = {0,0,1,-1};
//     area += 1;
//     peri += periVal[r][c];
//     for (int i=0; i<4; i++){
//         if (r+ii[i] >= 0 && r+ii[i] < n && c+jj[i] >= 0 && c+jj[i] < n){
//             if (grid[r+ii[i]][c+jj[i]] == '#'){
//                 vector<int> areaPeri = floodfill(r+ii[i],c+jj[i], 0, 0);
//                 area += areaPeri[0];
//                 peri += areaPeri[1];
//             }
//         }
//     }
//     return {area,peri};
// }

int floodfillAREA(int r, int c, int area){
    gridAREA[r][c] = '.';
    vector<int> ii = {-1,1,0,0};
    vector<int> jj = {0,0,1,-1};
    area += 1;
    for (int i=0; i<4; i++){
        if (r+ii[i] >= 0 && r+ii[i] < n && c+jj[i] >= 0 && c+jj[i] < n){
            if (gridAREA[r+ii[i]][c+jj[i]] == '#'){
                area += floodfillAREA(r+ii[i],c+jj[i], 0);
            }
        }
    }
    return area;
}

int floodfillPERI(int r, int c, int peri){
    gridPERI[r][c] = '.';
    vector<int> ii = {-1,1,0,0};
    vector<int> jj = {0,0,1,-1};
    peri += periVal[r][c];
    for (int i=0; i<4; i++){
        if (r+ii[i] >= 0 && r+ii[i] < n && c+jj[i] >= 0 && c+jj[i] < n){
            if (gridPERI[r+ii[i]][c+jj[i]] == '#'){
                peri += floodfillPERI(r+ii[i],c+jj[i], 0);
            }
        }
    }
    return peri;
}

bool comp(vector<int> A, vector<int> B){
    if (A[0] != B[0]){
        return (A[0] < B[0]);
    } else {
        return (A[1] >= B[1]);
    }
}

int main() {
    ifstream fin ("perimeter.in");
    ofstream fout ("perimeter.out");
    
    fin >> n;
    FOR(i,0,n){
        FOR(j,0,n){
            fin >> gridAREA[i][j];
            gridPERI[i][j] = gridAREA[i][j];
        }
    }
    vector<int> ii = {-1,1,0,0};
    vector<int> jj = {0,0,1,-1};
    FOR(r,0,n){
        FOR(c,0,n){
            int periContrib = 0;
            for (int i=0; i<4; i++){
                if (r+ii[i] >= 0 && r+ii[i] < n && c+jj[i] >= 0 && c+jj[i] < n){
                    if (gridAREA[r+ii[i]][c+jj[i]] == '#'){
                        periContrib ++;
                    }
                }
            }
            periVal[r][c] = 4-periContrib;
        }
    }
    //vector<vector<int>> icyperi;
    vector<int> bestIcy = {0,999999999}; 
    FOR(i,0,n){
        FOR(j,0,n){
            if (gridPERI[i][j] == '#'){
                //vector<int> iso = floodfill(i,j,0,0);
                int curArea = floodfillAREA(i,j,0);
                int curPeri = floodfillPERI(i,j,0);
                if (bestIcy[0] < curArea){
                    bestIcy = {curArea, curPeri};
                } else if (bestIcy[0] == curArea){
                    if (bestIcy[1] > curPeri){
                        bestIcy[1] = curPeri;
                    }
                }
                //icyperi.push_back({floodfillAREA(i,j,0), floodfillPERI(i,j,0)}); 
            }
        }
    }
    //sort(icyperi.begin(), icyperi.end(), comp);
    fout << bestIcy[0] << " " << bestIcy[1] << endl;
}
