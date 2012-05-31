#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool foo(char a, char b){
  if(a >= 'A' && a <= 'Z'){
    if(b >= 'A' && b <= 'Z')
      return a < b;
    else
      return a-'A' <= b-'a';
  }
  else{
    if(b >= 'A' && b <= 'Z')
      return a-'a' < b-'A';
    else
      return a < b;
  }
}

int main(){
  string sin;
  int n;
  cin >> n;
  while(n--){
    cin >> sin;
    char* in = new char[sin.length()];
    for(int i = 0; i < sin.length(); ++i)
      in[i] = sin[i];

    sort(in, in+sin.length(), foo);
    do{
        cout << in << endl;
    }while(next_permutation(in, in+sin.length(), foo));
  }
  return 0;
};
