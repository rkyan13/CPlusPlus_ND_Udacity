#include <iostream>
#include <vector>
using namespace std;

int main(){
  auto x = 5;
  auto str = "abc";
  auto v = {1,2,3};

  cout<<"typeid(x).name()   = "<<typeid(x).name()<<" : x   ="<<x<<endl;
  x = x+1;
  cout<<"typeid(x).name()   = "<<typeid(x).name()<<" : x   ="<<x<<endl;

  cout<<"typeid(str).name() = "<<typeid(str).name()<<" : str ="<<str<<endl;
  cout<<"typeid(v).name()   = "<<typeid(v).name()<<" : v.size() ="<<v.size()<<endl;

  /*
  //No idea how to print out the contents of v. The following errors out
  for (int i = 0; i < 2; i++) {
    cout << v.at(i) << " ";
  }
  cout<<endl;
  */

}
