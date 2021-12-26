#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;



int main(){
  string fname = "array1.txt";
  ifstream fileObj1(fname);


  vector<vector<int>> board;
  vector<int> row_vector_temp;
  string str_temp;
  int row_num =0;
  int col_num =0;
  //Read file using getline + string
  while(getline(fileObj1,str_temp)){
    stringstream ss(str_temp);
    int x;
    char c;
    //So what happens is the first int from ss gets extracted to x and the second char from ss gets extracted to c
    while(ss>>x>>c){
      row_vector_temp.push_back(x);
    }
    board.push_back(row_vector_temp);
    row_vector_temp.clear();
  }//EOF while loop

  fileObj1.close();


  cout<<"Printing the vector of boards \n";
  for(int i =0; i < board.size(); i++ ){
    for(int j=0; j< board[0].size(); j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }



}//Eof Main
