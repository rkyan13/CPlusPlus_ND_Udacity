#include<iostream>
#include<vector>
using std::cout;

int main(){
  std::vector<std::vector<int>> board = {{ 0, 1, 2, 3, 4},
                                         { 5, 6, 7, 8, 9},
                                         {10,11,12,13,14}};
  for(int i =0; i<board.size(); i++){
    for(int j=0; j<board[0].size(); j++){
      std::cout<<board[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}
