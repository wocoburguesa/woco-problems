#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

int get_last(vector<int> l, int n){
  int deleted = 0;
  int idx = 0;
  int step = 0;
  
  while(deleted < l.size()-1){
    l[idx%l.size()] = 0;
    deleted++;
    while(step < n){
      idx++;
      if(l[idx%l.size()] != 0){
	step++;
      }
    }
    step = 0;
  }
  return l[idx%l.size()];
}

int main(){
  int n;
  while(cin >> n && n){
    vector<int> plants;
    for(int i = 0; i < n; ++i)
      plants.push_back(i+1);

    for(int i = 1; i < n+1; ++i){
      if(get_last(plants, i) == 13){
	cout << i << endl;
	break;
      }
    }
  }
  return 0;
}
