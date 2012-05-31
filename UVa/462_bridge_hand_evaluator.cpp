#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int how_many_suit(vector<string> hand, char suit){
  int count = 0;
  for(int i = 0; i < hand.size(); ++i)
    if(hand[i][1] == suit)
      ++count;
  return count;
}

pair<int, int> get_score(vector<string> hand,
			 map<char, int, bool(*)(char,char)> &suits_count,
			 map<char, bool> &stopped){
  int score = 0, queens = 0, kings = 0, jacks = 0, aces = 0;
  suits_count['S'] = how_many_suit(hand, 'S');
  suits_count['H'] = how_many_suit(hand, 'H');
  suits_count['D'] = how_many_suit(hand, 'D');
  suits_count['C'] = how_many_suit(hand, 'C');
  
  for(int i = 0; i < hand.size(); ++i){
    switch(hand[i][0]){
    case 'A':
      ++aces;
      stopped[hand[i][1]] = 1;
      break;
    case 'K':
      ++kings;
      if (suits_count[hand[i][1]] < 2)
	--score;
      else
	stopped[hand[i][1]] = 1;
      break;
    case 'Q':
      ++queens;
      if (suits_count[hand[i][1]] < 3)
	--score;
      else
	stopped[hand[i][1]] = 1;
      break;
    case 'J':
      ++jacks;
      if (suits_count[hand[i][1]] < 4)
	--score;
      else;
      break;
    }
  }
  score += (aces * 4) + (kings * 3) + (queens * 2) + (jacks);
  int modifier = 0;
  map<char, int>::iterator it;
  for(it = suits_count.begin(); it != suits_count.end(); ++it){
    if((*it).second == 2)
      ++modifier;
    if((*it).second == 1)
      modifier += 2;
    if((*it).second == 0)
      modifier += 2;
  }
  return pair<int, int>(score, score+modifier);
}

char get_bigger(map<char, int, bool(*)(char,char)> suits_count){
  map<char, int>::iterator it;
  char winrar;
  int max = 0;
  for(it = suits_count.begin(); it != suits_count.end(); ++it){
    if((*it).second > max){
      max = (*it).second;
      winrar = (*it).first;
    }
  }
  return winrar;
}

bool comp(char a, char b){
  return a > b;
}

int main(){
  string line;
  while(getline(cin, line)){
    stringstream hand(line);
    string card;
    vector<string > cards;
    bool(*fn_pt)(char, char) = comp;
    map<char, int, bool(*)(char, char)> suits_count(fn_pt);
    map<char, bool> stopped;
    stopped['C'] = 0;
    stopped['S'] = 0;
    stopped['H'] = 0;
    stopped['D'] = 0;

    while(getline(hand, card, ' '))
      cards.push_back(card);
    pair<int, int> score = get_score(cards, suits_count, stopped);
    bool all_stopped = stopped['C'] & stopped['S'] & stopped['D'] & stopped['H'];
    if(score.first >= 16 && all_stopped){
      cout << "BID NO-TRUMP\n";
      continue;
    }
    if(score.second >= 14){
      cout << "BID " << get_bigger(suits_count) << endl;
      continue;
    }
    else
    cout << "PASS\n";
  }

  return 0;
};
