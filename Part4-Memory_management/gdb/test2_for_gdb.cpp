/*
Useful links
*/


#include <iostream>
#include <string>
using namespace std;



void func2(){
  int   func2_int   = 2;    //The hex for this int
  float func2_float1 = 2.0; //The hex for this float
  cout<<"func2_int    is = "<<func2_int    <<endl;
  cout<<"func2_float1 is = "<<func2_float1 <<endl;
  cout<<"func2_float2 is = "<<func2_float2 <<endl;
}

void func1(){
  int   func1_int    = 1;   //The hex for this int     is
  float func1_float1 = 1.0; //The hex for this float  is
  float func1_float2 = 1.1; //The hex for this float  is
  cout<<"func1_int    is = "<<func1_int    <<endl;
  cout<<"func1_float1 is = "<<func1_float1 <<endl;
  cout<<"func1_float2 is = "<<func1_float2 <<endl;
  func2();
}

void funcA(){
  char   funcA_str1[] = "LION";      //the hexadecimal
  string funcA_str2   = "LION";
  printf("funcA_str1 is = %s\n", funcA_str1);
  cout<<"funcA_str2 is = "<<funcA_str2 <<endl;
}

int main(){
  int mainVar1 =         10; //The hexadecimal is 00-00-00-0A
  int mainVar2 =   11259375; //The hexadecimal is 00-AB-CD-EF
  int mainVar3 = 2147483647; //The hexadecimal is 7F-FF-FF-FF (maximum int can store- 4 bytes)

  cout<<"mainVar1 is = "<<mainVar1 <<endl;
  cout<<"mainVar2 is = "<<mainVar2 <<endl;
  cout<<"mainVar3 is = "<<mainVar3 <<endl;
  func1();
  funcA();
  return 0;
}
