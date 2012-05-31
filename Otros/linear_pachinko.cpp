#include <iostream>
#include <vector>

using namespace std;

int go_back(int pos, string p){
  for(; pos >= 0; pos--){
    if(p[pos]=='.'){
      return 1;
    }
    else if(p[pos]=='\\' || p[pos]=='|')
      return 0;
    else if(pos==0)
      return 1;
  }  
}

int go_forward(int pos, string p){
  for(; pos < p.size(); pos++){
    if(p[pos]=='.'){
      return 1;
    }
    else if(p[pos]=='/' || p[pos]=='|')
      return 0;
    else if(pos==0)
      return 1;
  }  
}

int pachinko_odds(string p){
  float ans = 0;
  for(int i = 0; i < p.size(); ++i){
    int buff = 0;
    switch(p[i]){
    case '/':
      if(i==0)
        buff = 100;
      else
        buff = 100*go_back(i-1, p);
      break;
    case '\\':
      if(i==(p.size()-1))
        buff = 100;
      else
        buff = 100*go_forward(i+1, p);
      break;
    case '|':
      if(i==0){
        buff += 50;
        buff += 50*go_forward(i+1, p);
      }
      else if(i==(p.size()-1)){
        buff += 50;
        buff += 50*go_back(i-1, p);
      }
      else{
        buff += 50*go_forward(i+1, p);
        buff += 50*go_back(i-1, p);
      }
      break;
    case '.':
      buff = 100;
      break;
    }
    ans += buff;
  }

  ans /= p.size();
  return (int)ans;
}

int main(){
  string pachinko;
  while(cin >> pachinko && pachinko != "#"){
    cout << pachinko_odds(pachinko) << endl;
  }
  return 0;
}
