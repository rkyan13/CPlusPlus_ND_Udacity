#include<iostream>

using std::cout;
using std::cin;
using std::endl;



//Demonstration of scope . Putting enum inside and outside main (refer enums_Example1 and enums_example2.
//This kind of scope limitation etc. cannot be done with preprocessor directives i.e. # define
//But enums take only integet values , but #define can take float enum outside int main and it worked
//I have put the enum inside int main and it worked


//NOTE: Thateven if you give that values of x anything other than 0 and 1 no error is thrown

int main(){

  enum Coin {
    Head=0,
    Tail=1
  };

  Coin toss_result1, toss_result2;
  int x;

  cout<<"Enter coin toss result1:";
  //NOTE : enum cannot accept cin>>, nor can you use cin.get().So you read an integer and typecast
  cin >>x;
  toss_result1 = Coin(x);
  cout<<"\n Coin toss result1 = "<<toss_result1 <<endl;

  toss_result2 = Head;
  cout<<"\n Coin toss result2 = "<<toss_result2 <<endl;
}
