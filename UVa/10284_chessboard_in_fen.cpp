#include <iostream>
#include <vector>

using namespace std;

vector< vector<char> > make_board(string fen){
  char uno = '1';
  vector<char> row;
  vector< vector<char> > board;
  for(int i = 0; i < fen.size(); ++i){
    if(fen[i] >= '1' && fen[i] <= '9')
      for(int j = 0; j < (int)fen[i] - (int)uno + 1; ++j)
	row.push_back('*');
    else
      row.push_back(fen[i]);
    if(row.size() == 8){
      ++i;
      board.push_back(row);
      row.clear();
    }
  }
  return board;
}

void attack(int f, int c, vector< vector<char> > &board){
  if(board[f][c] == 'p' && f+1 < 8){
    /*    if(c+1 < 8)
      board[f+1][c+1] = 'X';
    else;
    if(c-1 >= 0)
    board[f+1][c-1] = 'X';*/
    board[f+1][c] = 'X';
  }
  else if(board[f][c] == 'P' && f-1 >= 0){
    /*    if(c+1 < 8)
      board[f-1][c+1] = 'X';
    else;
    if(c-1 >= 0)
    board[f-1][c-1] = 'X';*/
    board[f-1][c] = 'X';
  }
  else if(board[f][c] == 'r' || board[f][c] == 'R'){
    int i = f + 1;
    while(i < 8 && (board[i][c] == '*' || board[i][c] == 'X')){
      board[i][c] = 'X';
      ++i;
    }
    i = f - 1;
    while(i >= 0 && (board[i][c] == '*' || board[i][c] == 'X')){
      board[i][c] = 'X';
      --i;
    }
    i = c + 1;
    while(c < 8 && (board[f][i] == '*' || board[f][i] == 'X')){
      board[f][i] = 'X';
      ++i;
    }
    i = c - 1;
    while(c >= 0 && (board[f][i] == '*' || board[f][i] == 'X')){
      board[f][i] = 'X';
      --i;
    }
  }
  else if(board[f][c] == 'n' || board[f][c] == 'N'){
    if(f+2 < 8 && c-1 >= 0 && (board[f+2][c-1] == '*' || board[f+2][c-1] == 'X'))
      board[f+2][c-1] = 'X';
    else;
    if(f+2 < 8 && c+1 < 8 && (board[f+2][c+1] == '*' || board[f+2][c+1] == 'X'))
      board[f+2][c+1] = 'X';
    else;
    if(f+1 < 8 && c+2 < 8 && (board[f+1][c+2] == '*' || board[f+1][c+2] == 'X'))
      board[f+1][c+2] = 'X';
    else;
    if(f-1 >= 0 && c+2 < 8 && (board[f-1][c+2] == '*' || board[f-1][c+2] == 'X'))
      board[f-1][c+2] = 'X';
    else;
    if(f-2 >= 0 && c+1 < 8 && (board[f-2][c+1] == '*' || board[f-2][c+1] == 'X'))
      board[f-2][c+1] = 'X';
    else;
    if(f-2 >= 0 && c-1 >= 0 && (board[f-2][c-1] == '*' || board[f-2][c-1] == 'X'))
      board[f-2][c-1] = 'X';
    else;
    if(f-1 >= 0 && c-2 >= 0 && (board[f-1][c-2] == '*' || board[f-1][c-2] == 'X'))
      board[f-1][c-2] = 'X';
    else;
    if(f+1 < 8 && c-2 >= 0 && (board[f+1][c-2] == '*' || board[f+1][c-2] == 'X'))
      board[f+1][c-2] = 'X';
    else;
  }
  else if(board[f][c] == 'b' || board[f][c] == 'B'){
    int i = f - 1;
    int j = c - 1;
    while(i >= 0 && j >= 0 && (board[i][j] == '*' || board[i][j] == 'X')){
      board[i][j] = 'X';
      --i;
      --j;
    }
    i = f - 1;
    j = c + 1;
    while(i >= 0 && j < 8 && (board[i][j] == '*' || board[i][j] == 'X')){
      board[i][j] = 'X';
      --i;
      ++j;
    }
    i = f + 1;
    j = c - 1;
    while(i < 8 && j >= 0 && (board[i][j] == '*' || board[i][j] == 'X')){
      board[i][j] = 'X';
      ++i;
      --j;
    }
    i = f + 1;
    j = c + 1;
    while(i < 8 && j < 8 && (board[i][j] == '*' || board[i][j] == 'X')){
      board[i][j] = 'X';
      ++i;
      ++j;
    }
  }
  else if(board[f][c] == 'Q' || board[f][c] == 'q'){
    int i = f - 1;
    int j = c - 1;
    while(i >= 0 && j >= 0 && (board[i][j] == '*' || board[i][j] == 'X')){
      board[i][j] = 'X';
      --i;
      --j;
    }
    i = f - 1;
    j = c + 1;
    while(i >= 0 && j < 8 && (board[i][j] == '*' || board[i][j] == 'X')){
      board[i][j] = 'X';
      --i;
      ++j;
    }
    i = f + 1;
    j = c - 1;
    while(i < 8 && j >= 0 && (board[i][j] == '*' || board[i][j] == 'X')){
      board[i][j] = 'X';
      ++i;
      --j;
    }
    i = f + 1;
    j = c + 1;
    while(i < 8 && j < 8 && (board[i][j] == '*' || board[i][j] == 'X')){
      board[i][j] = 'X';
      ++i;
      ++j;
    }
    i = f + 1;
    while(i < 8 && (board[i][c] == '*' || board[i][c] == 'X')){
      board[i][c] = 'X';
      ++i;
    }
    i = f - 1;
    while(i >= 0 && (board[i][c] == '*' || board[i][c] == 'X')){
      board[i][c] = 'X';
      --i;
    }
    i = c + 1;
    while(c < 8 && (board[f][i] == '*' || board[f][i] == 'X')){
      board[f][i] = 'X';
      ++i;
    }
    i = c - 1;
    while(c >= 0 && (board[f][i] == '*' || board[f][i] == 'X')){
      board[f][i] = 'X';
      --i;
    }    
  }
  else if(board[f][c] == 'K' || board[f][c] == 'k'){
    if(f-1 >= 0 && (board[f-1][c] == '*' || board[f-1][c] == 'X'))
      board[f-1][c] = 'X';
    else;
    if(f+1 < 8 && (board[f+1][c] == '*' || board[f+1][c] == 'X'))
      board[f+1][c] = 'X';
    else;
    if(c-1 >= 0 && (board[f][c-1] == '*' || board[f][c-1] == 'X'))
      board[f][c-1] = 'X';
    else;
    if(c+1 < 8 && (board[f][c+1] == '*' || board[f][c+1] == 'X'))
      board[f][c+1] = 'X';
    else;
    if(f-1 >= 0 && c-1 >= 0 && (board[f-1][c-1] == '*' || board[f-1][c-1] == 'X'))
      board[f-1][c-1] = 'X';
    else;
    if(f-1 >= 0 && c+1 < 8 && (board[f-1][c+1] == '*' || board[f-1][c+1] == 'X'))
      board[f-1][c+1] = 'X';
    else;
    if(f+1 < 8 && c-1 >= 0 && (board[f+1][c-1] == '*' || board[f+1][c-1] == 'X'))
      board[f+1][c-1] = 'X';
    else;
    if(f+1 < 8 && c+1 < 8 && (board[f+1][c+1] == '*' || board[f+1][c+1] == 'X'))
      board[f+1][c+1] = 'X';
    else;
  }
  return;
}

int main(){
  string fen;
  while(cin >> fen){
    vector< vector<char> > board = make_board(fen);
    for(int i = 0; i < 8; ++i){
      for(int j = 0; j < 8; ++j)
	attack(i, j, board);
    }
    int count = 0;
    for(int i = 0; i < 8; ++i){
      for(int j = 0; j < 8; ++j)
	cout << board[i][j] << " ";
      cout << endl;
    }
	/*    	if(board[i][j] == '*')
	  ++count;
	  cout << count << endl;*/
  }
  return 0;
};
