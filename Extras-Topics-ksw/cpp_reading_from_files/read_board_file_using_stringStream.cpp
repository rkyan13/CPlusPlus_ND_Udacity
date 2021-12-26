#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

/*
//Note: The following while-loops causes the last characters to be read twice
while(sso){
  sso>>x>>c;
  cout<<x<<c;
}
while(sso>>x>>c){
  cout<<x<<c;
}
*/

void ParseFile(ifstream &file_obj){
  string this_line;
  stringstream sso;
  int  x;
  char c;
  while(getline(file_obj, this_line)){
    sso.clear();
    sso<<this_line;
    while(sso>>x>>c){
      cout<<x<<c;
    }
    cout<<endl;
  }
}



int main(){
  enum Cell{ kEmpty =0, kObstacle=1};
  vector<vector<Cell>> board ;

  ifstream board_file_obj;
  board_file_obj.open("array2.txt");
  ParseFile(board_file_obj);


}
