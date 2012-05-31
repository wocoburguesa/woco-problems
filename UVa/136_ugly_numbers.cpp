#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool less_than(unsigned long a, unsigned long b){
  return a > b;
}

vector<unsigned long> uglies;
vector<unsigned long> poss;

bool find(unsigned long n, vector<unsigned long> v){
  for(int i = 0; i < v.size(); ++i)
    if(v[i] == n)
      return 1;
  return 0;
}

int main(){
  uglies.push_back(1);
  for(int i = 0; i < 1500; ++i){
    //    for(int j = 0; j < uglies.size(); ++j){
    poss.push_back(uglies.back() * 2);
    poss.push_back(uglies.back() * 3);
    poss.push_back(uglies.back() * 5);
      //    }
    make_heap(poss.begin(), poss.end(), less_than);
    bool pushed = 0;
    while(!pushed){
      if(!find(poss.front(), uglies)){
	uglies.push_back(poss.front());
	pushed = 1;
      }
      else{
	pop_heap(poss.begin(), poss.end(), less_than);
	poss.pop_back();
      }
    }
    //    cout <<  uglies[i] << endl;
  }
  cout << "The 1500'th ugly number is " << uglies[1499] << "." << endl;
  //  cout << poss.size() << endl;
  return 0;
};
