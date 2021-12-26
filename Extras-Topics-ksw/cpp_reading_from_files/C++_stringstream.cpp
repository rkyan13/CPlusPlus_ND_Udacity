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
  string fname = "board1.txt";
  ifstream fileObj1(fname);


  vector<vector<int>> board;
  vector<int> row_vector_temp;
  string str_temp;
  int row_num =0;
  int col_num =0;
  //Read file using getline + string
  while(getline(fileObj1,str_temp)){
    stringstream ss(str_temp);
    int x=0 ;
    char c;
    ss >> x >>c;
    cout << "x="<<x<<" : c="<<c<<endl;
    ss >> x >>c;
    cout << "x="<<x<<" : c="<<c<<endl;
    ss >> x >>c;
    cout << "x="<<x<<" : c="<<c<<endl;
  }//EOF while loop

  fileObj1.close();

 /*
  cout<<"Printing the vector of boards \n";
  for(int i =0; i < 5; i++ ){
    for(int j=0; j< 5; j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
*/



}//Eof Main
