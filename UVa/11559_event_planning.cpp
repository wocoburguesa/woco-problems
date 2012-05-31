#include <iostream>

using namespace std;

int main(){
  int participants, budget, h, weeks;
  while(cin >> participants >> budget >> h >> weeks){
    int current_price;
    bool found = 0;
    for(int i = 0; i < h; ++i){
      cin >> current_price;
      int avail_beds;
      for(int j = 0; j < weeks; ++j){
	cin >> avail_beds;
	if(avail_beds < participants)
	  continue;
	else;
	int this_price = participants * current_price;
	if(this_price < budget){
	  budget = this_price;
	  found = 1;
	}
      }
    }
    if(found)
      cout << budget << endl;
    else
      cout << "stay home\n";
  }
  return 0;
};
