#include <iostream>

using namespace std;

int main(){
  string line;
  while(getline(cin, line) && line != "#"){
    int ans = 0;
    for(int i = 0; i < line.size(); ++i){
      if(line[i] != ' ')
        ans += (i+1)*((int)(line[i]-'A'+1));
    }
    cout << ans << endl;
  }
  return 0;
};
