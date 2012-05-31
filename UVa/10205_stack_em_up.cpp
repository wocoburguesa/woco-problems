#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

bool is_space(string s){
  if(s.size() == 0)
    return 1;
  for(int i = 0; i < s.length(); ++i)
    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
      return 0;
  return 1;
}

string foo(int n){
  string ans = "";
  int div = n / 13;
  int mod = n % 13;
  switch(mod){
  case 0:
    ans += "2";
    break;
  case 1:
    ans += "3";
    break;
  case 2:
    ans += "4";
    break;
  case 3:
    ans += "5";
    break;
  case 4:
    ans += "6";
    break;
  case 5:
    ans += "7";
    break;
  case 6:
    ans += "8";
    break;
  case 7:
    ans += "9";
    break;
  case 8:
    ans += "10";
    break;
  case 9:
    ans += "Jack";
    break;
  case 10:
    ans += "Queen";
    break;
  case 11:
    ans += "King";
    break;
  case 12:
    ans += "Ace";
    break;
  }
  ans += " of ";
  switch(div){
  case 0:
    ans += "Clubs";
    break;
  case 1:
    ans += "Diamonds";
    break;
  case 2:
    ans += "Hearts";
    break;
  case 3:
    ans += "Spades";
    break;
  }
  return ans;
}

int main(){
  int cases;
  string a;
  ofstream out("a.txt");
  cin >> cases;
  while(cases--){
    int shuffles;
    cin >> shuffles;
    vector< vector<int> > shuffs;
    for(int i = 0; i < shuffles; ++i){
      vector<int> tech;
      int card;
      for(int j = 0; j < 52; ++j){
	cin >> card;
	tech.push_back(card);
      }
      shuffs.push_back(tech);
    }
    vector<int> curr;
    for(int i = 0; i < 52; ++i)
      curr.push_back(i+1);
    vector<int> buff = curr;

    getline(cin, a);
    while(getline(cin, a) && a != "\0"){
      int shuffle = atoi(a.c_str());
      for(int i = 0; i < 52; ++i)
	buff[i] = curr[shuffs[shuffle - 1][i] - 1];
      for(int i = 0; i < 52; ++i)
	curr[i] = buff[i];
    }
    

    for(int i = 0; i < 52; ++i)
      cout << foo(curr[i] - 1) << endl;
    if(cases > 0)
      cout << endl;
    }
  return 0;
};
