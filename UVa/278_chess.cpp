#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
  int cases;
  cin >> cases;
  while(cases--){
    char type;
    cin >> type;
    int r, c;
    cin >> r >> c;
    switch(type){
    case 'r':
      cout << min(r, c);
      break;
    case 'k':
      if((r * c) % 2 != 0)
	cout << (r * c + 1) / 2;
      else
	cout << (r * c) / 2;
      break;
    case 'Q':
      cout << min(r, c);
      break;
    case 'K':
      cout << (int)ceil(r / 2.0) * (int)ceil(c / 2.0);
      break;
    }
    cout << endl;
  }
};
