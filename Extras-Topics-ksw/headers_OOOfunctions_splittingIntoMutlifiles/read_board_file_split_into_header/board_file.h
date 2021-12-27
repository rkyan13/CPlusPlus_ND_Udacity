
#ifndef BOARD_FILE_H
#define BOARD_FILE_H



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


#endif
