#include <iostream>
#include "graphics.h"
using namespace std;

int main(){
  /*
  cout<<"main: creating shape1"<<endl;
  Shape shape1;
  //----------------------------
  cout<<"\nmain: creating circle1"<<endl;
  Circle circle1;


  cout<<"\nmain: creating triangle1"<<endl;
  Triangle triangle1;
  triangle1.print_details();

  cout<<"\nmain: creating triangle2"<<endl;
  Triangle triangle2("red", 9.0 , 9.1);
  triangle2.print_details();


  cout<<"\nmain: creating square1"<<endl;
  Square square1;
  //----------------------------
  cout<<"\nmain: creating smileyface1"<<endl;
  SmileyFace smileyface1;

  */
  
  cout<<"\nmain: creating girl1"<<endl;
  Girl girl1;
  girl1.print_details();


  cout<<"\nmain: creating girl2"<<endl;
  Girl girl2( "brown",10.0, "happy-laughing",
              "red", 9.0 , 9.1,
               10.2, 10.3, 90.0);
  girl2.print_details();



  /*
  cout<<"\nmain: creating boy1"<<endl;
  Boy boy1;
  */
  //----------------------------
}
