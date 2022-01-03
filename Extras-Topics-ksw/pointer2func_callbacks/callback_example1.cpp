/*
pointer_to_function_example1.cpp
This code demonstrates how to declare and use pointers to math_functions

To compile the code
g++ math_functions/math_functions_ksw.cpp callback_example1.cpp -o callback_example1.out

To execute the code
./callback_example1.out

*/

#include<iostream>
#include "math_functions/math_functions_ksw.h"
using namespace std;

//Create a user defined data type called callback_t
using callback_t = int (*)(int , int );

int do_math(int x, int y, callback_t do_math_callback){
  return do_math_callback(x,y);
}


int main(){
  //Declare a pointer to a function
  int option, x,y, output;

  cout<<"\nDemonstration of call backs in c++";
  option = 1;
  while(option!=0) {
    cout<<"\nEnter 1:Add, 2:Multiply , 0:Exit : ";
    cin >> option;
    switch(option){
      case 1:
        cout<<"Enter the 2 integers(separated by space or newline(enter)): ";
        cin>>x>>y;
        output = do_math(x,y,add);
        cout<<"Output = "<<output<<endl;
        break;
      case 2:
        cout<<"Enter the 2 integers(separated by space or newline(enter)): ";
        cin>>x>>y;
        output = do_math(x,y,multiply);
        cout<<"Output = "<<output<<endl;
        break;
      case 0:
        cout<<"Program exiting \n";
        continue;
      default:
        cout<<"Invalid Option. Try again\n";
        continue;
    }//end of switch(option)
  }//eof while(option!=0)

}//eof main
