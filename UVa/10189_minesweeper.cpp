#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

int main(){
  int rows, cols, counter = 1;
  while(cin >> rows >> cols && rows, cols){
    if(counter > 1)
      cout << endl;
    vector<string> board;
    vector< vector<int> > solved;
    string buff;
    int rows_ = rows;
    while(rows_--){
      cin >> buff;
      board.push_back(buff);
      vector<int> aux;
      solved.push_back(aux);
    }
    for(int i = 0; i < rows; ++i)
      for(int j = 0; j < cols; ++j)
	if(board[i][j] != '*')
	  solved[i].push_back(0);
	else
	  solved[i].push_back(-1);

    for(int i = 0; i < rows; ++i)
      for(int j = 0; j < cols; ++j)
	if(board[i][j] == '*'){
	  if(i > 0 && j > 0){
	    solved[i-1][j-1]++;
	    solved[i-1][j]++;
	    solved[i][j-1]++;
	  }
	  else if(i > 0)
	    solved[i-1][j]++;
	  else if(j > 0)
	    solved[i][j-1]++;
	  else;
	  if(i < rows-1 && j > 0){
	    solved[i+1][j-1]++;
	    solved[i+1][j]++;
	  }
	  else if(i < rows-1)
	    solved[i+1][j]++;
	  else;
	  if(i > 0 && j < cols-1){
	    solved[i-1][j+1]++;
	    solved[i][j+1]++;
	  }
	  else if(j < cols-1)
	    solved[i][j+1]++;
	  else;
	  if(i < rows-1 && j < cols-1)
	    solved[i+1][j+1]++;
	}
    
    cout << "Field #" << counter << ":\n";
    ++counter;
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j)
	if(board[i][j] == '*')
	  cout << "*";
	else
	  cout << solved[i][j];//(int)solved[i][j];
      cout << endl;
    }

  }
  return 0;
}
