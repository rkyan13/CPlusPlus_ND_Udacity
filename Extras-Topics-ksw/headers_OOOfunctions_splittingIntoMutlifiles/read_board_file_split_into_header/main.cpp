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

read_board_file_split_into_header
--------------------------------------------------------
For larger files, it is not the best practice to have all the functions in 1 single file
You cannot keep compiling the entire file for the smallest changes.
You split into many files and only recompile the files that have been changed

1) Split into multiple files

2) Put the declarations in header files .
i)  Be sure to put file guards in header files

ii) What #includes should the header files include?
 Make the header files sufficient so that they compile by themselves
I had an aha moment for this:  You dont need to include iostream etc.
But you might need to include <vector> , <tuple> etc i.e things that feature in the function declaration

iii) Where are enums included ? .h or .cpp ?
In general an enum is going to be used as a type definition and should always be in the header file

iv) Splitting classes into .h and .cpp files
 Typically in C++ there are classes. So classes have a .h and .cpp files.
 .h file: Has class variable and class method declarations
 .cpp: class method definitoion: this can include initializer lists

v) Splitting non-OOP/ non-C++(maybe just c code into .h and .cpp files
It is not necessary only classes be split this way.
read_board_file_split_into_header/board_file.h,board_file.cpp and main.cpp is an example of
how to split non-oop code into header and .cpp files


How to compile the individual files
-------------------------------------------

You can compile the individual files and see is the header, .cpp and main files are self sufficient this way
COMPILING: METHOD A
i)   g++ -c board_file.h: this creates board_file.h.gch (I suppose this is not necessary )
ii)  g++ -c board_file.cpp: this creates board_file.o
iii) g++ -c main.cpp: this creates main.o\
COMPILING: METHOD B
Alternatively, if you want to compile all the files in one go
i) g++ -c *.cpp (this will create board_file.o and main.o)

LINKING METHOD A
Then you can link all of them together using
i) g++ *.o : this just created a.out which is an executable
ii) you can now run the executable using ./a.out

LINKING METHOD B: Y
ou can specify the name of the executable
i) g++ *.o -o main.out : this just created main.out which is an executable
ii) you can now run the executable using ./main.out

COMPILE & LINK in 1 STEP:
g++ board_file.cpp main.cpp -o main.out
OR
g++ *.cpp -o main.out
you can now run the executable using ./main.out
*/


#include<fstream>
#include<vector>
#include "board_file.h"
using namespace std;

int main(){
  ifstream board_file_obj;
  board_file_obj.open("board1.txt");

  vector<vector<Cell>> board ;
  board = ParseFile(board_file_obj);
  PrintBoardAsInt(board);
  PrintBoardAsEmoji(board);
}
