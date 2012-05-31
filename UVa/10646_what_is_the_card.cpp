#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int get_value(string card){
  char a = '1';
  if(card[0] >= '2' && card[0] <= '9')
    return (int)card[0] - (int)a + 1;
  else
    return 10;
}

int main(){
  int cases;
  cin >> cases;
  int casess = cases;
  while(cases--){
    stack<string> deck;
    string card;
    for(int i = 0; i < 52; ++i){
      cin >> card;
      deck.push(card);
    }
    stack<string> tops;
    for(int i = 27; i < 52; ++i){
      tops.push(deck.top());
      deck.pop();
    }
    
    int y = 0;
    for(int i = 0; i < 3; ++i){
      int x = get_value(deck.top());
      y += x;
      deck.pop();
      for(int i = 0; i < 10 - x; ++i)
	deck.pop();
    }
    
    while(!tops.empty()){
      deck.push(tops.top());
      tops.pop();
    }

    while(!deck.empty()){
      tops.push(deck.top());
      deck.pop();
    }

    for(int i = 0; i < y-1; ++i)
      tops.pop();

    cout << "Case " << casess - cases << ": " << tops.top() << endl;
  }

  return 0;
};
