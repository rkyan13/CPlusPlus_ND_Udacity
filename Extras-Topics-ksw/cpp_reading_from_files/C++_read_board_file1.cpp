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
  while(getline(fileObj1,str_temp,',')){
    //Create the 2d vector
    /*
    All temp_str contain the newline character (because that is the property of c++ strings I think. the string is terminated by \0 or \n or sth"
    But because we are using the comma as a delimter in getline, the newline at the end of each line gets read with the next line
    So the newline character on the first line of the file gets read with the first characater of the second line of the file
    The newline character on the second line of the file gets read with first character of the third line etc.
    So if the newline character is located at the very first position then it is a new line
    */
    if(str_temp.find("\n")==0){
      col_num =0;
      row_num ++;
      board.push_back(row_vector_temp);
      row_vector_temp.clear();
    }
    stringstream ss(str_temp);
    int x=0 ;
    ss >> x ;
    row_vector_temp.push_back(x);
    col_num++;
  }//EOF while loop

  fileObj1.close();


  cout<<"Printing the vector of boards \n";
  for(int i =0; i < 5; i++ ){
    for(int j=0; j< 5; j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }



}//Eof Main
