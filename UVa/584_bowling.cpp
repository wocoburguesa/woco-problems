#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

int get_score(char s){
  if(s == 'X' || s == '/'){
    return 10;
  }
  return s-'0';
}

int main(){
  string line;
  while(getline(cin, line) && line != "Game Over"){
    stringstream ss(line);
    int total = 0, frame = 1, i = 0;
    bool frame_switch = 0;
    string score;
    vector<char> rolls;
    while(ss >> score)
      rolls.push_back(score[0]);

    int size = rolls.size();

    for(; i < size;){
      total += get_score(rolls[i]);
      if(rolls[i] == 'X'){
	frame++;
	frame_switch = 0;
      }
      else if(rolls[i] == '/'){
	total -= get_score(rolls[i-1]);
	frame++;
	frame_switch = 0;
      }
      else
	if(i > 0 && rolls[i-1] >= '0' && rolls[i-1] <= '9' && !frame_switch){
	  frame++;
	  frame_switch = 1;
	}
	else
	  frame_switch = 0;
      ++i;
      if(frame == 11){
	break;
      }
    }
    
    for(int j = 0; j < i; ++j){
      if(rolls[j] == 'X'){
	if(j+1 < size)
	  total += get_score(rolls[j+1]);
	else;
	if(j+2 < size)
	  if(rolls[j+2] == '/'){
	    total += get_score(rolls[j+2]);
	    total -= get_score(rolls[j+1]);
	  }
	  else
	    total += get_score(rolls[j+2]);
      }
      else if(rolls[j] == '/'){
	if(j+1 < size)
	  total += get_score(rolls[j+1]);
      }
    }

    cout << total << endl;
  }
  return 0;
}
