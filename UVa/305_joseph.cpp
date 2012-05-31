#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

bool test(vector<int> l, int n, int k){
  int deleted = 0;
  int idx = n-1;
  int step = 0;
  bool good = 1;

  while(deleted < k && good){
    if(idx%l.size() < k)
      return 0;
    l[idx%l.size()] = -1;
    deleted++;
    while(step < n){
      idx++;
      if(l[idx%l.size()] != -1){
	step++;
      }
    }
    step = 0;
  }
  if(good)
    return 1;
  else
    return 0;
}

int main(){
  int k;
  while(cin >> k && k){
    vector<int> people;
    for(int i = 0; i < 2*k; ++i)
      people.push_back(i);

    int i = k;
    while(!test(people, i, k)){
      ++i;
    }
    cout << i << endl;
  }
  return 0;
}
