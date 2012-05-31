#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

string processline(string line){
  vector<char> buff;
  for(int i = 0; i < line.length(); ++i)
    if(line[i] >= 'a' && line[i] <= 'z')
      buff.push_back(line[i]);
  
  return string(buff.begin(), buff.end());
}

int main(){
  int cases;
  string line;
  cin >> cases;
  int casess = cases;
  getline(cin, line);
  while(cases--){
    getline(cin, line);
    line = processline(line);
    cout << "Case #" << casess - cases << ":\n";
    if(sqrt(line.length()) == floor(sqrt(line.length()))){
      int k = sqrt(line.length());
      vector<string> mat;
      for(int i = 0; i < k; ++i){
        string buff = "";
        for(int j = i*k; j < (i+1)*k; ++j)
          buff += line[j];
        mat.push_back(buff);
      }

      bool check1 = 1, check2 = 1;
      for(int i = 0; i < k && check1; ++i)
        for(int j = i; j < k; ++j)
          if(mat[i][j] != mat[j][i]){
            check1 = 0;
            break;
          }

      if(check1)
        for(int i = 0; i < k && check2; ++i)
          if(mat[i][i] != mat[k-i-1][k-i-1]){
            check2 = 0;
            break;
          }
          else;
      else;

      if(check1 && check2)
        cout << k << endl;
      else
        cout << "No magic :(\n";

    }
    else
      cout << "No magic :(\n";
  }
  return 0;
};
