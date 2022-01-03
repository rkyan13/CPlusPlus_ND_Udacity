/*
pointer_to_function_example1.cpp
This code demonstrates how to declare and use pointers to math_functions

To compile the code
g++ math_functions/math_functions_ksw.cpp pointer_to_function_example1.cpp -o pointer_to_function_example1.out

To execute the code
./pointer_to_function_example1.out  ``

*/

#include<iostream>
#include "math_functions/math_functions_ksw.h"
using namespace std;

int main(){
  //Declare a pointer to a function
  int (*ptr2func)(int,int);
  int option, x,y, output;

  cout<<"\nDemonstration of pointers to functions in c++";
  option = 1;
  while(option!=0) {
    cout<<"\nEnter 1:Add, 2:Multiply , 0:Exit : ";
    cin >> option;
    switch(option){
      case 1:
        ptr2func = &add;
        break;
      case 2:
        ptr2func = &multiply;
        break;
      case 0:
        cout<<"Program exiting \n";
        continue;
      default:
        cout<<"Invalid Option. Try again\n";
        continue;
    }//eof switch(option)

    cout<<"Enter the 2 integers(separated by space or newline(enter)): ";
    cin>>x>>y;
    output = ptr2func(x,y);
    cout<<"Output = "<<output<<endl;
  }//eof while(option!=0)

}//eof main
