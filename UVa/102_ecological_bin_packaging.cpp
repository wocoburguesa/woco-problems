#include <iostream>

using namespace std;

int main()
{
  int bins [3][3];
  int distribution[9];
  while(cin >> distribution[0]){

    for(int i = 1; i < 9; ++i){
      cin >> distribution[i];
    }

    int sum = 0;
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j){
	bins[i][j] = distribution[(i*3)+j];
	sum += bins[i][j];
      }

    string ways[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    string curr_way;
    int min;

    curr_way = ways[0];
    int max_subsum = bins[0][0] + bins[1][2] + bins[2][1];
    if(bins[0][0] + bins[1][1] + bins[2][2] > max_subsum){
      curr_way = ways[1];
      max_subsum = bins[0][0] + bins[1][1] + bins[2][2];
    }
    else;
    if(bins[0][2] + bins[1][0] + bins[2][1] > max_subsum){
      curr_way = ways[2];
      max_subsum = bins[0][2] + bins[1][0] + bins[2][1];
    }
    else;
    if(bins[0][2] + bins[1][1] + bins[2][0] > max_subsum){
      curr_way = ways[3];
      max_subsum = bins[0][2] + bins[1][1] + bins[2][0];
    }
    else;
    if(bins[0][1] + bins[1][0] + bins[2][2] > max_subsum){
      curr_way = ways[4];
      max_subsum = bins[0][1] + bins[1][0] + bins[2][2];
    }
    else;
    if(bins[0][1] + bins[1][2] + bins[2][0] > max_subsum){
      curr_way = ways[5];
      max_subsum = bins[0][1] + bins[1][2] + bins[2][0];
    }
    else;
    cout << curr_way << " " << sum - max_subsum << endl;
  }
}
