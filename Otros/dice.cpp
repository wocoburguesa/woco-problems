#include <iostream>

using namespace std;

int main(){
  string caster, caller, call;
  int rolls;
  while(cin >> caster >> caller >> call && call != "#"){
    cin >> rolls;
    int counts[2] = {0, 0}; //[0] = odds, [1] = evens
    int roll;
    while(rolls--){
      cin >> roll;
      ++counts[roll%2==0];
    }
    cout << caster << " " << counts[call!="even"] << " " <<
      caller << " " << counts[call=="even"] << endl;
  }
  return 0;
}
