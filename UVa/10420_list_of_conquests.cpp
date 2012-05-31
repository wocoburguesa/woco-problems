#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main(){
  int lines;
  string lovers;
  map<string, int> dict;
  cin >> lines;
  getline(cin, lovers);
  while(lines--){
    getline(cin, lovers);
    stringstream lover_stream(lovers);
    string word;
    int counter = 0;
    string country;
    while(getline(lover_stream, word, ' ')){
      if(counter == 0)
	country = word;
      else{
	++dict[country];
	break;
      }
      ++counter;
    }
  }
  map<string, int>::iterator it;
  for(it = dict.begin(); it != dict.end(); ++it){
    cout << (*it).first << ' ' << (*it).second << endl;
  }
  return 0;
};
