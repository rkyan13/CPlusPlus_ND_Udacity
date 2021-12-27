/*
read_board_file_in_single_codefile_noCompile.cpp
--------------------------------------------------------
Demonstration of out of order function definition
This code does not compile because ParseFile definition comes ahead of ParseLine
And ParseLine uses ParseFile

This is the following error that you will get
kswamin4@krithika-intern-Precision-7710:~/MOOC-code/CPlusPlus_ND_Udacity/Extras-Topics-ksw/headers_OOOfunctions_splittingIntoMutlifiles$ g++ read_board_file_in_single_codefile_noCompile.cpp -o read_board_file_in_single_codefile_noCompile.o
read_board_file_in_single_codefile_noCompile.cpp: In function ‘std::vector<std::vector<Cell> > ParseFile(std::ifstream&)’:
read_board_file_in_single_codefile_noCompile.cpp:26:11: error: ‘ParseLine’ was not declared in this scope
     row = ParseLine(this_line);
           ^~~~~~~~~
read_board_file_in_single_codefile_noCompile.cpp:26:11: note: suggested alternative: ‘ParseFile’
     row = ParseLine(this_line);
           ^~~~~~~~~
           ParseFile


read_board_file_in_single_codefile_Compile1.cpp
--------------------------------------------------------
In this code the code will compile, because the order of the functions are switched
ParseLine is defined first and the ParseFile

read_board_file_in_single_codefile_Compile2.cpp
--------------------------------------------------------
It is not possible to keep tracking the order of functions every single time.
So the right thing to do is
1) first declare the functions (in any order)
2) define the functions(in any order)

*/


#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

/*---------------------------------------All the declarations ---------------------------------------*/

//for enum it will be both the declaration and the definition
//In general an enum is going to be used as a type definition and should always be in the header file
enum class Cell{ kEmpty, kObstacle};

//Declare the functions
vector<vector<Cell>> ParseFile(ifstream& file_obj) ;
vector<Cell> ParseLine(string& this_line) ;
void PrintBoardAsInt(vector<vector<Cell>> board) ;
void PrintBoardAsEmoji(vector<vector<Cell>> board) ;



/*---------------------------------------All the defintions ---------------------------------------*/
vector<vector<Cell>> ParseFile(ifstream& file_obj){
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

vector<Cell> ParseLine(string& this_line){
  stringstream sso(this_line);
  vector<Cell> row;
  int x;
  char c;
  while(sso>>x>>c && c==','){
    row.push_back(Cell(x));
  }
  return row;
}


void PrintBoardAsInt(vector<vector<Cell>> board){
  cout<<"\n Printing Board as Int"<<endl;
  for(vector<Cell> row:board){
    for(Cell cell:row){
       if(cell == Cell::kEmpty)
         cout<<"0 ";
       else
         cout<<"1 ";
    }
    cout<<endl;
  }
}

void PrintBoardAsEmoji(vector<vector<Cell>> board){
  cout<<"\n Printing Board as Emoji"<<endl;
  for(vector<Cell> row:board){
    for(Cell cell:row){
       if(cell == Cell::kEmpty)
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
