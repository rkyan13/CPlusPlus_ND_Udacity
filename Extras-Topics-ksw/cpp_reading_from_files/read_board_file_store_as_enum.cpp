#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

enum Cell{ kEmpty =0, kObstacle=1};

vector<Cell> ParseLine(string &this_line){
  stringstream sso(this_line);
  vector<Cell> row;
  int x;
  char c;
  while(sso>>x>>c && c==','){
    //Note this type
    row.push_back(Cell(x));
  }
  return row;
}

vector<vector<Cell>> ParseFile(ifstream &file_obj){
  string this_line;
  stringstream sso;
  int  x;
  char c;
  vector<Cell> row;
  vector<vector<Cell>> board;
  while(getline(file_obj, this_line)){
    row = ParseLine(this_line);
    board.push_back(row);
  }
  return board;
}


void PrintBoardAsInt(vector<vector<Cell>> board){
  cout<<"\n Printing Board as Int"<<endl;
  for(vector<Cell> row:board){
    for(Cell cell:row){
      cout<<cell<<" ";
    }
    cout<<endl;
  }
}

void PrintBoardAsEmoji(vector<vector<Cell>> board){
  cout<<"\n Printing Board as Emoji"<<endl;
  for(vector<Cell> row:board){
    for(Cell cell:row){
       if(cell == kEmpty)
         cout<<" 0 ";
       else
         cout<<"⛰️  ";
    }
    cout<<endl;
  }
}


int main(){
  ifstream board_file_obj;
  board_file_obj.open("board1.txt");

  vector<vector<Cell>> board ;
  board = ParseFile(board_file_obj);
  PrintBoardAsInt(board);
  PrintBoardAsEmoji(board);
}
