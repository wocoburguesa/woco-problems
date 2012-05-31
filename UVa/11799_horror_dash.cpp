#include <iostream>

using namespace std;

int main(){
  int cases, casess;
  cin >> cases;
  casess = cases;
  while(cases--){
    int number;
    int curr_speed;
    cin >> number;
    int min = 0;
    while(number--){
      cin >> curr_speed;
      if(curr_speed > min)
	min = curr_speed;
    }
    cout << "Case " << casess - cases << ": " << min << endl;
  }
  return 0;
};
