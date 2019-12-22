/*
USACO 2018 December Contest, Silver
Problem 2. Convention II
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <bits/stdc++.h>

using namespace std;

/*
Essentially the idea is to keep track of three things:
1. the current time
2. the cows that haven't gone yet
3. the cows in the line.
*/

struct cow{
  int sen; int arr; int dur; //senior, arrivaal, duration, time in line
};

struct cowOrd{ // order for the cows that haven't gone sorted based on time
	bool operator()(cow const& c1, cow const& c2){
    if (c1.arr != c2.arr) return c1.arr > c2.arr;
    else return c1.sen > c2.sen;
  }
};

struct Qord{ // order for the line thats sorted based on priority
	bool operator()(cow const& c1, cow const& c2){
			return c1.sen > c2.sen;
  }
};

bool isEq(cow A, cow B){
	if (A.sen == B.sen && A.arr == B.arr && A.dur == B.dur){
		return true;
	} return false;
}

int N;
priority_queue<cow, vector<cow>, Qord> line;
priority_queue<cow, vector<cow>, cowOrd> notGone;
cow inPatch; // cow thats in the patch.
int curTime = 0;

int main(){
	ifstream fin ("convention2.in");
	ofstream fout ("convention2.out");
	fin >> N;
	for (int i=0; i<N; i++){
		int a,t; fin >> a >> t; notGone.push({i,a,t});
	}
  vector<int> times; // times in line for the cows
  int maxTime = 0;
  inPatch = notGone.top();
  curTime = inPatch.arr+inPatch.dur;
  notGone.pop();
  while (!notGone.empty()) {
    if (curTime >= notGone.top().arr){//endtime greater than arrival
      line.push(notGone.top());
      notGone.pop();
    } else break;
  }
  while (!notGone.empty() || !line.empty()){
    if (line.empty()){
      inPatch = notGone.top();
      curTime = inPatch.arr + inPatch.dur;
      notGone.pop();
      while (!notGone.empty()){
        if (curTime >= notGone.top().arr){
          line.push(notGone.top());
          notGone.pop();
        } else break;
      }
    } else {
      inPatch = line.top();
      line.pop();
      curTime += inPatch.dur;
      times.push_back(curTime - inPatch.arr - inPatch.dur);
      while (!notGone.empty()){
        if (curTime >= notGone.top().arr){
          line.push(notGone.top());
          notGone.pop();
        } else break;
      }
    }
  }
  fout << *max_element(times.begin(),times.end());
}
