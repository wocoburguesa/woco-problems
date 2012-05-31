#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string to_lower(string s){
  for(int i = 0; i < s.length(); ++i){
    if(s[i] >= 'A' && s[i] <= 'Z')
      s[i] = 'a' + (s[i] - 'A');
  }
  return s;
}

int main(){
  string in;
  map< string, vector<string> > dict;
  map< string, vector<string> >::iterator it;
  while(cin >> in && in != "#"){
    string buff = to_lower(in);
    sort(buff.begin(), buff.end());
    dict[buff].push_back(in);
  }
  vector<string> final;
  for(it = dict.begin(); it != dict.end(); ++it)
    if((*it).second.size() == 1)
      final.push_back((*it).second[0]);

  sort(final.begin(), final.end());
  for(int i = 0; i < final.size(); ++i)
    cout << final[i] << endl;

  return 0;
};
