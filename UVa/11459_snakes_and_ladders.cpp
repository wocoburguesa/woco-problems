#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

int board[104];

int main(){
  int cases;
  cin >> cases;
  while(cases--){
    int players, switches, rolls;
    cin >> players >> switches >> rolls;
    for(int i = 0; i < 104; ++i)
      board[i] = 0;

    int start, end;
    while(switches--){
      cin >> start >> end;
      board[start] = end;
    }

    for(int i = 0; i < 104; ++i)
      while(board[board[i]] != 0)
	board[i] = board[board[i]];

    int pos[players];
    for(int i = 0; i < players; ++i)
      pos[i] = 1;

    int roll, i;
    for(i = 0; i < rolls; ){
      cin >> roll;
      int j = i % players;
      ++i;
      pos[j] += roll;
      if(board[pos[j]] != 0)
	pos[j] = board[pos[j]];

      if(pos[j] >= 100){
	pos[j] = 100;
	break;
      }
    }

    for(; i < rolls; ++i){
      cin >> roll;
    }

    for(i = 0; i < players; ++i){
      cout << "Position of player " << i+1 << " is " << pos[i] << ".\n";
    }
    
  }
  return 0;
}
