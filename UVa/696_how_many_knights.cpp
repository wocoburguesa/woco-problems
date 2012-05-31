#include <iostream>

using namespace std;

int main(){
  int r, c;
  while (cin >> r >> c && r && c){
    if(r == 1)
      cout << c;
    else if(c == 1)
      cout << r;
    else if(r == 2){
      if(c % 4 == 1)
	cout << (((c / 4) * 2) + 1) * 2;
      else if(c % 4)
	cout << (((c / 4) * 2) + 2) * 2;
      else
	cout << ((((c / 4) - 1) * 2) + 2) * 2;
    }
    else if(c == 2){
      if(r % 4 == 1)
	cout << (((r / 4) * 2) + 1) * 2;
      else if(r % 4)
	cout << (((r / 4) * 2) + 2) * 2;
      else
	cout << ((((r / 4) - 1) * 2) + 2) * 2;
    }
    else if((r * c) % 2 != 0)
      cout << (r * c + 1) / 2;
    else
      cout << (r * c) / 2;
    cout << " knights may be placed on a " << r << " row " << c <<
      " column board.\n";
  }
  return 0;
};
