#include <iostream>
using std::cout;
using std::endl;

//NOTE: all 3 methods below are valid ways to use auto
float add_method1(float a, float b){
  float c = a+b;
  return c;
}

float add_method2(auto a, auto b){
  float c = a+b;
  return c;
}

auto add_method3(auto a, auto b){
  auto c = a+b;
  return c;
}


int main(){

  auto x1 = 3;
  auto y1 = 2.5;
  auto c1 = add_method1(x1,y1);
  cout <<"c1= "<<c1<<endl;

  auto x2 = 1;
  auto y2 = 2;
  auto c2 = add_method2(x2,y2);
  cout <<"c2= "<<c2<<endl;

  auto x3 = 8.92;
  auto y3 = 6005.3;
  auto c3 = add_method2(x3,y3);
  cout <<"c3= "<<c3<<endl;

  return 0;
}
